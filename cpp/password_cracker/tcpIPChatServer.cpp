// ********************************************************************************
// ********  C++ Multithreaded chess/chat server example                     ******
// ********                                                                  ******
// ********  More information: http://www.codebase.eu/                       ******
// ********                                                                  ******
// ********  Compiling : g++ server.cpp -o server -pthread                   ******
// ********************************************************************************

//TODO



#include <iostream>
#include <cstring> 	// used for memset.
#include <arpa/inet.h> 	// for inet_ntop function
#include <netdb.h>
#include <sys/socket.h>
#include <pthread.h>
#include <vector>
#include <list>
#include <iterator>
#include <sstream>

#include <errno.h>

using namespace std;

vector<vector<string> > chessboard;     // We use a 2d vector for the chessboard

list <string> killed;                   // We use a linked list to store beaten pieces.
list <string>::iterator cur_killed;     // And an iterator for working with them

//chess functions
void newgame() ;
void printchessboard(int clientnr);
bool isblack(int x , int y) ;
bool movepiece(char * move) ;
void do_command(char * command, int client) ;
void print_all();

//server functions
int server_start_listen() ;
int server_establish_connection(int server_fd);
int server_send(int fd, string data);
void *tcp_server_read(void *arg) ;
void mainloop(int server_fd) ;


// colors (Your terminal's must support color codes for these to work)
const string clr_text ("\033[22;30m");
const string clr_abc ("\033[01;32m");
const string clr_black ("\033[22;30m");
const string clr_white ("\033[01;30m");
const string clr_black_square("\033[01;34m") ;
const string clr_white_square("\033[01;36m") ;


//server constants
const  char * PORT = "12345" ; // port numbers 1-1024 are probably reserved by your OS
const int MAXLEN = 1024 ;   // Max lenhgt of a message.
const int MAXFD = 7 ;       // Maximum file descriptors to use. Equals maximum clients.
const int BACKLOG = 5 ;     // Number of connections that can wait in que before they be accept()ted

// This needs to be declared volatile because it can be altered by an other thread. Meaning the compiler cannot
// optimise the code, because it's declared that not only the program can change this variable, but also external
// programs. In this case, a thread.
volatile fd_set the_state;

pthread_mutex_t mutex_state = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t boardmutex = PTHREAD_MUTEX_INITIALIZER; // mutex locker for the chessboard vector.

int main()
{

    // create a 8*8 2d field.
    chessboard.resize(8);
    for (int i = 0; i < 8; ++i)
        chessboard[i].resize(8);

    newgame(); // fill the board with pieces

    cout << "Server started."  << endl ; // don not forgfet endl, or it won't display.

    // start the main and make the server listen on port 12345
    // server_start_listen(12345) will return the server's fd.

    int server_fd = server_start_listen() ;
    if (server_fd == -1)
    {
        cout << "An error occured. Closing program." ;
        return 1 ;
    }

    mainloop(server_fd);

    return 0;
}

int server_start_listen()
{

struct addrinfo hostinfo, *res;

int sock_fd;

int server_fd; // the fd the server listens on
int ret;
int yes = 1;

// first, load up address structs with getaddrinfo():

memset(&hostinfo, 0, sizeof(hostinfo));

hostinfo.ai_family = AF_UNSPEC;  // use IPv4 or IPv6, whichever
hostinfo.ai_socktype = SOCK_STREAM;
hostinfo.ai_flags = AI_PASSIVE;     // fill in my IP for me

getaddrinfo(NULL, PORT, &hostinfo, &res);


    server_fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    //if(server_fd < 0) throw some error;

    //prevent "Error Address already in use"
    ret = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
    // if(ret < 0) throw some error;

    ret = bind(server_fd, res->ai_addr, res->ai_addrlen);

    if(ret != 0)
    {
        cout << "error :" << strerror(errno) << endl;
        return -1 ;
    }

    ret = listen(server_fd, BACKLOG);
    //if(ret < 0) throw some error;



return server_fd;

}

