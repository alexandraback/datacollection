#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <utility>
#define mp make_pair
#define F first
#define S second
#define N 100005 //10^5 + 5
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	int t;
	cin >> t;
	for(int o = 0; o < t; o++)
	{
		vector<string> ans;
		int n, mn = 10000;
		int p[100];
		pair<int, int> b[100];
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> p[i];
			b[i] = mp(p[i], i);
			mn = min(mn, p[i]);
		}
		cout << "Case #" << o+1 << ": ";
		sort(b, b + n);
		bool go = 1;
		while(go)
		{
			go = 0;
			for(int i = n - 1; i >= 0; i--)
			{
				if(b[i].F > mn)
				{
					cout << char(int('A') + b[i].S) << " ";
					go = 1;
					b[i].F--;
				}
			}
		}
		if(n % 2 == 1)
		{
			for(int j = 1; j <= mn; j++)
			{
				string s;
				cout << char(int('A') + b[n-1].S) << " ";
				s += char(int('A') + b[n-1].S);
				ans.push_back(s);
			}
		}
		for(int i = 0; i < n - (n%2); i+=2)
		{
			for(int j = 1; j <= mn; j++)
			{
				string s;
				cout << char(int('A') + b[i].S) << char(int('A') + b[i+1].S) << " ";
				s += char(int('A') + b[i].S) + char(int('A') + b[i+1].S);
				ans.push_back(s);
			}
		}
		for(int i = 0; i < ans.size(); i++)
		{
			//cout << ans[i] << " ";
		}
		cout << endl;
	}
	return 0;
}