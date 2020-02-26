#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
const char * argv[]={"ps","-eaf",NULL};
	if(fork()==0)
	{
		//getchar();
		execvp("ps",argv);
		return ;
	}
	else
	{
//		wait(NULL);
		printf("this is parent... \n");
		execl("bin/ls","ls",NULL);
	//	wait(NULL);
	}

}
