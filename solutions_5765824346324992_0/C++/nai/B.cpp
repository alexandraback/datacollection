#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define FOR(i,c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

#define pr(x) do{cout << (#x) << " = " << (x) << endl;}while(0)
#define pri(x,i) do{cout << (#x) << "[" << i << "] = " << (x[i]) << endl;}while(0)
#define pra(x,n) rep(__i,n) pri(x,__i);
#define prar(x,b,e) repr(__i,b,e) pri(x,__i);

typedef long long ll;
const int INF = 1001001001;
const ll INFll = 9008007006005004003ll;
typedef long double ldouble;

typedef pair<int, int> pint;
typedef vector<int> vint;

int in() {
	int a;
	scanf("%d ", &a);
	return a;
}

int main() {
	int T = in();
	for (int t = 0; t < T; t++) {
		int B = in();
		int N = in();
		vint data(B);
		ldouble v = 0;
		rep(i,B) {
			data[i] = in();
			v += (ldouble)1. / data[i];
		}
		
		if (N <= B) {
			printf("Case #%d: %d\n", t+1, N);
			continue;
		}
		
		ll tm = (ll)(N / v);
		ll left = max(0ll, tm - 100);
		ll right = tm + 123456;
		// (left, right]
		for (int i = 0; i < 50; i++) {
			ll middle = (left + right) / 2;
			ll done = 0;
			rep(k, B) {
				done += middle / data[k] + 1;
			}
			if (done < N) left = middle;
			else right = middle;
		}
		ll done = 0;
		rep(k,B) done += right / data[k] + 1;
		ll ind = done - N;
		int ans = 0;
		for (int k = B-1; k >= 0; k--) {
			if (right % data[k] == 0) {
				if (ind == 0) {
					ans = k;
					break;
				}
				ind--;
			}
		}
		
		printf("Case #%d: %d\n", t+1, ans+1);
	}
	return 0;
}
