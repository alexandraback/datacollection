#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

#define ii pair<int, int>
#define ll long long

int N;
string S[101];

int solve()
{
	string xbase;
	for(int i = 0; i < N; i++)
	{
		int b = 0;
		char base[100];
		base[0] = S[i][0];
		for(int j = 1; S[i][j] != '\0'; j++)
		{
			if(S[i][j] != base[b])
			{
				base[++b] = S[i][j];
			}
		}
		base[++b] = '\0';
		if(i == 0)
		xbase = (string) base;
		else if(xbase != (string) base)
		{
			cout<<"Fegla Won\n";
			return 0;
		}
	}
	
	//cout<<xbase<<endl;
	
	int len = xbase.size();
	int index[101];
	int count[101][101];
	int total = 0;
	
	for(int i = 0; i < 101; i++)
	{
		for(int j = 0; j < 101; j++)
		count[i][j] = 0;
		index[i] = 0;
	}
	
	for(int i = 0; i < len; i++)
	{
		char x = xbase[i];
		for(int j = 0; j < N; j++)
		{
			string s = S[j];
			for(; s[index[j]] == x; index[j]++)
			{
				count[j][i]++;
			}	
		}
	}
	
	for(int i = 0; i < len; i++)		//For each char in base
	{
		int localmin = count[0][i];
		int localmax = count[0][i];		
		for(int j = 0; j < N; j++)		//For each string
		{
			localmin = min(localmin, count[j][i]);
			localmax = max(localmax, count[j][i]);
		}
		int xtotal = (localmax - localmin)*N;
		for(int target = localmin; target <= localmax; target++)
		{
			int localtotal = 0;
			for(int j = 0; j < N; j++)
			{
				localtotal += abs(target - count[j][i]);
			}
			xtotal = min(localtotal, xtotal);
		}
		total += xtotal;
	}
	cout<<total<<endl;
}

int main(void)
{
	freopen("A0.in", "r", stdin);
	freopen("A0.out", "w", stdout);
	
	int T, t = 1;
	
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i = 0; i < N; i++)
		cin>>S[i];
		cout<<"Case #"<<t++<<": ";
		solve();
	}
	return 0;
}

