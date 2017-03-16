#include<cstdio>
int n,b,a[1010],ans,T;
int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&T);
	for(int test=1;test<=T;++test){
		scanf("%d%d",&b,&n);
		for(int i=1;i<=b;++i)scanf("%d",&a[i]);
		long long l=0,r=100000000000LL,mid;
		while(l<=r){
			mid=(l+r)/2;
			long long res=0;
			int count=0;
			for(int i=1;i<=b;++i){
				res+=(mid+a[i]-1)/a[i];
				if(mid%a[i]==0)++count;
			}
			if(res+b>=n){
				if(n>res&&res+count>=n){
					for(int i=1;i<=b;++i)
						if(mid%a[i]==0){
							--n;
							ans=i;
							if(n==res)break;
						}
					break;
				}
				if(res>=n)r=mid-1;
				else l=mid+1;
			}else l=mid+1;
		}
		printf("Case #%d: %d\n",test,ans);
	}
	return 0;
} 
