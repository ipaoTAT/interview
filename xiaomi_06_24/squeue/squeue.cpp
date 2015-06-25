#include<iostream>
#include<stack>
using namespace std;

/*
   complate a queue with two stack
*/

template <typename T>
class Squeue
{
	private:
		stack<T> stackA;
		stack<T> stackB;
		void restore();
	public:
		Squeue():stackA(), stackB(){}
		void push(const T&);
		void pop();
		T &top();
};

template <typename T>
void Squeue<T>::push(const T &elem)
{
	stackA.push(elem);
}

template <typename T>
void Squeue<T>::pop()
{
	if(stackB.empty())restore();
	stackB.pop();
}

template <typename T>
T & Squeue<T>::top()
{
	if(stackB.empty())restore();
	return stackB.top();
}

template <typename T>
void Squeue<T>::restore()
{
	while(!stackA.empty())
	{
		stackB.push(stackA.top());
		stackA.pop();
	}
}

int main()
{
	Squeue<int> sq;
	sq.push(1);
	cout << sq.top();
	sq.pop();
	sq.push(2);
	sq.push(3);
	sq.push(4);
	cout << sq.top();
	sq.pop();
	sq.push(5);
	cout << sq.top();
	sq.pop();
	cout << sq.top();
	sq.pop();
	cout << sq.top();
	sq.pop();
}
