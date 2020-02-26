#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
int c=5;
sem_t mutex1,mutex2;

void * fun1(void *);
void * fun2(void *);
void * fun3(void *);
int main()
{
	sem_init(&mutex1,0,2);
//	sem_init(&mutex2,0,1);
	pthread_t th1,th2,th3,th4;
	if(pthread_create(&th1,NULL,fun1,NULL)<0)
	{
		perror("Thread1 fails...\n");
		return -1;
	}
	if(pthread_create(&th2,NULL,fun2,NULL)<0)
        {
                perror("Thread2 fails...\n");
                return -1;
        }
	if(pthread_create(&th3,NULL,fun3,NULL)<0)
        {
                perror("Thread3 fails...\n");
                return -1;
        }
pthread_exit(NULL);
}

void * fun1(void * args)
{
	//printf("Thread1..\n");
	sem_wait(&mutex1);
	printf("Thread1 enter into critical section...\n");
	int i;
	sleep(5);
	printf("Thread1 After sleep..\n");
	sem_post(&mutex1);
}
void * fun2(void * args)
{
        //printf("Thread2..\n");
        sem_wait(&mutex1);
	//sem_post(&mutex1);
        printf("Thread2 enter into critical section...\n");
	sleep(5);
	printf("Thread2 after sleep..\n");
	sem_post(&mutex1);
}

void * fun3(void * args)
{
        //printf("Thread3..\n");
        sem_wait(&mutex1);
        
        printf("Thread3 enter into critical section...\n");
        sleep(5);
        printf("Thread3 After sleep..\n");
	sem_post(&mutex1);
}

