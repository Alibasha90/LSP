#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int id=fork();
int d;

	if(id==0)
	{
		sleep(10);
		d=getpid();
		printf("child 1=%d\n",getpid());		
		


	}

	else
	{
		if(fork()==0)
		{
			
			sleep(40);
			printf("child 2---%d\n",getpid() );
			printf("child 2 parent ---%d\n",getppid() );
		}


		else{
			int ret;
			printf("parent process=%d\n",getpid());
			waitpid(d,&ret,0);
			printf("child 1 returned--%d\n",ret);
			exit(0);
		}
	}

}
