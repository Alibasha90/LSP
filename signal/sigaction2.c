#include <stdio.h>

	#include <signal.h>

	#include <string.h>
	#include <unistd.h>
	 
	struct sigaction act;
	 
	void sighandler(int signum)
	{
	    printf("Received signal %d\n", signum);
//	    printf("Signal originates from process %lu\n",
//	        (unsigned long)info->si_pid);
}
	int main()
	{
	    printf("I am %lu\n", (unsigned long)getpid());
	 
	    memset(&act, 0, sizeof(act));
	 
	    act.sa_handler = sighandler;
//	    act.sa_flags = SA_SIGINFO;
	 
	    sigaction(SIGINT ,&act, NULL);
	 
	    // Waiting for CTRL+C...
	    sleep(100);
	 
	}
