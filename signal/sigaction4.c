#include<stdio.h>
#include<signal.h>
#include<string.h>
void handler(int signo)
{
    printf("Into handler\n");
    printf("caught siganl %d\n",signo);
sleep(5);
}
int main()
{
    struct sigaction act;
    sigset_t sigmask;
memset(&act,0,sizeof(act));


 // act.sa_handler = handler;

 // act.sa_flags = 0;
    sigemptyset(& act.sa_mask);
sigaddset(&sigmask,SIGQUIT);
sigaddset(&sigmask,SIGTERM);
act.sa_handler=handler;
act.sa_mask=sigmask;
act.sa_flags=SA_NODEFER;

    sigaction(SIGINT, &act, NULL);
    while(1)
{
printf("hello from main\n");
sleep(3);
}
    return 0;
}
