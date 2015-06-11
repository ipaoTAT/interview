#include<stdio.h>
#include<assert.h>

/* calculate a^n */
int power(int a, int n)
{
	assert(a != 0 || n != 0);
	if(n == 0)return 1;
	int res = power(a, n >> 1);
	res *= res;
	if(n & 0x00000001)
	{
		res *= a;
	}
	return res;
}

int main(int argc , char **argv)
{
	int i, base, n;
	for(i = 1; i < argc; i++)
	{
		sscanf(argv[i], "%d^%d", &base, &n);
		printf("%d^%d = %d\n", base, n, power(base, n));
	}
}
