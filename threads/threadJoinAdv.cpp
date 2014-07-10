/** If you are creating threads in a loop, like in the example below,
* do not forget to create new variables for the arguments
* you pass. It's a bad idea to pass a reference to a variable 
* that can change before the thread has been created.
**/
extern "C"
{
    #include <pthread.h>
    #include <unistd.h>
}
#include <iostream>

using namespace std;

const int NUMBER_OF_THREADS = 5;

void * thread_talk(void * thread_nr)

{
    int a = *(static_cast<int*>(thread_nr));
    sleep(a+1);
    //sleep(1); //In this case, all threads sleep for same time, thus finish at same time.
    cout << "Thread " <<  a <<" has finished"  << endl;
    
    pthread_exit(NULL);
    return 0;
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
            cout << "Error creating thread " << current_t << ". Return code:" << result <<endl;
        }
    }
    for(int current_t = 0; current_t < NUMBER_OF_THREADS; current_t++)
    {
        pthread_join(thread[current_t], NULL);
    }
    cout << "All threads completed." ;
    
    return 0;
}

