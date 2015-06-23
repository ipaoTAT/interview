#include<stdio.h>

int verify(int *a, int n)
{
	if(n <= 0)return 1;
	int root = a[n - 1];
	int i, j;
	for(i = 0; i < n - 1 && a[i] <= root; i++);
	j = i;
	for(; i < n - 1 ; i++)if(a[i] <= root)break;
	if(i != n - 1)return 0;
	return verify(a, j) && verify(a + j, n - j - 1);
}

int main()
{
	int post_order[] = {5,7,9,10,11,7,8};
	printf("%d\n", verify(post_order, 7));
}
