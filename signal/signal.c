#include<unistd.h>
#include<stdio.h>
#include<unistd.h>

#include<signal.h>
void handler_sigint(int);
void handler_signal(int);
int main()
{
	printf("%d\n",getpid());
	signal(SIGINT,handler_sigint);
	signal(12,handler_signal);
	while(1)
	{
		printf("i am in main fucntion\n");
		sleep(1);
	}
	return 0;
}
void handler_sigint(int signo)
{
	printf("caught SIGINT siganal %d\n",signo);
	sleep(10);
	printf("exited from signal sigint routine \n");
}
void handler_signal(int num)
{
	printf("caught signal %d\n",num);
	
			sleep(15);
			printf("exited from signal 12 routine\n");
}
