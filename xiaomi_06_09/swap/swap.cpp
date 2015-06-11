#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
	return ;
}

int main()
{
	int a = 1, b = 2;
	swap(a, b);
	cout << a << "," << b << endl;
}
