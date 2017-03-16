#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using std::vector;
using std::pair;
using std::make_pair;
using std::sort;
int main(void){
	int t,hh;
	scanf("%d",&t);
	for(hh=1;hh<=t;hh++){
		int n;
		int s[1005];
		int i;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		  scanf("%d",&s[i]);
		int ans1=0,max=0,ans2=0;
		for(i=1;i<n;i++){
		  if(s[i]<s[i-1]) ans1+=s[i-1]-s[i];
		  if(max<s[i-1]-s[i]) max=s[i-1]-s[i];
		}
	//	printf("_%d\n",max);
		for(i=0;i<n-1;i++){
			if(s[i]<max) ans2+=s[i];
			else ans2+=max;
		}
		printf("Case #%d: %d %d\n",hh,ans1,ans2);
	}
	return 0;
}

