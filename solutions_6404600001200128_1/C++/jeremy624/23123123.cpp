#include <cstdio>
#include <algorithm>
#include <cmath>
int tn,n,m,i,a[1005];
using namespace std;
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("test123.txt", "w", stdout);
	scanf("%d", &tn);
	for(int w = 1; w <= tn; w++){
		scanf("%d", &n);
		int ans = 0;
		int ans1 = 0;
		for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
		double rate = 0;
		for(i = 0; i < n - 1; i++){
			if(a[i] > a[i + 1]){
			ans+= (a[i] - a[i + 1]);
			rate = max(rate, (a[i] - a[i + 1]) * 1.0 / (10 * 1.0));
			}
		}
			for(i = 0; i < n - 1; i ++){
			int g = min((int)(rate * 10), a[i]);
			ans1+= g;
		} 
		printf("Case #%d: %d %d\n", w,ans, ans1);
	}
}
