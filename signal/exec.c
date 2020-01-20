#include<stdio.h>
int main(int argc, char *argv[])
{
char *args[]={"./zombie.c","hiiiii",NULL};
execvp("./zombie.c",args);
}
