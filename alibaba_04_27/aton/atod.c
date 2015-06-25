#include<stdio.h>

#define SETERR(x) do{_errno = x; return -1;}while(0)
#define true 1
#define false 0

int _errno = 0;

int _overflow(unsigned int n, int flag)
{
	if((flag && n > 0x7FFFFFFF) || 
		(!flag && n > 0x80000000))return true;
	return false;
}

double atod(char *str)
{
	int positive = 1;
	int i;
	double res = 0;
	
	while(str[i++] == ' ');
	i--;

	if(str[i] == '-')positive = 0;
	if(str[i] == '+' || str[i] == '-')i++;

	char tmp;
	while((tmp = str[i]) != 0)
	{
		if(tmp > '9' || tmp < '0')break;
		res = res * 10 + (tmp -'0');
		//if(_overflow((unsigned int)res, positive))SETERR(2);
		i++;
	}

	if(str[i] == '.')
	{
		i++;
		double base = 0.1;
		while((tmp = str[i]) != 0)
		{
			if(tmp > '9' || tmp < '0')break;
			res = res + (tmp - '0') * base;
			base *= 0.1;
			//if(_overflow((unsigned int)res, positive))SETERR(2);
			i++;
		}
	}

	while(str[i++] == ' ');
	i--;

	if(str[i] != 0)SETERR(1);
	else if(positive)return res;
	else return 0 - res;
}

int main()
{
	char str[100];
	while(scanf("%s", str) != EOF)
	{
		_errno = 0;
		double res = atod(str);
		printf("%lf, errno(%d)\n", res, _errno);
	}
}
