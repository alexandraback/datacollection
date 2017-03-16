#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <set>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <ctime>
#include <queue>
#include <map>
#include <cstring>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef bool bl;
typedef pair<bl, bl> pbl;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair
#define ft first
#define sd second
#define forn(i, y, x) for(int i = y; i < x; i++)
#define ford(i, y, x) for(int i = y; i >= x; i--)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define error exit(1)
#define DEBUG
const int mod = (int)1e9;
const ll inf = (ll)2e18;
const int base = 1000 * 1000 * 1000;
const int maxn = 2005;
const ld pi = acosl(-1.0);
const ld eps = 1e-9;

void solve()
{
	int t;
	scanf("%d", &t);
	forn(tt, 1, t + 1){
		int n;
		scanf("%d", &n);
		int sum = 0;
		set<pii> st;
		forn(i, 0, n){
			int val;
			scanf("%d", &val);
			sum += val;
			st.insert(mp(val, i));
		}
		printf("Case #%d: ", tt);
		while (sum > 0){
			string ans = "";
			pii v = *st.rbegin();
			st.erase(v);
			ans += 'A' + v.sd;
			v.ft--;
			sum--;
			if (sum > 0){
				if (v.ft > 0) st.insert(v);
				pii v = *st.rbegin();
				st.erase(v);
				if (!st.empty() && (sum - 1) / 2 < (*st.rbegin()).ft){
					st.insert(v);
				}
				else{
					ans += 'A' + v.sd;
					v.ft--;
					sum--;
					if (v.ft > 0) st.insert(v);
				}
			}
			printf("%s ", ans.c_str());
		}
		printf("\n");
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}