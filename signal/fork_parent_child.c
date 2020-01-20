#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main() {
	pid_t pid, mypid, myppid;
	pid = getpid();
	printf("Before fork: Process id is %d\n", pid);
	pid = fork();

	if (pid < 0) {
		perror("fork() failure\n");
		return 1;
	}

	// Child process
	if (pid == 0) {
		printf("This is child process\n");
		mypid = getpid();
		myppid = getppid();
		printf("Process id is %d and PPID is %d\n\n\n\n", mypid, myppid);
		return 99;
	}
	else { // Parent process 
		sleep(2);
		int ret;
		printf("This is parent process\n");
		mypid = getpid();
		myppid = getppid();
		printf("Process id is %d and PPID is %d\n", mypid, myppid);
		printf("Newly created process id or child pid is %d\n", pid);
		wait(&ret);
		printf("return value of child==%d\n",ret);
/*		if(WIFEXITED(ret))
		{
			printf("child returned ==%d\n",ret);
		}
		return 0;*/
	}
}
