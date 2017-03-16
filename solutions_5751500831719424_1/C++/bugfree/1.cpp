#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
	char c;
	int count;
	node(char x, int y):c(x), count(y){}
};
int helper(string *s, int N)
{
	vector<vector<node> > v;
	for(int i = 0; i < N; ++i)
	{
		vector<node> tmp;
		for(int j = 0; j < s[i].length(); ++j)
		{
			int k = j;
			int count = 0;
			while(k < s[i].length() && s[i][k] == s[i][j])
			{
				++count;
				++k;
			}
			j = k - 1;
			tmp.push_back(node(s[i][j], count));
		}
		v.push_back(tmp);
	}	
	for(int i = 1; i < N; ++i)
	{
		if(v[i].size() != v[0].size())
		{
			return -1;
		}
	}
	int result = 0;
	for(int j = 0; j < v[0].size(); ++j)
	{
		vector<int> tmp;
		char cc = v[0][j].c;
		for(int i = 0; i < N; ++i)
		{
			if(v[i][j].c != cc)
			{
				return -1;
			}
			tmp.push_back(v[i][j].count);
		}
		sort(tmp.begin(), tmp.end());
		int mid = N / 2;
		for(int i = 0; i < mid; ++i)
		{
			result += tmp[mid] - tmp[i];
		}
		for(int i = mid + 1; i < N; ++i)
		{
			result += tmp[i] - tmp[mid];
		}
	}
	return result;
}
void fun()
{
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i)
	{
		int N;
		cin >> N;
		string s[N];
		for(int j = 0; j < N; ++j)
			cin >> s[j];
		int result = helper(s, N);
		cout << "Case #" << i << ": ";
		if(result == -1)
		{
			cout << "Fegla Won";
		}
		else
		{
			cout << result;
		}
		cout <<endl;
	}
}

int main()
{
	fun();
}
