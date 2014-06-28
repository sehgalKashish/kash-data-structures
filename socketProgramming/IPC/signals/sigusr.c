/**
*Here's an example that handles SIGUSR1 by setting a global flag,
*which is then examined in the main loop to see if the handler was called.
**/
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

volatile sig_atomic_t got_usr1;

void sigusr1_handler(int sig)
{
    got_usr1 = 1;
}
int main(void)
{
    struct sigaction sa;
    got_usr1 = 0;
    sa.sa_handler = sigusr1_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
    while (!got_usr1) {
        printf("PID %d: working hard...\n", getpid());
        sleep(1);
    }
    printf("Done in by SIGUSR1!\n");

    return 0;
}
/**
* Fire it it up in one window, and then use the kill -USR1 in another window to kill it. The sigusr
* program conveniently prints out its process ID so you can pass it to.
* Then in the other window, send it the signal SIGUSR1:
* "$ kill -USR1 5023"
* And the response should be immediate even if sleep() has just been called—sleep() gets
* interrupted by signals.
**/
