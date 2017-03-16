#include "iostream"
#include "cstring"
#include "cstdio"
using namespace std;
const int N = 1100;
int n;
int a[N];
int gao1()
{
	int ans = 0;
	for(int i = 2; i <= n; ++ i){
		if(a[i] < a[i - 1]){
			ans += a[i - 1] - a[i];
		}
	}
	return ans;
}
int gao2(){
	int ans = 0x3fffffff;
	for(int i = 0; i <= 10000; ++ i){
		int now = 0;
		for(int j = 2; j <= n; ++ j){
			if(a[j - 1] - i > a[j]){
				now = -1;
				break;
			}else{
				now += min(a[j - 1], i);
			}
		}
		if(now == -1) continue;
		ans = min(ans, now);
	}
	return ans;
}
int main(void)
{
	int g = 0, T;
	scanf("%d", &T);
	while(T --){
		printf("Case #%d: ", ++ g);
		scanf("%d ", &n);
		for(int i = 1; i <= n; ++ i){
			scanf("%d", &a[i]);
		}
		printf("%d %d\n", gao1(), gao2());
	}
	return 0;
}