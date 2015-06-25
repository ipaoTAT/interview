#include<string.h>
#include<stdio.h>

inline int min(int x, int y)
{
	return x < y ? x : y;
}

int min_edit_distence(char *src, char *dst, int i)
{
	if(src[0] == 0)return strlen(dst);		//addition
	if(dst[0] == 0)return strlen(src);		//delete
	if(src[0] == dst[0])return min_edit_distence(src + 1, dst + 1, i + 1); //skip
	int modify = min_edit_distence(src + 1, dst + 1, i + 1);
	int add = min_edit_distence(src, dst + 1, i);
	int delete = min_edit_distence(src + 1, dst, i + 1);

	int _min = min(min(modify , add), delete);
	if(_min == modify)
	{
		printf("modify %c(%d) to %c | ", src[0], i, dst[0]);
	}
	if(_min == add)
	{
		printf("add %c at %d | ", dst[0], i);
	}
	if(_min == delete)
	{
		printf("delete %c at %d | ", src[0], i);
	}
	printf("\n");
		
	return _min + 1;
}


int main()
{
	char src[100], dst[100];
	while(scanf("%s%s", src, dst) != EOF)
		printf("min edit distence is %d\n", min_edit_distence(src, dst, 0));
}
