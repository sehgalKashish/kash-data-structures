/**
* Here, I will include a demo program, lockdemo.c, that waits for the user to hit return, then locks
* its own source, waits for another return, then unlocks it. By running this program in two (or more)
* windows, you can see how programs interact while waiting for locks.
* Basically, usage is this: if you run lockdemo with no command line arguments, it tries to grab a
* write lock (F_WRLCK) on its source (lockdemo.c). If you start it with any command line arguments at
* all, it tries to get a read lock (F_RDLCK) on it.
**/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    /* This flock() is a struct.
       Its various members are as followed.
       struct flock fl;
       int fd;
       fl.l_type = F_WRLCK; // F_RDLCK, F_WRLCK, F_UNLCK
    fl.l_whence = SEEK_SET; // SEEK_SET, SEEK_CUR, SEEK_END 
    fl.l_start = 0; // Offset from l_whence 
    fl.l_len = 0; // length, 0 = to EOF 
    fl.l_pid = getpid(); // our PID 
    fd = open("filename", O_WRONLY);
    fcntl(fd, F_SETLKW, &fl); // F_GETLK, F_SETLK, F_SETLKW 

    **/

    /* l_type l_whence l_start l_len l_pid */

    struct flock fl = {F_WRLCK, SEEK_SET, 0, 0, 0 };
    int fd;
    fl.l_pid = getpid();
    if (argc > 1)
        fl.l_type = F_RDLCK;
    if ((fd = open("lockdemo.c", O_RDWR)) == -1) {
        perror("open");
        exit(1);
    }
    printf("Press <RETURN> to try to get lock: ");
    getchar();
    printf("Trying to get lock...");
    if (fcntl(fd, F_SETLKW, &fl) == -1) {
        perror("fcntl");
        exit(1);
    }
    printf("got lock\n");
    printf("Press <RETURN> to release lock: ");
    getchar();
    fl.l_type = F_UNLCK; /* set to unlock same region */
    if (fcntl(fd, F_SETLK, &fl) == -1) {
        perror("fcntl");
        exit(1);
    }
    printf("Unlocked.\n");
    close(fd);
    return 0;
}
/**
* Compile that puppy up and start messing with it in a couple windows. Notice that when one
* lockdemo has a read lock, other instances of the program can get their own read locks with no problem.
* It's only when a write lock is obtained that other processes can't get a lock of any kind.
* Another thing to notice is that you can't get a write lock if there are any read locks on the same
* region of the file. The process waiting to get the write lock will wait until all the read locks are cleared.
* One upshot of this is that you can keep piling on read locks (because a read lock doesn't stop other
* processes from getting read locks) and any processes waiting for a write lock will sit there and starve.
* There isn't a rule anywhere that keeps you from adding more read locks if there is a process waiting for a
* write lock. You must be careful.
**/
