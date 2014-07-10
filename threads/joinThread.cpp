/** Joining threads.....
* Joining threads is a method of synchronizing treads. 
* Thew pthread_join() halts execution of your code until the specified
* thread has been terminated. The pthread_join() call : 

* "int pthread_join(pthread_t th, void **thread_return); "

* Parameters : 

* th : The unique identifier for the thread (as specified by pthread_t unique_identifier). 
* thread_return : A pointer to the value the thread returned. (as specified by pthread_exit(return_value)). 
**/
extern "C"
{
    #include <pthread.h>
}

#include <iostream>

using namespace std ;

void* function1(void* arg);

int main( void )
{
    pthread_t  t1,t2 ;

    string msg1 ("helloji")  ;
    string msg2 ("world.....")  ;

    int create1 = pthread_create( &t1, NULL, function1,reinterpret_cast<void*>(&msg1));
    if (create1 != 0)
        cout << "error" ;

    int create2 = pthread_create( &t2, NULL, function1,reinterpret_cast<void*>(&msg2));
    if (create2 != 0)
        cout << "error" ;

    pthread_join(t1,NULL) ;
    pthread_join(t2,NULL) ;
    
    return 0;
}
// Here t1 and t2 are 2 threads, accessing same function
void* function1(void* arg)
{
    cout << *(reinterpret_cast<string*>(arg)) << endl ;
    
    return 0;
}

/**
* In the above piece of code we also gave pthread_create() an argument for the strart routine, therefore reducing the need for
* having 2 functions doing the same job. Because pthread_create() only accepts one argument for the thread function, we have to
* pass a pointer to a struct if we want to pass multiple arguments. IMPORTANT In this case it would not be wise to use
* pthread_exit. The pthread_exit function terminates main() and waits for the two threads to finish. This means that the memory
* containing the strings msg1 and msg2 is free to be used by the two threads, and can (and they will) therefore overwrite the
* values msg1 and msg2. The pthread_join function differs. It keeps main() alive and closes it only when the two threads are
* finished.
**/
