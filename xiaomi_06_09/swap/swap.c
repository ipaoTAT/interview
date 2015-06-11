#include<stdio.h>

int swap(int * const a, int * const b)
{
	if(a == b)return 0;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return 0;
}


int main()
{
	int a = 1, b = 2;
	swap(&b, &a);
	printf("%d, %d\n", a, b);
}