int server_establish_connection(int server_fd)
// This function will establish a connection between the server and the
// client. It will be executed for every new client that connects to the server.
// This functions returns the socket filedescriptor for reading the clients data
// or an error if it failed.
{
    char ipstr[INET6_ADDRSTRLEN];
    int port;


    int new_sd;
    struct sockaddr_storage remote_info ;
    socklen_t addr_size;

    addr_size = sizeof(addr_size);
    new_sd = accept(server_fd, (struct sockaddr *) &remote_info, &addr_size);
    //if (fd < 0) throw some error here;

    getpeername(new_sd, (struct sockaddr*)&remote_info, &addr_size);

   // deal with both IPv4 and IPv6:
if (remote_info.ss_family == AF_INET) {
    struct sockaddr_in *s = (struct sockaddr_in *)&remote_info;
    port = ntohs(s->sin_port);
    inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof ipstr);
} else { // AF_INET6
    struct sockaddr_in6 *s = (struct sockaddr_in6 *)&remote_info;
    port = ntohs(s->sin6_port);
    inet_ntop(AF_INET6, &s->sin6_addr, ipstr, sizeof ipstr);
}

std::cout << "Connection accepted from "  << ipstr <<  " using port " << port << endl;

    return new_sd;

}

int server_send(int fd, string data)
// This function will send data to the clients fd.
// data contains the message to be send

{
    int ret;

    ret = send(fd, data.c_str(), strlen(data.c_str()),0);
    //if(ret != strlen(data.c_str()) throw some error;
    return 0;
}
void *tcp_server_read(void *arg)
/// This function runs in a thread for every client, and reads incomming data.
/// It also writes the incomming data to all other clients.

{
    int rfd;

    char buf[MAXLEN];
    int buflen;
    int wfd;

    rfd = (int)arg;
    for(;;)
    {
        //read incomming message.
        buflen = read(rfd, buf, sizeof(buf));
        if (buflen <= 0)
        {
            cout << "client disconnected. Clearing fd. " << rfd << endl ;
            pthread_mutex_lock(&mutex_state);
            FD_CLR(rfd, &the_state);      // free fd's from  clients
            pthread_mutex_unlock(&mutex_state);
            close(rfd);
            pthread_exit(NULL);
        }

        // send the data to the other connected clients
        pthread_mutex_lock(&mutex_state);

        for (wfd = 3; wfd < MAXFD; ++wfd)
        {
            if (FD_ISSET(wfd, &the_state) && (rfd != wfd))
            {
                  // add the users FD to the message to give it an unique ID.
                    string userfd;
                    stringstream out;
                    out << wfd;
                    userfd = out.str();
                    userfd = userfd + ": ";

                server_send(wfd, userfd);
                server_send(wfd, buf);
            }



        }

        pthread_mutex_unlock(&mutex_state);

        do_command (buf,rfd) ;  

    }
    return NULL;
}

void mainloop(int server_fd)

// This loop will wait for a client to connect. When the client connects, it creates a
// new thread for the client and starts waiting again for a new client.
{

    string welcome_msg =("Welcome to this telnet chess server. Valid commands are:\n'1' to show the board or '9' to reset the board.\nTo make a move use the board coordinates to change posistion of a piece.\nFor example 'a2a4'\n");

    pthread_t threads[MAXFD]; //create 10 handles for threads.

    FD_ZERO(&the_state); // FD_ZERO clears all the filedescriptors in the file descriptor set fds.

    while(1) // start looping here
    {
        int rfd;
        void *arg; 

        // if a client is trying to connect, establish the connection and create a fd for the client.
        rfd = server_establish_connection(server_fd);

        if (rfd >= 0)
        {
            cout << "Client connected. Using file desciptor " << rfd << endl;
            if (rfd > MAXFD)
            {
                cout << "To many clients trying to connect." << endl;
                close(rfd);
                continue;
            }

            pthread_mutex_lock(&mutex_state);  // Make sure no 2 threads can create a fd simultanious.

            FD_SET(rfd, &the_state);  // Add a file descriptor to the FD-set.

            pthread_mutex_unlock(&mutex_state); // End the mutex lock

            arg = (void *) rfd;

            server_send(rfd, welcome_msg); // send a welcome message/instructions.

            // now create a thread for this client to intercept all incomming data from it.
            pthread_create(&threads[rfd], NULL, tcp_server_read, arg);
        }
    }
}
void printchessboard(int clientnr)

/// This function sends the chessboard to "clientnr's" telnet client.

