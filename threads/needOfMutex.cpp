

extern "C"
{  
    #include <pthread.h>
    #include <unistd.h>
}
#include <iostream>

using namespace std;
const int NUMBER_OF_THREADS = 5;

int some_value = 10 ;

// add a global ,mutex variable
pthread_mutex_t mutex_for_some_value = PTHREAD_MUTEX_INITIALIZER;

void * thread_talk(void * thread_nr)
{
    int a = *(static_cast<int*>(thread_nr));
    sleep(a+1);
    //sleep(1); //In this case, all threads sleep for same time, thus finish at same time.
    cout << "Thread " <<  a <<" has finished"  << endl;
    for (int x = 1 ; x< 500 ; x++)
    {
        // lock some_value here :
        pthread_mutex_lock( &mutex_for_some_value );

        some_value = some_value * 10 ;
        some_value++;
        some_value--;
        some_value = some_value / 10 ;

        // and unlock it for the next thread :
        pthread_mutex_unlock( &mutex_for_some_value );
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread[NUMBER_OF_THREADS];
    
    cout << "Starting all threads..." << endl;
    
    int temp_arg[NUMBER_OF_THREADS] ;
    
    for(int current_t = 0; current_t < NUMBER_OF_THREADS; current_t++)
    {   
        temp_arg[current_t] = current_t;
        int result = pthread_create(&thread[current_t], NULL, thread_talk,
                static_cast<void*>(&temp_arg[current_t]))  ;
        
        if (result !=0)
        {   
            cout << "Error creating thread " <<current_t << ". Return code:" << result<<endl;
        }   
    }   
    for(int current_t = 0; current_t < NUMBER_OF_THREADS; current_t++)
    {   
        pthread_join(thread[current_t], NULL);
    }
    cout << "The value of some_value in end is : \n" << some_value;
    cout << "All threads completed." ;
    
    return 0;
}
/**
* Now we can be sure no, so called, "race condition" occurs because only one thread has access to the variable within the
* 'lock' block. Note that the 'cout' object we've used in our examples actually isn't actually meant to be used with threads. I
* haven't run into trouble using cout and threads yet, but if you want to be absolutely sure no problems will arise, you should
* use mutexes when working with cout.
**/


