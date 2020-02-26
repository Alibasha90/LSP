#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>

void * fun1(void *);
void * fun2(void *);

int a=0,b=10;
sem_t m1,m2;
int main()
{
	sem_init(&m1,0,1);
	sem_init(&m2,0,1);	
	pthread_t th1,th2;
	if(pthread_create(&th1,NULL,fun1,NULL)<0)
	{
		perror("Thread1 fails...\n");
		return -1;
	}
	if(pthread_create(&th2,NULL,fun2,NULL)<0)
        {
                perror("Thread1 fails...\n");
                return -1;
        }
	
	pthread_exit(NULL);
}

void * fun1(void * args)
{
	printf("Thread1...\n");
	int i,j;
	sem_wait(&m1);
	sleep(2);
	printf("Thread1 entered into critical section for one resource..\n");
	for(i=0;i<=10;i++)
	{
		a++;
		printf("thread1_a:%d\n",a);
	}
//	sem_post(&m1);
	sem_wait(&m2);
	printf("Thread1 entered into critical section for second resource..\n");
	for(j=0;j<10;j++)
	{
		b--;
		printf("thread1_b:%d\n",b);
	}	
	sem_post(&m1);
	sem_post(&m2);
}
void * fun2()
{
        printf("Thread2...\n");
        int i,j;
        sem_wait(&m2);
	sleep(2);
        printf("Thread2 entered into critical section for one resource..\n");
        for(i=0;i<=10;i++)
        {
                b--;
		printf("thread2_b:%d\n",b);
        }
        sem_post(&m2);
        sem_wait(&m1);
        printf("Thread2 entered into critical section for second resource..\n");
        for(j=0;j<10;j++)
        {
                a++;
		printf("thread2_a:%d\n",a);

        }
       // sem_post(&m2);
        sem_post(&m1);
}

