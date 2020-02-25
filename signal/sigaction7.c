#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
/*void sighandler(int signo)
{
printf("caught the signal %d\n",signo);
wait();
}*/

int main()
{
int pid;
struct sigaction act;
memset(&act,0,sizeof(act));
//t.sa_handler=sighandler;
//act.sa_flags= SA_NOCLDWAIT;
sigaction(SIGCHLD,&act,NULL);

printf("hello from the main \n");
pid=fork();
if(pid==0)
{
printf("child pid %d\n",getpid());
printf("hello from child\n");
sleep(20);
}
else
{
printf("hello from the parent process\n");
printf("parent pid :%d\n",getpid());
//signal(SIGCHLD,sighandler);
while(1)
{
printf(" i am from parent\n");
sleep(1);
}
}
}

