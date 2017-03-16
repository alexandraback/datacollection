#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<math.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
//#pragma comment(linker, "/STACK:36777216") //if stack overflow
using namespace std;

#define LarN 100000
typedef long long LL;
const double d_pi = 57.2957795;

template<class T> inline void ReMin(T &a, T b) { if (b<a) a = b; }
template<class T> inline void ReMax(T &a, T b) { if (b>a) a = b; }
template<class T> inline T sqr(T x) { return x*x; }

void solve()
{
	int N, r;
	cin >> N;
	vector<pair<int, int> > buf;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &r);
		buf.push_back(make_pair(r, i));
	}
	sort(buf.begin(), buf.end());

	int ca = buf[N - 1].first, cb = buf[N - 2].first;
	int sa = buf[N - 1].second, sb = buf[N - 2].second;
	for (int i = 0; i < ca - cb; i++)
	{
		printf(" %c", sa + 'A');
	}

	for (int i = 0; i < N - 2; i++)
	{
		int c = buf[i].first;
		int s = buf[i].second;
		for (int j = 0; j < c; j++) printf(" %c", s + 'A');
	}

	 // two senators left;
	for (int i = 0; i < cb; i++)
	{
		printf(" %c%c", sa + 'A', sb + 'A');
	}
	printf("\n");
	
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T_case;
	cin >> T_case;
	for (int i_case = 1; i_case <= T_case; i_case++) {
		printf("Case #%d:", i_case);
		solve();
	}
	
	return 0;
}