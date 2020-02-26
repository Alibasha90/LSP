#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	if(fork()==0)
	{
		//getchar();
		execl("/bin/ps","ps",NULL);
		return ;
	}
	else
	{
		wait(NULL);
		printf("this is parent... \n");
		execl("bin/ls","ls",NULL);
	//	wait(NULL);
	}

}
