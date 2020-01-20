#include<stdio.h>
int main()
{

struct sigaction v;
sigset_t sigmask;

memset(&v,0,sizeof(v));

sigemptyset(&v.sa_mask);
sigaddset(&




