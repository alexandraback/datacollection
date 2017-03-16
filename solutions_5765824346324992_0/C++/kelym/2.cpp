#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int tt;
	scanf("%d",&tt);
	for(int _t=1;_t<=tt;++_t){
		int n,m;
		long long ins[1000],tim=10000000,lo,hi;
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;++i){
			scanf("%lld",&ins[i]);
			if(ins[i]<tim) tim=ins[i];
		}
		if(n>m){
			printf("Case #%d: %d\n",_t,m);
			continue;
		}
		lo=1;
		hi=tim*(m-1);
		while(lo<hi){
			long long mid = (lo+hi)/2 , sum=0;
			
			for(int i=0;i<n;++i){
				sum += mid/ins[i];
				if(mid%ins[i]) sum+=1;
			}
			if(sum<m-1) lo=mid+1;
			else hi=mid;
		}
		long long pp[1000],get[1000],sum=0;
		for(int i=0;i<n;++i){
			get[i]=lo/ins[i];
			if(lo%ins[i]) get[i]+=1;
			sum+=get[i];
			pp[i]=get[i]*ins[i];
		}
		int res=0;
		if(sum<m){
			for(int i=1;i<n;++i){
				if(pp[i]<pp[res]) res = i;
			}
		}
		else{
			lo-=1;
			int s = 0;
			for(int i=0;i<n;++i){
				s+=lo/ins[i];
				if(lo%ins[i]) s+=1;
			}
			res = 0;
			while(s<m){
				if(lo%ins[res]==0) s+=1;
				res++;
			}
			res-=1;
		}
		printf("Case #%d: %d\n",_t,res+1);
	}
	return 0;
}