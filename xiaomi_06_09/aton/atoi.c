#include<stdio.h>

#define SETERR(x) {_errno=x;return 0;}while(0);

int _errno = 0;

int _overflow(unsigned int n, int sign)
{
	if((sign && n > 0x7FFFFFFF)
		|| (!sign && n > 0x80000000))return 1;
	return 0;
}

int _atoi(char *str)
{
	if(str == NULL)SETERR(1);
	int sign = 1, res = 0;
	
	/* trim left */
	while(*(str++) == ' ');
	str--;

	if(*str == '-')sign = 0;
	if(*str == '+' || *str == '-')str++;

	while(*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if(_overflow(res, sign))SETERR(2);
		str++;
	}

	/* trim right */
	while(*(str++) == ' ');
	str--;

	if(*str != 0)SETERR(1);

	return res;
}

int main()
{
	char *str = "110101010100101010023";

	int res = _atoi(str);
	printf("str = %s, atoi=%d(errno = %d)\n", str, res, _errno);
}
