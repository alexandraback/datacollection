#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T,N,B;
	long long input[1010],sum;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d%d",&N,&B);
		sum=0;
		for(int i=0;i<N;i++){
			scanf("%lld",&input[i]);
			sum+=input[i];
		}
		long long l=0,h=sum*B/N,m;
		long long k=0,nth=sum*B,ans=0;
		while(l<=h){
			m=(l+h)/2;
			k=0;
			for(int i=0;i<N;i++){
				k+=((m/input[i])+1);
			}
			if(k>=B){
				nth=min(nth,m);
				h=m-1;
			} else {
				l=m+1;
			}
		}
		int before=0;
		k=0;
		for(int i=0;i<N;i++){
				k+=(((nth-1)/input[i])+1);
		}
		for(int i=0;i<N;i++){
			if(nth%input[i]==0){
				k++;
				if(k==B){
					ans=i+1;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
