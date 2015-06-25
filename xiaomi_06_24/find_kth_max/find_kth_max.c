#include<stdio.h>

int middle(int *a, int n)
{
	int i, j;
	int tmp = a[0];
	i = 0; j = n - 1;
	while(i < j)
	{
		while(i < j && a[j] <= tmp)j--;
		if(i < j)a[i++] = a[j];
		while(i < j && a[i] > tmp)i++;
		if(i < j)a[j--] = a[i];
	}
	a[i] = tmp;
	return i;
}

int find_kth_max(int *a, int n, int k)
{
	if(n == 1 && k == 1)return a[0];
	int i, j, mid;
	mid = middle(a, n);
	if(mid + 1 > k)return find_kth_max(a, mid, k);
	else if(mid + 1 < k)return find_kth_max(a + mid + 1, n - mid - 1, k - mid - 1);
	if(mid + 1 == k)return a[mid];
}


int main()
{
	int a[] = {9,8,7,6,5,4,3,2,1};
	printf("the %dth max if %d\n", 5, find_kth_max(a, 9, 1));
}
