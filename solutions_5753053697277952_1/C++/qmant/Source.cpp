#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<iomanip>
#include<queue>
#include<deque>
#include<stack>
#include<numeric>
#include<functional>
#include<fstream>
#define ll long long
#define vi vector<long long>
#define vvi vector<vi>
#define pii pair<long long,long long>
using namespace std;

inline pair<double,long long> matj(pair<double,long long> a, long long b)
{
	return{ a.first += (double)(b + a.second) / (double)b, (b + a.second) };
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	for (int qq = 0; qq < t; qq++)
	{
		int n;
		cin >> n;
		vi a(n);
		int w1 = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i], w1 += a[i];
		string s="";

		while (1)
		{
			int w = 0;
			char c;
			for (int i = 0; i < n; i++)
			{
				if (w < a[i])
				{
					w = a[i];
					c = 'A' + i;
				}
			}
			if (w == 0)
				break;
			s += c;
			a[c - 'A']--;
			
		}


		cout << "Case #" << qq + 1 << ": ";
		if (w1 % 2 == 1)
		{
			cout << s[0] << ' ';
			s = s.substr(1);
		}
		for (int i = 0; i < s.size(); i += 2)
		{
			cout << s[i] << s[i + 1] << ' ';
		}
		cout << endl;
	}


	return 0;
}