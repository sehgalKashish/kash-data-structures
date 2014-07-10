/** When you execute the piece of code below, you should get "hello world" imidiatly on your screen without the 2 seconds delay
 * in function1(). After this you still have to wait 1 second (sleep(1);) for the program to terminate itself and all threads
 * it created. In the code above we've archieved this by including the pthread libraby (<pthread.h>) and using the
 * pthread_create() fuction to create two extra threads for function1() and function2(). These threads run the instructions in
 * function1() and function2() separately from each other and main(). There is no certainty in what function will be executed
 * first. Your OS will decide when resources are available for your threads and execute them on whatever CPU is least occupied.
 * So do not be surprised when you see "world hello" instead of "hello world
 **/

#include <pthread.h>
#include <unistd.h>
#include <iostream>

using namespace std ;

void  * function1(void * argument);
void  * function2(void * argument);

int main( void )
{
    pthread_t t1, t2 ; // declare 2 threads.
    pthread_create( &t1, NULL, function1,NULL); // create a thread running function1
    pthread_create( &t2, NULL, function2,NULL); // create a thread running function2

    /** 
    * Because all created threads are terminated when main() finishes, we have
    * to give the threads some time to finish. Unfortunately for function1, main()
    * will give only 1 second, but function1 needs at least 2 seconds. So function1 will
    * probably be terminated before it can finish. This is a BAD way to manage threads.
    **/
    sleep(1);

    return 0;
}

void *function1(void * argument)
{
    cout << " hello " << endl ;
    sleep(2); // fall alseep here for 2 seconds...
    return 0;
}

void *function2(void * argument)
{
    cout << " world "  << endl ;
    sleep(2);
    return 0;
}


/** Multithreading, like in the example code above, does not make much sense. Nevertheless imagine a program has to wait for
 * some I/O calls without holding up the entire program, do a big calculation on a multi-core and speed it up by deviding it
 * over the available cores, or just to keep your program responsive while it's waiting for user input. 
**/
