#include<stdio.h>

int cmp(int a, int b)
{
	return b - a;
}

int swap(int *a, int *b)
{
	if(*a == *b)return 0;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int next_array(int *a, int n)
{
	int i, j;
	for(i = n - 2; i >= 0; i--)
	{
		if(a[i] < a[i + 1])break;
	}
	if(i < 0)return 0;
	for(j = n - 1; a[j] <= a[i]; j--);
	swap(&a[i], &a[j]);

	qsort(&a[i + 1], n - i - 1, sizeof(int), cmp);
	return 1;
}


int main()
{
	int a[] = {1,2,3,4,5};
	int i;
	do{
		for(i = 0; i < 5; i++)
		{
			printf("%d, ", a[i]);
		}
		printf("\n");
	}while(next_array(a, 5));
}
