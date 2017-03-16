/*
 	Beautiful Codes are MUCH better than 'Shorter' ones !
user  : triveni
date  : 18/04/2015
time  : 07:24:25
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<int,int>
#define      vi                std::vector<int>
#define      mp(a,b)           std::make_pair(a,b)
#define      pb(a)             std::push_back(a)
#define      each(it,s)        for(auto it = s.begin(); it != s.end(); ++it)
#define      rep(i, n)         for(int i = 0; i < (n); ++i)
#define      fill(a)           memset(a, 0, sizeof (a))
#define      sortA(v)          sort(v.begin(), v.end())
#define      sortD(v)          sort(v.begin(), v.end(), greater<auto>())
#define      X                 first
#define      Y                 second

typedef long long LL;
LL MOD = 1000000007;

int solve(vector<int>&v, int s){
	int n = v.size();
	int prev = v[0], ate = 0;
	for(int i = 1; i < n; ++i){
		if(v[i-1] - s > v[i]) return MOD;
		ate += min(v[i-1], s);
	}
	return ate;
}

int main()
{
	int T;
	cin >> T;
	for(int tc = 1; tc <= T; ++tc){
		int n;
		cin >> n;
		vector<int> v(n, 0);
		rep(i, n){
			cin >> v[i];
		}
		int ans1 = MOD, ans2 = 0;
		rep(speed, 10001){
			ans1 = min(ans1, solve(v, speed));
		}
		for(int i = 1; i < n; ++i){
			if(v[i] < v[i-1]) {
				ans2 += v[i] - v[i-1];
			}
		}
		ans2 = -ans2;
		swap(ans1, ans2);
		printf("Case #%d: %d %d\n",tc, ans1, ans2);
	}
	return 0;
}
