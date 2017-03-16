#include<stdio.h>
#include<vector>
#define INF 1000000000000000LL
using namespace std;
int d[1000];

int main(){
	int dn;
	scanf("%d",&dn);
	for(int di=0;di<dn;di++){
		int n,m,i;
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)scanf("%d",&d[i]);
		long long l=0,r=INF;
		while(r-l>1){
			long long mid=(l+r)/2;
			long long s=0;
			for(i=0;i<n;i++)s+=(mid-1)/d[i]+1;
			if(s<m)l=mid;
			else r=mid;
		}
		int s=0;
		if(l>0){
			for(i=0;i<n;i++)s+=(l-1)/d[i]+1;
		}
		vector<int> fr;
		for(i=0;i<n;i++)if(l%d[i]==0)fr.push_back(i);
		printf("Case #%d: %d\n",di+1,fr[m-s-1]+1);
	}
	return 0;
}