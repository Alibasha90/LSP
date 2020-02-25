/*nclude <stdio.h>
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

 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void bye(void)
{
	printf("That was all functions excuted ,,,,,, i m last one, folks\n");
}

void f1()
{
printf("fuck off 1 \n");
}

void f2()
{
printf("fuck off 2 \n");
}
void f3()
{
printf("fuck off 3 \n");
}
void f4()
{
printf("fuck off 4\n");
}
int main(void)
{
	long a;
	int i;

	a = sysconf(_SC_ATEXIT_MAX);
	printf("ATEXIT_MAX = %ld\n", a);
	i = atexit(bye);
	f1();
	i = atexit(bye);
	f2();
	i = atexit(bye);
	f3();
	i = atexit(bye);
	f4();

	if (i != 0) {
		fprintf(stderr, "cannot set exit function\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}


