#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;
const int N = 1005;
int n,a[N];
void solve(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	int ans1=0,ans2=0;
	for(int i=1;i<n;i++){
		ans1+=max(0,a[i-1]-a[i]);
	}
	int ma=0;
	for(int i=0;i<n-1;i++)ma=max(ma,a[i]-a[i+1]);
	for(int i=0;i<n-1;i++){
		if(a[i]<=ma){
			ans2+=a[i];
		}else ans2+=ma;
	}
	printf("%d %d\n",ans1,ans2);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		printf("Case #%d: ",cas);
		solve();
	}
	return 0;
}
