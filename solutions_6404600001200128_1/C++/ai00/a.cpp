#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
int a[1001];
int main(){
	int t = 0, tt;
	for (scanf("%d ", &tt); t < tt; ++t){
		scanf("%d ", &n);
		for (int i = 0; i < n; ++i){
			scanf("%d ", &a[i]);
		}
		int ans1 = 0, ans2 = 0;
		for (int i = 0; i < n - 1; ++i){
			ans1 += max(0, a[i] - a[i + 1]);
		}
		int rate = 0;
		for (int i = 0; i < n - 1; ++i){
			rate = max(rate, a[i] - a[i + 1]);
		}
		for (int i = 0; i < n - 1; ++i){
			ans2 += min(a[i], rate);
		}
		printf("Case #%d: %d %d\n", t + 1, ans1, ans2);
	}
}