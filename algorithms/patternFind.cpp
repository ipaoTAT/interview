#include<iostream>
#include<string>
#include<vector>
using namespace std;

int findForce(const string str, const string ptn)
{
	int i, j;
	for(i = 0, j = 0; str[i] != 0;)
	{
		if(str[i] == ptn[j])
		{
			i++;j++;
		}else{
			i = i - j + 1;
			j = 0;
		}
		if(ptn[j] == 0)break;
	}
	if(ptn[j] == 0)return (i - j);
	else return -1;
}

vector<int> getNext(const string &ptn)
{
	int i, j;
	vector<int> next(ptn.size());
	for(i = 0, j = -1; j < ptn.size();)
	{
		if(j == -1 || ptn[i] == ptn[j])
		{
			i++;j++;
			next[i] = ptn[i] != ptn[j] ? j : next[j];
		}else{
			j = next[j];
		}
	}
	return next;
}

int findKmp(const string &str, const string &ptn)
{
	int i, j;
	vector<int> &next = getNext(ptn);
	for(i = 0, j = 0; i < str.size();)
	{
		if(str[i] == ptn[j])
		{
			i++;j++;
		}else{
			j = next[j];
		}
		if(j == ptn.size())break;
	}
	if(j == ptn.size())return (i - j);
	else return -1;
}

int main()
{
	char *str = "aaabcabc";
	char *ptn = "ab";
	cout << "str = " << str << ",ptn = " << ptn << ", " << findKmp(str, ptn) << endl;
}
