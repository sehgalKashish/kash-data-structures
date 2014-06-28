/**
* The challenge: implement “ls | wc -l” in C.

* This requires usage of a couple more functions you may never have
* heard of: exec() and dup().The exec() family of functions replaces
* the currently running process with whichever one is passed to exec().
* This is the function that we will use to run ls and wc -l. dup()
* takes an open file descriptor and makes a clone (a duplicate) of it.
* This is how we will connect the standard output of the ls to the standard
* input of wc. See, stdout of ls flows into the pipe, and the stdin of 
* wc flows in from the pipe. The pipe fits right there in the middle!
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
    int pfds[2];
    pipe(pfds);
    if (!fork())
    {
        close(1); /* close normal stdout */
        dup(pfds[1]); /* make stdout same as pfds[1] */
        close(pfds[0]); /* we don't need this */
        execlp("ls", "ls", NULL);
    }
    else
    {
        close(0); /* close normal stdin */
        dup(pfds[0]); /* make stdin same as pfds[0] */
        close(pfds[1]); /* we don't need this */
        execlp("wc", "wc", "-l", NULL);
    }
    return 0;
}
