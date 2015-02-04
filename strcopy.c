#include <stdio.h>


char * Strcpy(char *dst,char *src)
{
	char *s = dst;
	while(*dst++ = *src++);
	return s;
}

int main()
{
	char s[] = "dwqd";
	char d[] = "sqs";
	Strcpy(d,s);	
}
