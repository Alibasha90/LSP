#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main() {
	int p[2];
	int var,fd;
	char rd[30];
//	char wt[20]="helloo pipes";
//	char rd[20];
//	pipe(p);

	close(1);
	dup(p[1]); 

	read(p[0],rd,strlen(rd));
	fd=open("file.text",O_RDWR);
//	close(1);
//	scanf("%d",&var);
	printf("%s\n",rd);
}
