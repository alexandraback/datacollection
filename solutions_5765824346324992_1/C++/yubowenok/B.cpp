#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const ll INF = (ll)1E15;
#define MAXN 100005

int B;
ll N, x[MAXN];
int main(){
	int cs;
	cin >> cs;
	REP(csn, 1, cs + 1){
		printf("Case #%d: ", csn);
		cin >> B >> N;
		REP(i, 0, B) cin >> x[i];
		ll l = 0, r = INF;
		while (l <= r){
			ll m = (l + r) / 2;
			ll take = 0;
			REP(i, 0, B){
				take += m / x[i] + 1;
			}
			if (take < N) {
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		ll t = l;
		int ans;
		if (t == 0) ans = N - 1;
		else {
			ll bef = 0;
			VI cand;
			REP(i, 0, B){
				if (t % x[i] == 0)
					cand.push_back(i);
				bef += (t - 1) / x[i] + 1;
			}
			ans = cand[N - bef - 1];
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}