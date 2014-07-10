#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <pthread.h>
#include <crypt.h>
#include <ctime>
#include <cstring>


using namespace std;

void * wordlist_crack(void * arg);
void * bruteforce_integer(void * arg);
int start_threads() ;

// globals

pthread_mutex_t pass_found = PTHREAD_MUTEX_INITIALIZER;
vector< string > word_list ;
vector<string> password_list ;

string passfilename = "password.txt";   // the default password file
string wordfilename = "wordlist.txt";   // the default wordlist file

struct crypt_data ;

int     p_threads=5;                    // number of threads to use
int     p_menu = 0 ;                    // default menu option
int     wl_devided;                     // wordlistsize / threads
int     cracked = 0 ;                   // number of passwords cracked
int     p_maxint = 999999 ;             // maximum number to go


int main( int argc, char** argv )
{

    int arg_count=1;
    // decode arguments
    while (arg_count < argc)
    {
        string sw = argv[arg_count];

        if (sw=="-m")
        {

            arg_count++;

            std::stringstream ss(argv[arg_count]); 
            ss >> p_menu;


        }


        else if (sw=="-t")
        {
            arg_count++;
            std::stringstream ss(argv[arg_count]); 
            ss >> p_threads;
        }

        else if (sw=="-w")
        {
            arg_count++;
            wordfilename = argv[arg_count];
        }

        else if (sw=="-p")
        {
            arg_count++;
            passfilename = argv[arg_count];
        }


        else

            arg_count++;
    }

    cout << "*************************************************\n" ;

// read passwords (lines) from "password.txt" into a vector.

    ifstream passfile(passfilename.c_str()) ;
    string password ;
    while( getline( passfile, password ) ) password_list.push_back(password) ;

    cout << password_list.size() << " password(s) loaded from " << passfilename << endl;

// read words (lines) from wordlist file into a vector
    ifstream file(wordfilename.c_str()) ;
    string word ;
    while( getline( file, word ) ) word_list.push_back(word) ;


    cout << word_list.size() << " words loaded from " << wordfilename << endl ;


    cout << "threads : " << p_threads << endl;


    cout << "*************************************************\n" ;

    if (p_menu == 0)
    {
        cout << "1. Wordlist crack ["  << wordfilename << "]"  << endl ;
        cout << "* 2. Wordlist + 0-9"  << endl ;
        cout << "* 3. Wordlist + a-z"  << endl ;
        cout << "* 4. Wordlist + same wordlist (combined words)"  << endl ;
        cout << "* 5. Wordlist + other wordlist (combined words)"  << endl ;
        cout << "6. Brutforce 0-9"  << endl ;
        cout << "* 7. Brutefoce a-z"  << endl ;
        cout << "* 8. Brutefoce crack a-z + 0-9"  << endl ;
        cout << "9. Create password"  << endl ;

        cout << "options with an * are not yet supported. I just added" << endl
             << "them because they would be good options to add." << endl << endl ;


        string choice_temp;

        cout << "your choice :" ;
        getline (cin,choice_temp);


        stringstream ss(choice_temp); 
        ss >>p_menu;


    }


    start_threads() ;

    return 0;
}




int start_threads()
{

    int mod_left = 0 ;
    void *(*function_pointer) (void*) ;


    switch ( p_menu )
    {
    case 1:
        {

        // calculate how much each thread should handle with wordlist.
        wl_devided = word_list.size() / p_threads ;
        mod_left = (word_list.size() %  p_threads);
        cout << "every thread should handle " << wl_devided << " words from the wordlist..." << endl;
        cout << "for the last thread there is a modulo left of " << mod_left << endl;
        function_pointer  = &wordlist_crack;
        break;
        }

    case 6:
        {

        // calculate how much each thread should handle with bruteforce integers.
        wl_devided = p_maxint / p_threads ;
        mod_left = (p_maxint %  p_threads);
        cout << "every thread should handle " << wl_devided << " numbers" << endl;
        cout << "for the last thread there is a modulo left of " << mod_left << endl;
        function_pointer  = &bruteforce_integer;
        break;
        }

    case 9:
        {


        string password;
        string salt;
        string encryption;

        cout << "password: ";
        getline (cin,password);
        cout << "salt: ";
        getline (cin,salt);
        cout << "encryption method(leave blank for DES,'1'= MD5,'2' = Blowfish,'3'=NT-Hash,'5'=SHA-256,'6'=SHA-512) :";
        getline (cin,encryption);
        salt = "$"+encryption + "$" + salt;


        password = crypt(password.c_str(), salt.c_str());


        cout << "Encrypted password : " << password << endl;
        return 0;
        break;
        }

    default:
        {
        cout << "invalid option" << endl;
        return 0;
        break;
        }
    }


    pthread_t thread[p_threads];



    int temp_arg[p_threads];

    int start_time = time(0);

    cout << "Starting all threads..." << endl;
    for(int current_t = 0; current_t < p_threads; current_t++)
    {
        temp_arg[current_t]   = current_t * wl_devided;

        // give the last thread the left overs...
        if (current_t==p_threads)
            wl_devided = wl_devided + mod_left;

        int start_time = time(0);
        int result = pthread_create(&thread[current_t], NULL, function_pointer, static_cast<void*>(&temp_arg[current_t]));
        if (result !=0)
        {
            cout << "Error creating thread " << current_t << ". Return code:" << result <<  endl;
        }
    }

    for(int current_t = 0; current_t < p_threads; current_t++)
    {
        pthread_join(thread[current_t], NULL);
    }

    cout << "*************************************************\n" ;
    cout << "completed : " << cracked << " password(s) cracked, "<<password_list.size() <<  " password(s) uncracked " << endl;
    cout << "time :" << time(0) - start_time  << " seconds." << endl;
}



