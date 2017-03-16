#include "iostream"
#include "cstring"
#include "cstdio"
using namespace std;
typedef long long ll;
const int N = 1010;
int a[N];
ll gao(ll m, int b)
{
	ll sum = 0;
	for(int i = 1; i <= b; ++ i){
		sum += (m + a[i] - 1) / a[i];
	}
	return sum;
}
int main(void)
{
	int g = 0, T;
	int b;
	ll n;
	scanf("%d", &T);
	while(T--){
		printf("Case #%d: ", ++g);
		scanf("%d %lld", &b, &n);
		for(int i = 1; i <= b; ++ i){
			scanf("%d", &a[i]);
		}
		ll l = 0, r = (ll)n * 1000000;
		while(l < r){
			ll m = (l + r + 1) / 2;
			ll sum = gao(m, b);
			if(sum < n){
				l = m;
			}else{
				r = m - 1;
			}
		}
		ll count = n - gao(l, b);
		for(int i = 1; i <= b; ++i){
			if(l % a[i] == 0){
				count --;
				if(count == 0){
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}