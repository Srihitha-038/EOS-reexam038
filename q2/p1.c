#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<errno.h>


int main()
{

int fd;
unsigned char buffer[10]={"hello"};
unsigned char buffer1[10]={"world"};
fd=open("fifo",O_WRONLY);
write(fd,buffer,sizeof(buffer));
write(fd,buffer1,sizeof(buffer1));
close(fd);
return 0;
}