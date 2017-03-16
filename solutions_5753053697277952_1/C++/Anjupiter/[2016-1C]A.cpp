//TAG : 
#include<bits/stdc++.h>//Just in case 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<climits>
#include<functional>
#include<numeric>
using namespace std;
#define rep(i,n)	for(int (i)=0;(i)<(n);(i)++)
#define repd(i,n)	for(int (i)=(n)-1;(i)>=0;(i)--)
#define REP(i,j,n)  for(int (i)=(j),_n=(n); (i) < _n; (i)++)
#define FOR(i,a,b)  for(int _b=(b), (i)=(a); (i) <= _b; (i)++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define CLEAR(x) memset((x),0,sizeof(x))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EPS 	(1e-9)
typedef pair<int, int>	PII;
typedef vector<int>		VI;
typedef unsigned int	uint;
typedef long long		LL;
typedef unsigned long long	ULL;
template<typename T> void check_max(T& a, T b) { if (a < b) a = b; }
template<typename T> void check_min(T& a, T b) { if (a > b) a = b; }
#ifdef _MSC_VER
#include "builtin_gcc_msvc.h"
#define gets	gets_s
#else
#define popcnt(x)	__builtin_popcount(x)
#define ctz(x)		__builtin_ctz(x)
#define clz(x)		__builtin_clz(x)
#define popcntll(x)	__builtin_popcountll(x)
#define ctzll(x)	__builtin_ctzll(x)
#define clzll(x)	__builtin_clzll(x)
#endif

bool isok(int arr[26], int n) {
	int sum = accumulate(arr, arr + 26, 0);
	int ma = *max_element(arr, arr + 26);
	return ma <= sum / 2;
}

int main()
{
	int arr[26];

	int TC;
	scanf("%d", &TC);
	FOR(T, 1, TC)
	{
		int n; scanf("%d", &n);
		CLEAR(arr);
		rep(i, n)scanf("%d", &arr[i]);
		printf("Case #%d:", T);
		int sum = accumulate(arr, arr + 26, 0);
		while (sum > 0) {
			//find most big
			int best = 0, check = 0;
			rep(i, n) {
				if (best < arr[i]) {
					best = arr[i];
					check = 1 << i;
				} else if(best==arr[i]){
					check |= 1 << i;
				}
			}
			if (popcnt(check) & 1) {
				int j = ctz(check);
				--arr[j];
				--sum;
				if (!isok(arr, n)) {
					throw "";
				}
				printf(" %c", 'A' + j);
			} else {
				int j = ctz(check);
				check &= check - 1;
				int k = ctz(check);
				--arr[j], --arr[k];
				sum -= 2;
				if (!isok(arr, n)) {
					throw "";
				}
				printf(" %c%c", 'A' + j, 'A' + k);
			}
		}
		puts("");
	}

	return 0;
}