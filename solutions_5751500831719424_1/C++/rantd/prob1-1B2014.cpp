#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;
typedef long long int64;
typedef pair<int, char> PIC;
const int MOD = 1000000007;
const double EPSILON = 1e-10;

#define FORU(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REPU(i, a, b) for (int i = (a); i < (b); ++i)
#define REPD(i, a, b) for (int i = (a); i > (b); --i)
#define SIZE(A) ((int) A.size())
#define PB(X) push_back(X)
#define MP(A, B) make_pair(A, B)

template<class T> inline T tmin(T a, T b) {return (a < b) ? a : b;}
template<class T> inline T tmax(T a, T b) {return (a > b) ? a : b;}
template<class T> inline T tabs(T a) {return (a > 0) ? a : -a;}
template<class T> T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}

int b[101];

int calc(int n, int min_vals, int max_vals)
{
	int val = 100000;
	FORU(i, min_vals, max_vals) {
		int tot = 0;
		REPU(j, 0, n) {
			tot += tabs(b[j] - i);
		}
		val = tmin(val, tot);
	}
	return val;
}

int main(int argc, char const *argv[])
{
	/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	*/
	
	ios_base::sync_with_stdio(false);
	int n, a[101], ntest;
	string s[101];
	vector<PIC> G[101];
	cin >> ntest;
	FORU(t, 1, ntest) {
		cin >> n;
		REPU(i, 0, n) {
			G[i].clear();
			cin >> s[i];
			int len = s[i].size();
			int num = 1;
			REPU(j, 0, len-1) {
				if (s[i][j] == s[i][j+1]) num++;
				else {
					G[i].PB(MP(num, s[i][j]));
					num = 1;
				}
			}
			G[i].PB(MP(num, s[i][len-1]));
		}
		int ans = 0;
		REPU(i, 0, n-1) {
			if (SIZE(G[i]) != SIZE(G[i+1])) {
				ans = -1; break;
			}
		}
		if (ans == -1) {
			printf("Case #%d: Fegla Won\n", t);
			continue;
		}
		bool ip = false;
		REPU(i, 0, SIZE(G[0])) {
			char c = G[0][i].second;
			int min_vals = G[0][i].first;
			int max_vals = min_vals;
			b[0] = min_vals;
			int add = G[0][i].first;
			REPU(j, 1, n) {
				b[j] = G[j][i].first;
				if (G[j][i].second != c) {
					ip = true;
					break;
				}
				min_vals = tmin(min_vals, G[j][i].first);
				max_vals = tmax(max_vals, G[j][i].first);
				add += G[j][i].first;
			}
			if (ip) break;
			ans += calc(n, min_vals, max_vals);
		}
		if (ip) {
			printf("Case #%d: Fegla Won\n", t);
		}
		else printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}