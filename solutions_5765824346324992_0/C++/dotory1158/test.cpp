#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll d[1050];
vector <int> tmp;
void print_ans(int t, int x) {
	printf("Case #%d: %d\n", t, x);
	return;
}
int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, B, T, i, j;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%d %d", &B, &N);
		for(i = 1; i <= B; i++) scanf("%d", &d[i]);
		if(N <= B) {
			print_ans(t, N);
			continue;
		}
		ll st = 1, en = (ll)100000*N, mi, sum, ans;
		while(st <= en) {
			mi = (st+en)/2;
			sum = 0;
			for(i = 1; i <= B; i++) sum += mi/d[i] + 1;
			if(sum >= N) {
				ans = mi;
				en = mi-1;
			}
			else st = mi+1;
		}
		sum = 0;
		for(i = 1; i <= B; i++) sum += (ans-1)/d[i]+1;
		sum = N-sum;
		for(i = 1; i <= B; i++) if(ans%d[i] == 0) tmp.push_back(i);
		print_ans(t,tmp[sum-1]);
		tmp.clear();
		continue;
	}
	return 0;
}