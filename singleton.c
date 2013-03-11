//
//create by zhangz @2013-03-11
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
 
int app_singleton(char *pid_file)
{
    int fd = -1;
    int m = 0;
    int n = 0;
    char pid[64] = {0};
    struct flock lock;
 
    /* open file */
    fd = open(pid_file, O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
    if(-1 == fd){
        //perror("app_singleton:open");
        return -1;
    }
 
    /* lock file */
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    if (fcntl(fd, F_SETLK, &lock) < 0){
        close(fd);
        //perror("app_singleton:fcntl");
        return -1;
    }
 
    /* write PID */
    m = sprintf(pid, "%u", (unsigned int)getpid());
    n = write(fd, pid, m);
    if(n != m){
        //perror("app_singleton:write");
        return -1;
    }
 
    /* Note:
     * Don't close the fd when process is running 
     */    
 
    return fd;
}
 
/*
int main(int argc, char *argv[])
{
    int idx = 0;
 
    if(-1 == app_singleton("/tmp/zz.pid")){
        return -1;
    }
 
    while(1){
        idx++;
        printf("%d\n", idx);
 
        sleep(2);
    }
 
    return 0;
}
*/
