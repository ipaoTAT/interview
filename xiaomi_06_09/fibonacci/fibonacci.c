#include<stdio.h>
#include<stdlib.h>

/* fibonacci O(logn) */
/* Note that , use tmp array */
int power(int (*a)[2], int n)
{
	if(n == 1)return 0;
    int b[2][2], c[2][2];
    memcpy((void *)b, (void *)a, 4 *sizeof(int));
	
	power(a, n >> 1);
    memcpy((void *)c, (void *)a, 4 *sizeof(int));
	a[0][0] = c[0][0] * c[0][0] + c[0][1] * c[1][0];
	a[0][1] = c[0][0] * c[0][1] + c[0][1] * c[1][1];
	a[1][0] = c[1][0] * c[0][0] + c[1][1] * c[1][0];
	a[1][1] = c[1][0] * c[0][1] + c[1][1] * c[1][1];

    if(n & 0x00000001)
    {
		/* do a * b */
    	memcpy((void *)c, (void *)a, 4 *sizeof(int));
		a[0][0] = c[0][0] * b[0][0] + c[0][1] * b[1][0];
		a[0][1] = c[0][0] * b[0][1] + c[0][1] * b[1][1];
		a[1][0] = c[1][0] * b[0][0] + c[1][1] * b[1][0];
		a[1][1] = c[1][0] * b[0][1] + c[1][1] * b[1][1];
	}
	return 0;
}

int fibonacci(int n)
{
	int a[2][2] = {{1, 1},{1, 0}};

	power(a, n - 1);
	return a[0][0];
}

int fibonacci_on(int n)
{
	int n1, n2, res;
	n1 = n2 = 0; res = 1;
	for(; n > 1; n--)
	{
		n1 = n2; n2 = res;
		res = n1 + n2;
	}
	return res;
}

int main(int argc, char **argv)
{
	int input = 0;
	if(argc > 1)
	{
		sscanf(argv[1], "%d", &input);
	}
	printf("fibonacci %d = %d\n", input, fibonacci(input));
	printf("fibonacci_on %d = %d\n", input, fibonacci_on(input));
}
