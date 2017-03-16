/*
 	Beautiful Codes are MUCH better than 'Shorter' ones !
user  : triveni
date  : 18/04/2015
time  : 07:39:54
*/
#include <bits/stdc++.h>

using namespace std;

#define      pii               std::pair<LL,LL>
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

LL getTime(vector<int> & v, LL N){
	int B = v.size();
	LL l = 0, r = MOD * 1000000LL, mid;
	while(r - l > 1){
		mid = (l + r) / 2LL;
		LL x = 0, dx = 0;
		rep(i, B) {
			x += mid / v[i];
			dx += ((mid % v[i]) > 0);
		}
		if(x >= N) r = mid;
		else if(x + dx < N) l = mid;
		else return mid;
	}

	LL x = 0, dx = 0;
	mid = r;
	rep(i, B) {
		x += mid / v[i];
		dx += ((mid % v[i]) > 0);
	}
	if(x < N  and x + dx >= N) return mid;

	mid = l;
	x = 0, dx = 0;
	rep(i, B) {
		x += mid / v[i];
		dx += ((mid % v[i]) > 0);
	}
	if(x < N  and x + dx >= N) return mid;

	mid = mid + 1;
	x = 0, dx = 0;
	rep(i, B) {
		x += mid / v[i];
		dx += ((mid % v[i]) > 0);
	}
	if(x >= N)	return -mid+1;
	return MOD;
}

int main()
{
	int T;
	cin >> T;
	for(int tc = 1; tc <= T; ++tc){
		int B, N;
		cin >> B >> N;
		vector<int> v(B);
		rep(i, B) cin >> v[i];

		LL t = getTime(v, N);
		if(t <= 0){
			t = -t;
			vector<pii> vv;
			LL x = 0;
			rep(i, B){
				x += t / v[i];
				vv.push_back({t - t % v[i], i});
			}
			int idx = N  -x - 1;
			assert(idx >= 0 and idx < B);
			sort(vv.begin(), vv.end());
			idx = vv[idx].Y + 1;
			printf("Case #%d: %d\n",tc, idx);
			continue;
		}
		LL x = 0;
		vector<pii> vv;
		rep(i, B){
			x += t / v[i];
			if(t % v[i] > 0){
				vv.push_back({t - t%v[i], i});
			}
		}
		int idx = N - x - 1;
		assert(idx >= 0 and idx < B);
		sort(vv.begin(), vv.end());
		idx = vv[idx].Y + 1;
		printf("Case #%d: %d\n",tc, idx);
	}
	return 0;
}
