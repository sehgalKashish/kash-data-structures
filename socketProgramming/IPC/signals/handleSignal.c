/**
When you're handling a signal, you might want to block other
signals from being delivered, and you can do this by adding them to the sa_mask It's a “set”, which
means you can do normal set operations to manipulate them: sigemptyset(), sigfillset(),
sigaddset(), sigdelset(), and sigismember(). In this example, we'll just clear the set and not
block any other signals.
Examples always help! Here's one that handled SIGINT, which can be delivered by hitting ^C,
called sigint.c
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
void sigint_handler(int sig)
{
    write(0, "Ahhh! SIGINT!\n", 14);
    /**
    POSIX says that write() is async-safe (so is safe to call from within the handler), while printf() is not.
    The library functions and system calls that are async-safe and can be called from within your signal
    handlers are (breath):
    **/
}
int main(void)
{
    void sigint_handler(int sig); /* prototype */
    char s[200];
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sa.sa_flags = SA_RESTART;// or 0
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
    printf("Enter a string:\n");
    if (fgets(s, sizeof s, stdin) == NULL)
        perror("fgets");
    else
        printf("You entered: %s\n", s);
    return 0;
}
