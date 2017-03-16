#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
typedef long long ll;
#define B 1234

int t;
ll n, b, m[B];
vector<int> ready;
int main() {
	freopen("b.in", "r", stdin); freopen("b.out", "w", stdout);
	scanf("%d", &t);
	fo(tc,1,t+1) {
		printf("Case #%d: ", tc);
		scanf("%lld %lld", &b, &n);
		fo(i,0,b) scanf("%lld", m+i);
		ll mi = 0, ma = 1e15, mid; char g = 0;
		while (!g) {
			mid = (mi+ma)/2;
			ll done = 0;
			ready.clear();
			fo(i,0,b) {
				done += mid/m[i] + 1;
				if (done > 1e15) break;
			}
			fo(i,0,b) if (mid % m[i] == 0) ready.push_back(i);
			if (done - ready.size() >= n) {
				ma = mid-1; continue;
			}
			if (done < n) {
				mi = mid+1; continue;
			}
			g = 1;
			int ind = n - (done - ready.size()) -1;
			sort(ready.begin(), ready.end());
			//printf("%lld\n", mid);
			printf("%d\n", ready[ind]+1);
		}
	}

	return 0;
}