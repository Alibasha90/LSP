
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 
  
// A normal C function that is executed as a thread  
// when its name is specified in pthread_create() 
void *f1() 
{ 
    sleep(2); 

//intf("%d\n",a);
    printf("Printing GeeksQuiz from Thread`1 =%ld\n",pthread_self()); 
//   return NULL; 
} 
   
void *f2(void *vargp) 
{ 
    sleep(1); 
    printf("Printing GeeksQuiz from Thread2 ==%ld\n",pthread_self()); 
//   return NULL; 
}

void *f3() 
{ 
    sleep(1); 
    printf("Printing GeeksQuiz from Thread3 ==%ld\n",pthread_self()); 
  // return NULL; 
}

void *f4(void *vargp) 
{ 
    sleep(1); 
    printf("Printing GeeksQuiz from Thread4 ==%ld\n",pthread_self()); 
  // return NULL; 
}


int main() 
{
int i=0; 
    pthread_t thread_id1,thread_id2,thread_id3,thread_id4; 
    printf("Before Thread\n"); 

    pthread_create(&thread_id1, NULL, f1, NULL);   ///  HERE IT WILL CALL THREAD BUT DOESN'T WAIT 
//
pthread_join(thread_id1,NULL);

	sleep(4);       ////   NO TIME TO EXCUTE THREAD ,SO MAKE IT AS SLEEP THREAD ,,THEN IT WILL PRINT..  SO WE CAN USE PTHREAD_EXIT
    pthread_create(&thread_id2, NULL, f2, NULL); 
	sleep(4); 
//pthread_join(thread_id1,NULL);
    pthread_create(&thread_id3, NULL, f3, NULL); 
	sleep(4); 
    pthread_create(&thread_id4, NULL, f4, NULL); 
	sleep(4);
//    for(i = 0; i<5; i++)
 //   {
 //       pthread_join(thread_id[i], NULL); 
 //   }
 //   printf("After Thread\n"); 
  //  pthread_exit(NULL); 


    pthread_exit(NULL); 

}

