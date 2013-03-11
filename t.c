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
 

int main(int argc, char *argv[])
{
    int idx = 0;
 
    if(-1 == app_singleton("/tmp/zz.pid")){
	printf("%s already running\n", argv[0]);
        return -1;
    }
 
    while(1){
        idx++;
        printf("%d\n", idx);
 
        sleep(2);
    }
 
    return 0;
}
