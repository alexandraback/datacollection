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
		int b;
		long long n;
		scanf("%d%lld",&b,&n);
		int i;
		int s[1005];
		for(i=0;i<b;i++)
		  scanf("%d",&s[i]);
		long long int l=0,r=100000000000000LL;
		while(l<=r){
			long long int mid=(l+r)/2;
			long long int sum=0;
			for(i=0;i<b;i++){
			  sum+=mid/s[i];
			  if(mid%s[i]) sum++;
		    }
		//    printf("  %lld %lld\n",mid,sum);
			if(sum>=n) r=mid-1;
			else l=mid+1;
		}
		long long int tt=r;
		long long int tot=0;
		for(i=0;i<b;i++){
		  tot+=tt/s[i];
		  if(tt%s[i]) tot++;
	    }
	//	printf("%lld %lld\n",tt,tot);
		for(i=0;i<b;i++){
		  if(tt%s[i]==0) tot++;
		  if(tot==n) break;
	    }
	    int ans=i%b+1;
	    printf("Case #%d: %d\n",hh,ans);    
	}
	return 0;
}

