#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>

int main()
{
unsigned char buffer[10];
unsigned char buffer1[10];
unsigned char buffer2[20];
int fd;
fd=open("fifo",O_RDONLY);
read(fd,buffer,10);
printf("string1 is %s",buffer);
read(fd,buffer1,10);
printf("string2 is %s",buffer1);
printf("data received from p1\n");
printf("concatenating two strings\n");
strcpy(buffer2,buffer);
strcat(buffer2,buffer1);
printf("%s\n",buffer2);
close(fd);
return 0;
}
