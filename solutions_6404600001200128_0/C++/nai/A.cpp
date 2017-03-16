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

typedef long long llint;
const int INF = 1001001001;
const llint INFll = 9008007006005004003ll;

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
		int N = in();
		vint data(N);
		rep(i,N) data[i] = in();
		
		int ans1 = 0;
		int mosteaten = 0;
		for (int i = 1; i < N; i++) {
			int eaten = data[i - 1] - data[i];
			if (eaten > 0) ans1 += eaten;
			if (eaten > mosteaten) mosteaten = eaten;
		}
		
		llint ans2 = 0;
		for (int i = 0; i < N - 1; i++) {
			ans2 += min(mosteaten, data[i]);
		}
		
		printf("Case #%d: %d %lld\n", t+1, ans1, ans2);
	}
	return 0;
}
