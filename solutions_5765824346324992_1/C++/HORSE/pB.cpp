#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;

const int N_MAX = 1010;
ll bar[N_MAX];

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("pB_large.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int cnt = 1; cnt <= t; cnt ++){
		int n;
		ll ord;
		scanf("%d%lld", &n, &ord);
		for(int i = 0; i < n; i++)
			scanf("%lld", &bar[i]);
		ll lb = -1, ub = 10000000000000, sum;
		while(ub - lb > 1){
			ll mid = (ub + lb) / 2;
			sum = 0;
			for(int i = 0; i < n; i++)
				sum += mid / bar[i] + 1;
			(sum >= ord) ? ub = mid : lb = mid;
		}
		sum = 0;
		for(int i = 0; i < n; i++)
			sum += ub / bar[i] + 1;
		//printf("%lld %lld %lld\n", sum, ub, ord);
		vector<int> can;
		for(int i = 0; i < n; i++){
			if(ub % bar[i] == 0)
				can.push_back(i + 1);
		}
		printf("Case #%d: %d\n", cnt, can[can.size() - 1 - (int)(sum - ord)]);
	}
	return 0;
}
