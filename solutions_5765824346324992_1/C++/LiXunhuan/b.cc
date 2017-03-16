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
		int b,n;
		scanf("%d%d",&b,&n);
		for(int i=0;i<b;i++){
			scanf("%d",x+i);
		}
		long long low=-1,high=123456789098765432;
		while(high-low>1){
			long long mid=(low+high)/2;
			long long ct=0;
			for(int i=0;i<b;i++){
				ct+=mid/x[i]+1;
			}
			if(ct>=n)high=mid;
			else low=mid;
		}
		printf("Case #%d:  ",cas);
		long long cnt=0;
		for(int i=0;i<b;i++)
			cnt+=low/x[i]+1;
		cnt=n-cnt;
		for(int i=0;i<b;i++){
			if(high%x[i]==0){
				cnt--;
				if(!cnt){
					printf("%d\n",i+1);
					break;
				}
			}
		}
	}

}
