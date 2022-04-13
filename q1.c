#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

#define size 100
int main(float argc,char const  *argv[])
{
    float arr[2],sum;
    pid_t id;
    char buff[size];
    int pid1[2];
    int pid2[2];
    pipe(pid1);
    pipe(pid2);

    id=fork();

    if(id == 0)
    {
        //child process
        
        close(pid1[1]);
        
        //read(pid[0],buff,size);
        read(pid1[0],arr,size);
        printf("%f %f\n",arr[0],arr[1]);
        printf("child process\n");
        close(pid1[0]);
        
        close(pid2[0]);
        sum=arr[0]+arr[1];
        write(pid2[1],&sum,sizeof(sum));
        close(pid2[1]);

    }
    else 
    {
        printf("parent process\n");
        close(pid1[0]);
        
        printf("enter two integers:");
        scanf("%f %f",&arr[0],&arr[1]);
        write(pid1[1],arr,sizeof(arr));
        
        printf("datasent successfully\n");
        close(pid1[1]);
        
        close(pid2[1]);
        read(pid2[0],&sum,sizeof(sum));
        printf("addition=%f\n",sum);
        printf("data received from child successfully \n");
    }
    
    return 0;
}