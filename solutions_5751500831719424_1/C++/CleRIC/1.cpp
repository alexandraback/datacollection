#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <stdlib.h>
#include <sstream>
#include <assert.h>

#include <time.h>
#pragma comment(linker, "/STACK:20000000")

#define fr(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define fd(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define mp make_pair
#define pb push_back
#define ll long long

using namespace std;

int ri(){int x;scanf("%d",&x);return x;}
ll rll(){ll x;scanf("%lld",&x);return x;}



void solve()
{
	int test = ri();
	fr(testing,1,test)
	{
		int n = ri();
		vector<vector<pair<char,int> > > mas;
		fr(i,1,n)
		{
			vector<pair<char,int> > temp;
			string s;
			cin >> s;
			char c = s[0];
			int cnt = 1;
			for(int j = 1;j < s.length();j++)
				if (s[j] != s[j - 1])
				{
					temp.pb(mp(c,cnt));
					cnt = 1;
					c = s[j];
				}
				else
					cnt++;
			temp.pb(mp(c,cnt));
			mas.pb(temp);
		}
		bool check = true;
		fr(j,0,mas[0].size() - 1)
			fr(i,1,n - 1)
				if (mas[i].size() < j + 1)
					check = false;
				else
				if (mas[i][j].first != mas[0][j].first)
					check = false;
		fr(i,1,n - 1)
			if (mas[i].size() != mas[0].size())
				check = false;
		if (!check)
		{		
			printf("Case #%d: Fegla Won\n",testing);
			continue;
		}
		int res = 0;
		fr(i,0,mas[0].size() - 1)
		{
			int mx = 10000000;
			fr(j,1,100)
			{
				int temp = 0;
				fr(k,0,n - 1)
					temp += abs(mas[k][i].second - j);
				mx = min(mx,temp);
			}
			res += mx;
		}
		printf("Case #%d: %d\n",testing,res);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("C:/Users/CleRIC/Desktop/Универ/acm.timus.ru/input.txt","rt",stdin);
		freopen("C:/Users/CleRIC/Desktop/Универ/acm.timus.ru/output.txt","wt",stdout);
	#else
		//freopen("input.in","rt",stdin);
		//freopen("output.out","wt",stdout);
	#endif

	solve();

	#ifndef ONLINE_JUDGE
		printf("\n\ntime-%.3lf",clock()*1e-3);
	#endif

	return 0;
}