void * wordlist_crack(void * arg)
{


    crypt_data  data ;
    memset(&data, 0, sizeof data);
    int checking_range =  *(reinterpret_cast<int*>(arg));
    // cout << "the checking range is " << checking_range << endl ;
    // cout << "it will run to " << checking_range + wl_devided << endl ;


    for( int cur_word = checking_range ; cur_word < (checking_range + wl_devided)  ; ++cur_word ) // loop through the wordlist
    {
        for( int cur_pass = 0 ; cur_pass < password_list.size()  ; ++cur_pass ) // and loop through every password at each word
        {
            // cout << crypt(word_list[cur_word].c_str(), password_list[cur_pass].c_str()) << endl;
            // cout << "curpas: " << password_list[cur_pass] << endl;


            if( crypt_r(word_list[cur_word].c_str(), password_list[cur_pass].c_str(),&data) == password_list[cur_pass])

            {
                // locking in case an other password was found at the same time
                // preventing messing up the  "cout" display and changing password_list (password_list.erase)
                pthread_mutex_lock( &pass_found );

                cout << "=================================================\n" ;
                cout <<  password_list[cur_pass]  <<" is in the wordlist [" <<  word_list[cur_word] << "]" << endl;
                cracked++;
                // if a password has been found, erase it from the list, so this loop get's
                // shorter(and also other threads' loops )
                password_list.erase (password_list.begin()+cur_pass);
                cout << cracked << " password(s) cracked, "<<password_list.size() <<  " password(s) remaining " << endl;
                cout << "=================================================\n" ;
                if (password_list.size() ==0) return 0;
                pthread_mutex_unlock( &pass_found );
                // But do not "break" this loop, as other passwords using
                // different salts may be the same
            }
        }
    }
}

void * bruteforce_integer(void * arg)
{

    //cout << "trying bruteforce crack with integers." ;
    crypt_data  data ;
    memset(&data, 0, sizeof data);
    string s;
    stringstream ss;

    int checking_range =  *(reinterpret_cast<int*>(arg));
    // cout << "the checking range is " << checking_range << endl ;
    // cout << "it will run to " << checking_range + wl_devided << endl ;


    for( int cur_int = checking_range  ; cur_int < (checking_range + wl_devided)  ; ++cur_int ) // loop through the wordlist
    {

        ss.str(std::string());
        ss << cur_int;
        s = ss.str();



        for( int cur_pass = 0 ; cur_pass < password_list.size()  ; ++cur_pass ) // and loop through every password at each word
        {

            if( crypt_r(s.c_str(), password_list[cur_pass].c_str(),&data) == password_list[cur_pass])


            {
                pthread_mutex_lock( &pass_found );
                cout << "=================================================\n" ;
                cout <<  password_list[cur_pass]  <<" is in the wordlist [" <<  cur_int << "]" << endl;
                cracked++;
                // if a password has been found, erase it from the list, so this loop get's
                // shorter(and alsoother threads' loops )
                password_list.erase (password_list.begin()+cur_pass);
                cout << cracked << " password(s) cracked, "<<password_list.size() <<  " password(s) remaining " << endl;
                cout << "=================================================\n" ;
                if (password_list.size() ==0) return 0;
                pthread_mutex_unlock( &pass_found );

                // But do not "break" this loop, as other passwords using
                // different salts may be the same
            }


        }

    }
}
