#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
void sighandler(int signo)
{
printf("caught the signal %d\n",signo);
wait();
}

int main()
{
int pid;
printf("hello from the main \n");
pid=fork();
if(pid==0)
{
printf("hello from child\n");
sleep(10);
}
else
{
printf("hello from the parent process\n");
signal(SIGCHLD,sighandler);
while(1)
{
printf(" i am from parent\n");
sleep(1);
}
}
}

