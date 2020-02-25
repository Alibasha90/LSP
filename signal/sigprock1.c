#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void sighand(int signo)
{
printf("signal %d number caught\n",signo);
}
int main()
{
sigset_t s_set;
signal(SIGQUIT,sighand);
signal(SIGTERM,sighand);
printf("pid %d\n",getpid());
sigemptyset(&s_set);
sigaddset(&s_set,SIGQUIT);
sigaddset(&s_set,SIGTERM);
sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set,NULL);
printf("%s send me signal SIGQUIT AND SIGTERM  and see effect now\n",__func__);
getchar();
sigprocmask(SIG_UNBLOCK,&s_set,NULL);
printf("%s send me signal SIGQUIT AND SIGTERM and see effect now\n",__func__);
getchar();
}
