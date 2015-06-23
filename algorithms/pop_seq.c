#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

int pop_seq(int *a, int n)
{
	int i, j;
	int *stack = (int *)malloc(sizeof(int) *n);
	int top = -1;
	assert(stack != NULL);
	for(i = 1, j = 0; i <= n;)
	{
		if(top >= 0 && stack[top] == a[j])
		{
			printf("pop %d\n", a[j]);
			top --;		//pop
			j ++;
		}
		else
		{
			printf("push %d\n", i);
			stack[++top] = i++;		//push
		}
	}

	while(top >= 0 && stack[top] == a[j++])top--;
	if(top < 0)return 1;
	else return 0;

}


int main()
{
	int pop_order[] = {4,3,5,1,2};
	printf("%d\n", pop_seq(pop_order, 5));
}
