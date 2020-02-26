#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <pthread.h> 
  
// To Count 
int counter = 0;  
  
// for temporary thread which will be  
// store thread id of second thread 
pthread_t tmp_thread;  
  
// thread_one call func 
void* func(void* p)  
{
sleep(2);
printf("func=%ld,tmp_thread=%ld\n",pthread_self(),tmp_thread); 
  //  while (1) { 
  
    //    printf("thread number one\n"); 
  //      sleep(1);   // sleep 1 second 
  //      counter++;    
        
        // for exiting if counter = = 5 
//        if (counter == 2) { 
  
            // for cancel thread_two 
            pthread_cancel(pthread_self());  
printf("func\n");  
            // for exit from thread_one  
//            pthread_exit(NULL);   
    //    } 
  //  } 
} 
  
// thread_two call func2 
void* func2(void* p)  
{ 
  sleep(2);
printf("func2=%ld,tmp_thread=%ld\n",pthread_self(),tmp_thread); 
    // store thread_two id to tmp_thread 
//    tmp_thread = pthread_self();  
  
//    while (1) { 
        printf("thread Number two\n"); 
  //      sleep(1); // sleep 1 second 
   // } 
} 
  
// Driver code 
int main() 
{ 
  
    // declare two thread 
    pthread_t thread_one, thread_two;  
  
    // create thread_one 
    pthread_create(&thread_one, NULL, func, NULL); 
  
    // create thread_two  
    pthread_create(&thread_two, NULL, func2, NULL);  
  
    // waiting for when thread_one is completed 
    pthread_join(thread_one, NULL);  
sleep(2);
    pthread_join(thread_two, NULL);  
  
}
    // waiting for when thread_two is completed 
//

/*

#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <pthread.h> 
  
// To Count 
int counter = 0;  
  
// for temporary thread which will be  
// store thread id of second thread 
pthread_t tmp_thread;  
  
// thread_one call func 
void* func(void* p)  
{ 
    while (1) { 
  
        printf("thread number one\n"); 
        sleep(1);   // sleep 1 second 
        counter++;    
        
        // for exiting if counter = = 5 
        if (counter = = 2) { 
  
            // for cancel thread_two 
            pthread_cancel(tmp_thread);  
  
            // for exit from thread_one  
            pthread_exit(NULL);   
        } 
    } 
} 
  
// thread_two call func2 
void* func2(void* p)  
{ 
  
    // store thread_two id to tmp_thread 
    tmp_thread = pthread_self();  
  
    while (1) { 
        printf("thread Number two"); 
        sleep(1); // sleep 1 second 
    } 
} 
  
// Driver code 
int main() 
{ 
  
    // declare two thread 
    pthread_t thread_one, thread_two;  
  
    // create thread_one 
    pthread_create(&thread_one, NULL, func, NULL); 
  
    // create thread_two  
    pthread_create(&thread_two, NULL, func2, NULL);  
  
    // waiting for when thread_one is completed 
    pthread_join(thread_one, NULL);  
  
    // waiting for when thread_two is completed 
    pthread_join(thread_two, NULL);  
  
}    pthread_join(thread_two, NULL);  
  
//pthread_exit(NULL);
}*/
