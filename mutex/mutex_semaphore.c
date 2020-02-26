#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
int c=5;
sem_t sema;
//pthread_mutex_t m;
void * fun1(void *);
void * fun2(void *);
void * fun3(void *);
int main()
{
	sem_init(&sema,0,3);
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
	sem_wait(&sema);
//	pthread_mutex_lock(&m);
	printf("Thread1 enter into critical section...\n");
	int i;
	sleep(5);
	++c;
	printf("c value inc in fun1=%d\n",c);
	printf("Thread1 Exited..\n");
	sem_post(&sema);
//	pthread_mutex_unlock(&m);
}
void * fun2(void * args)
{
        //printf("Thread2..\n");
        sem_wait(&sema);
//        pthread_mutex_lock(&m);
	printf("Thread2 enter into critical section...\n");
	sleep(5);
	--c;
	printf("c value dec in fun2=%d\n",c);
	printf("Thread2 Exited..\n");
	sem_post(&sema);
//	pthread_mutex_unlock(&m);
}

void * fun3(void * args)
{
        //printf("Thread3..\n");
        sem_wait(&sema);
//  	pthread_mutex_lock(&m);      
        printf("Thread3 enter into critical section...\n");
        sleep(5);
	c=c*2;
	printf("c value mul in fun3=%d\n",c);
        printf("Thread3 Exited..\n");
	sem_post(&sema);
//	pthread_mutex_unlock(&m);
}

