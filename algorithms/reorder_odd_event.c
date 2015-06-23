#include<stdio.h>

int is_odd(int a)
{
	return a & 1;
}

int swap(int *a, int *b)
{
	if(*a == *b)return 0;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int reorder(int *a, int n, int (*cond)(int))
{
	if(a == NULL || n <= 0)return 0;
	int i, j;
	i = 0; j = n - 1;
	while(i < j)
	{
		while(i < j && cond(a[i]))i++;
		while(i < j && !cond(a[j]))j--;
		if(i < j)swap(&a[i], &a[j]);
	}
	return 0;
}

int main()
{
	int a[] = {1,3,2,4,3,6,7,9};
	reorder(a, 8, is_odd);
	int i;
	for(i = 0; i < 8; i++)
		printf("%d, ", a[i]);
	printf("\n");
}
