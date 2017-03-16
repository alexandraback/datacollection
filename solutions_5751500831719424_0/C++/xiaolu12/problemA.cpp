#include <fstream>
#include <string.h>
#define MAXLEN 101
#define MAXN 101

using namespace std;

typedef struct{
	char ch[MAXLEN];
	int point;
}node;

node strs[MAXN];

int n;
int chLen[MAXN];

ifstream cin;
ofstream cout;

int findNextChar(node &str, char &c)
{
	if(str.ch[str.point] == '\0')
	{
		return -1;
	}
	int count = 1;
	c = str.ch[str.point];
	str.point++;
	while(c == str.ch[str.point]){
		str.point++;
		count++;
	}
	return count;
}

int findSameChar(node &str, int c)
{
	if(str.ch[str.point] == '\0')
	{
		return 0;
	}
	int count = 0;
	while(c == str.ch[str.point]){
		str.point++;
		count++;
	}
	return count;
}

int getMinChange()
{
	int min = MAXLEN*n;
	for(int i=1; i<=MAXLEN; ++i)
	{
		int temp = 0;
		for(int j=0; j<n; ++j)
		{
			if(i>chLen[j])
			{
				temp += i-chLen[j];
			}
			else
			{
				temp += chLen[j]-i;
			}
		}
		if(temp < min)
		{
			min = temp;
		}

	}
	return min;
}

int search()
{
	int sum = 0;
	while(true)
	{
		char c;
		int k = findNextChar(strs[0], c);
		if(k == -1)
		{
			for(int i=1; i<n; ++i)
			{
				if(findNextChar(strs[i], c) != -1)
				{
					return -1;
				}
			}
			break;
		}
		chLen[0] = k;
		for(int i=1; i<n; ++i)
		{
			k = findSameChar(strs[i], c);
			if(k == 0)
			{
				return -1;
			}
			chLen[i] = k;
		}
		int t = getMinChange();
		sum += t;
	}

	return sum;
}

int main()
{
	//cin.open("A-small-attempt1.in");
	cin.open("A-small-attempt2.in");
	cout.open("A-small-attempt2.out");
	int t = 0;
	cin>>t;
	for(int i=1; i<=t; ++i)
	{
		cin>>n;
		for(int j=0; j<n; ++j)
		{
			cin>>strs[j].ch;
			strs[j].point = 0;
		}
		int res = search();
		if(res == -1)
		{
			cout<<"Case #"<<i<<": "<<"Fegla Won"<<endl;
		}
		else
		{
			cout<<"Case #"<<i<<": "<<res<<endl;
		}
		
	}
	return 0;
}