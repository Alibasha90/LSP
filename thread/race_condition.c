#include<stdio.h>
#include<pthread.h>
#include<stdbool.h>
#include<time.h>
int count = 10,c;
pthread_mutex_t lock;
void *thread_inc(void *data)
{
int i=5;

	while (true)
	{
		double time_spent = 0.0;
		clock_t time_begin = clock();
	//	printf("\nIn Increment thread \n");
		sleep(1);
		
//		pthread_mutex_lock(&lock);
		
		if(i>0){		
		{		
		count += 1;
		sleep(2);
		printf("After increment count is %d \n",count);
		i--;
		}
		}
//		pthread_mutex_unlock(&lock);
//		if(c>=50)
//			pthread_exit(NULL);
//		clock_t time_end = clock();
//printf("time spent for increment thread %f \n\n",time_spent += (double)(time_end - time_begin) / CLOCKS_PER_SEC);
	}
}
void *thread_dec(void *data)
{
int i=5;

	while (true)
	{
		double time_spent = 0.0;
		clock_t time_begin = clock();
//		printf("\nIn decrement thread \n");
//		sleep(0.5);
//		pthread_mutex_lock(&lock);
		if(i>0){
		{
		count -= 1;
		sleep(2);
		printf("After decrement count is %d \n",count);
		i--;
		}
		}
//		pthread_mutex_unlock(&lock);
//		if(c>=50)
//			pthread_exit(NULL);
//		clock_t time_end = clock();
//		printf("time spent for decrement thread %f \n\n",time_spent += (double)(time_end - time_begin) / CLOCKS_PER_SEC);
	
	}
}
int main()
{
	pthread_t pid_inc,pid_dec;
	pthread_create(&pid_inc,NULL,thread_inc,NULL);
	pthread_create(&pid_dec,NULL,thread_dec,NULL);

//	pthread_join(pid_inc,NULL);
//	pthread_join(pid_dec,NULL);

			pthread_exit(NULL);
}
