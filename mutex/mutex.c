#include <pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t count_mutex;
long long count;

void * increment_count()
{
int i=0;
    printf("inc thread\n");
    pthread_mutex_lock(&count_mutex);
while(i<5)
{
    count = count + 1;
sleep(7);
printf("increment=%d\n",count);
i++;
}
    pthread_mutex_unlock(&count_mutex);
}




void * get_count()
{
    long long c;
    printf("get thread\n");
    pthread_mutex_lock(&count_mutex);
    c = count;
	printf("get_=%d\n",c);
    pthread_mutex_unlock(&count_mutex);
    
}

int main()
{
	
pthread_t tid1,tid2;
pthread_create(&tid1,NULL,increment_count,NULL);
pthread_create(&tid2,NULL,get_count,NULL);

//pthread_join(tid1,NULL);
pthread_exit(0);
}
