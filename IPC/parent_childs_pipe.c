#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main() {
	int pipefds[2];
	int returnstatus;
	char wt[20]="helloo pipes";
	char rd[20];
	pipe(pipefds);

	if (returnstatus == -1) {
		printf("Unable to create pipe\n");
		return 1;
	}
	//printf("%d\n",returnstatus);
	if(fork()==0)
	{
		printf("child is writing...\n");   
		write(pipefds[1], wt, sizeof(wt));
	}
	else
	{
		read(pipefds[0], rd, sizeof(rd));
		printf("Reading from pipe –: %s\n", rd);
	}
	return 0;
}
