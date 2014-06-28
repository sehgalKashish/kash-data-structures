/**
* First, we'll have the parent make a pipe. Secondly, we'll fork().
* Now, the fork() man page tells us that the child will receive a
* copy of all the parent's file descriptors, and this includes a 
* copy of the pipe's file descriptors.

* the child will be able to send stuff to the write-end of the pipe, and the
* parent will get it off the read-end
**/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
int main(void)
{
    int pfds[2];
    char buf[30];
    pipe(pfds);
    if (!fork())
    {
        printf("3  CHILD: writing to the pipe\n");
        write(pfds[1], "test", 5);
        printf("4 CHILD: exiting\n");
        exit(0);
    }
    else
    {
        printf("1 PARENT: reading from pipe\n");
        read(pfds[0], buf, 5);
        printf("2 PARENT: read \"%s\"\n", buf);
        wait(NULL);
    }
    return 0;
}
/**
* In this case, the parent tried to read from the pipe before the child writes to it. When this happens,
* the parent is said to block, or sleep, until data arrives to be read. It seems that the parent tried to read,
* went to sleep, the child wrote and exited, and the parent woke up and read the data.
**/
