#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
void exitfunc() {
   printf("Called cleanup function - exitfunc()\n");
   return;
}

void f1()
{
printf("f1..\n");
}

int main() 
{
   atexit(exitfunc);
   atexit(f1);

   printf("Hello, World!\n");
   _exit (0);
}
