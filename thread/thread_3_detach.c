#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
 
#include <unistd.h>
 
	pthread_t th1,th2;
void * f1(void * arg)
{
	printf("Thread 1 Function  Start\n");
	//printf("Thread Function :: End\n" );
	// Return value from thread
		sleep(5);
	
	pthread_detach(&th2);
	printf("Thread 1 Function  End\n" );
	return NULL;

}
 
void * f2(void * arg)

{
	printf("Thread 2 Function  Start\n");
	//printf("Thread Function :: End\n" );
	// Return value from thread
		sleep(5);
	
	printf("Thread 2 Function  End\n" );
	return NULL;
}
int main()
{
	// Thread id
//	pthread_t th1,th2;
 
	// Create a thread that will funtion threadFunc()
	pthread_create(&th1, NULL, &f1, NULL);
	pthread_create(&th2, NULL, &f2, NULL);
	// Check if thread is created sucessfuly
/*	if (err)
	{
	printf( "Thread creation failed :%d\n " ,strerror(err));
		return err;
	}
	else
		printf( "Thread Created with ID :%ld \n" ,threadId);
	// Do some stuff
 */
//	pthread_detach(th1);
//	if (err)
//		printf("Failed to detach Thread : %d\n", strerror(err) );
 
	// Sleep for 2 seconds because if main function exits, then other threads will
	// be also be killed. Sleep for 2 seconds, so that detached exits by then
//	sleep(2);
 

	printf("Main function ends\n " );

	sleep(6);
	return 0;
pthread_exit(NULL);
}
