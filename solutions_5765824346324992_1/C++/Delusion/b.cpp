/*
 * Author: Farhad Shahmohammadi
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <queue>

using namespace std;

#define int long long

#define FOR(i, s, n) for(int i=s; i<(int)(n); i++)
#define REP(i, n) FOR(i, 0, n)
#define REV(i, n) for(int i=n-1; i>=0; --i)
#define show(x) cerr << #x << '=' << x << endl;
#define sh(x) cerr << #x << '=' << x << ' ';
#define sh2(x, y) {sh(x)show(y)}
#define sh3(x, y, z) {sh(x)sh(y)show(z)}
#define pb push_back
#define CL cerr << "--------------------" << endl;
#define PII pair<int, int>

const int INF = (int)1e9;
const int MAX = 1000 + 10;

int a[MAX];
int n, m;

int f(int mid)
{
	int s = 0;
	REP(i, n)
		s += mid  / a[i];
	return s;
}

int bin(int x, int y)
{
	if(y - x == 1)
		return y;
	int mid =(x + y) / 2;
	int s = f(mid);
	if(s + n >= m)
		return bin(x, mid);
	else
		return bin(mid, y);
}

#undef int
int main()
#define int long long
{
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	REP(Test, T)
	{
		cin >> n >> m;
		REP(i, n)
			cin >> a[i];
		int sec = bin(-1, 100000 * m + 1);

		int k = m - f(sec);
		REP(i, n)
			if(sec % a[i] != 0)
				k --;
		REP(i, n)
		{
			if(sec % a[i] == 0)
			{
				k --;
				if(k <= 0)
				{
				cout << "Case #" << Test+1 << ": " << i+1 << endl;
				break;
				}
			}
		}
	}
}


