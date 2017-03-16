#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
int x[1000];
int main(){
	int ca;
	scanf("%d",&ca);
	for(int cas=1;cas<=ca;cas++){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",x+i);
		}
		int ans1=0,ans2=0,mx=0;
		for(int i=1;i<n;i++){
			if(x[i-1]>x[i]){
				ans1+=x[i-1]-x[i];
				mx=max(mx,x[i-1]-x[i]);
			}
		}
		for(int i=0;i<n-1;i++)
			ans2+=min(mx,x[i]);
		printf("Case #%d: %d %d\n",cas,ans1,ans2);
	}

}
