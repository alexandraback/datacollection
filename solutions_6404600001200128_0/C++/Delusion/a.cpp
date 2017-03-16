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

#undef int
int main()
#define int long long
{
	ios::sync_with_stdio(0);
	int Test;
	cin >> Test;
	REP(T, Test)
	{
		int n;
		cin >> n;
		REP(i, n)
			cin >> a[i];
		int ans = 0, ans2 = 0, rate = 0;
		FOR(i, 1, n)
		{
			if (a[i] < a[i-1])
			{
				ans += a[i-1] - a[i];
				rate = max(rate, (a[i-1] - a[i]));
			}
		}
		REP(i, n-1)
		{
			ans2 += min(a[i], rate);
		}
		cout << "Case #" << T+1 << ": " << ans << " " << ans2 << endl;
	}
	return 0;
}