{
    char char_y ;

    string piece ;

    string abc1 =clr_abc + "  a  b  c  d  e  f  g  h\n" ;
    server_send(clientnr, "\n" + abc1);

    for (int y=7 ; y>-1 ; y--)
    {
        char_y = y+ 49;         // Converting int to char...
        string char_y_str("");
        char_y_str += char_y ;  // to string.
        server_send(clientnr, char_y_str);

        for (int x=0 ; x<8 ; x++)
        {

            if (chessboard[x][y] == "X") // X represents an empty space.
            {
                if (isblack(x+1,y+1) )
                {
                    chessboard[x][y] = clr_black_square + "â–©" ; // unicode char for a black square
                }
                else
                    chessboard[x][y] = clr_white_square + "â–¢" ; // unicode char for a white square
            }

            server_send(clientnr, " " + chessboard[x][y] + " ");

        }


        server_send(clientnr,clr_abc+ char_y_str+ "\n" );



    }



    server_send(clientnr, abc1 + "\n\n");

    string temp("Dead pieces :") ;
    for (cur_killed = killed.begin(); cur_killed != killed.end(); ++cur_killed)
        temp +=   *cur_killed ;

    server_send(clientnr, temp + clr_text + "\n");



}


bool isblack(int x, int y) // This function determines if the square color is black or white.
{
    bool black = false;
    if (((x & 1) && (y & 1)) || (!(x & 1) && !(y & 1))) black= true  ;
    return black;
}

bool movepiece(char * move)  // Function that executes moves
{

    bool accept  = true ;  // function returns TRUE  if a move is accepted.

    int a,b,c,d ;

    a = move[0] -97;
    b = move[1] -49 ;
    c = move[2] -97;
    d = move[3] -49;



    // If there is no piece on chessboard [a][b] cancel the move.
    if (chessboard [a][b] =="\033[01;34mâ–©" || chessboard [a][b] =="\033[01;36mâ–¢")
    {
        accept = false ;
    }
    else
    {

        // now actually make the move.
        pthread_mutex_lock(&boardmutex);  // lock here, to prevent a race conditions.

        if (chessboard[c][d] != "X" && chessboard[c][d] != clr_black_square+"â–©"  && chessboard[c][d] != clr_white_square +"â–¢") killed.insert(killed.begin() ,chessboard[c][d] ) ;
        chessboard[c][d] = chessboard [a][b] ;
        chessboard[a][b] = "X" ;
        pthread_mutex_unlock(&boardmutex); // unlock
    }

    return accept;

}

void  do_command(char * command, int client) // function that will handle commands
{

    if (command[0]== '1')printchessboard(client) ;  // Show the chessboard.

    if (command[0]== '9')newgame() ;                // Reset the chessboard.

    // Checking if 'command' is a valid command for making a move.
    if (command[0] >= 'a' && command[0] <= 'h' && command[1] >= '1' && command[1] <= '8' && command[2] >= 'a' && command[2] <= 'h' && command[3] >= '1' && command[3] <= '8')
    {
        if(movepiece(command)) ; // and if it is, try to move the piece and print the new chessboard to all connected clients.
        {
            //print chessboard to all
            print_all() ;

        }

        server_send(client,  "\nYour move:");
        server_send(client, command);
        server_send(client,  "\n");

    }

}


void newgame()  // Function to set the chessboard to it's begin status.
{
    pthread_mutex_lock(&boardmutex); // lock mutex

    //first clear the board.
    for (int y=7 ; y>-1 ; y--)
    {
        for (int x=0 ; x<8 ; x++)
        {
            chessboard[x][y] = "X" ; // With 'X' presenting an empty space.
        }
    }

    //then write the pieces to it.

    chessboard[7][7] = clr_black + "â™œ";
    chessboard[6][7] = clr_black + "â™ž";
    chessboard[5][7] = clr_black + "â™";
    chessboard[4][7] = clr_black + "â™š";
    chessboard[3][7] = clr_black + "â™›";
    chessboard[2][7] = clr_black + "â™";
    chessboard[1][7] = clr_black + "â™ž";
    chessboard[0][7] = clr_black + "â™œ";
    for (int x=0; x<8 ; x++)
        chessboard[x][6] = clr_black + "â™Ÿ";


    chessboard[7][0] = clr_white +"â™–";
    chessboard[6][0] = clr_white +"â™˜";
    chessboard[5][0] = clr_white +"â™—";
    chessboard[4][0] = clr_white +"â™”";
    chessboard[3][0] = clr_white +"â™•";
    chessboard[2][0] = clr_white +"â™—";
    chessboard[1][0] = clr_white +"â™˜";
    chessboard[0][0] = clr_white +"â™–";
    for (int x=0; x<8 ; x++)
        chessboard[x][1] = clr_white +"â™™";


    pthread_mutex_unlock(&boardmutex); // unlock mutex

}


void   print_all()
// Printing the chessboard to all connected clients.
{

    for (int wdf = 3; wdf < MAXFD; ++wdf)
    {
        if (FD_ISSET(wdf, &the_state))
        {
            printchessboard(wdf) ;
        }

    }
}


