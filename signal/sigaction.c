#include <signal.h>
#include<stdio.h>

static void f1(int signum)
{
	/* Take appropriate actions for signal delivery */
	printf("hello caught f1=%d\n",signum);
	sleep(2);
}

void f2(int signum)
{

printf("i m function 2 = %d\n",signum);
sleep(2);

}
int main()
{
	struct sigaction sa;


	sa.sa_handler = f1;
	sa.sa_handler = f2;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART; /* Restart functions if
	//                                 interrupted by handler */
	sigaction(SIGINT , &sa, NULL) 
	sigaction(SIGUSR1 , &sa, NULL) 
 
		/* Handle error */;

	while(1)
	{
		printf("hello main\n");
		sleep(2);
	}
	/* Further code */
}

