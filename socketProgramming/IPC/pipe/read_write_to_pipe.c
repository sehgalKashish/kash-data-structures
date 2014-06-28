/**
* pipe() takes an array of two ints as an argument. Assuming no errors, it connects
* two file descriptors and returns them in the array. The first element of the array is the reading-end of the
* pipe, the second is the writing end.
**/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
int main(void)
{
    int pfds[2];
    char buf[30];
    if (pipe(pfds) == -1) {
        perror("pipe");
        exit(1);
    }
    printf("writing to file descriptor #%d\n", pfds[1]);
    write(pfds[1], "Kashihsh sehjgalt", 5);
    printf("reading from file descriptor #%d\n", pfds[0]);
    read(pfds[0], buf, 5);
    printf("read \"%s\"\n", buf);
    return 0;
}
