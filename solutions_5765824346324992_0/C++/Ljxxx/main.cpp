#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int num[1010], n, m;

void input() {
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i ++) scanf("%d", &num[i]);
}

long long compute_served_cust(int x, int id) {
	long long tt = ((long long)x)*((long long)num[id]);

	long long res = 0;
	for(int i = id;i < n;i ++) {
		res += (tt + num[i]-1)/((long long)num[i]);
	}

	return res;
}

void solve() {
	for(int i = 0;i < n-1;i ++) {
		int low = 0, high = m, sol;
		while(low <= high) {
			int mid = (low + high)/2;
			long long cust = compute_served_cust(mid, i);
			if(cust >= m) {
				sol = mid;
				high = mid-1;
			}
			else low = mid+1;
		}

		long long cust = compute_served_cust(sol - 1, i);
		if(cust == m-1) {
			printf("%d\n", i+1);
			return ;
		}

		m -= sol;
	}

	printf("%d\n", n);
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int Case;
	scanf("%d", &Case);
	for(int cas = 1;cas <= Case;cas ++) {
		input();
		printf("Case #%d: ", cas);
		solve();
	}
}