#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxN (1005)
using namespace std;

int N,a[maxN];

int main(){
	freopen("i.txt","r",stdin);
	int T;
	scanf("%d",&T);
	for (int testcase=1;T--;testcase++){
		printf("Case #%d: ",testcase);
		scanf("%d",&N);
		for (int i=0;i<N;i++) scanf("%d",&a[i]);
		int ans1=0,ans2=0;
		int max_rate=0;
		for (int i=0;i<N-1;i++){
			if (a[i]>a[i+1]){ 
				ans1+=a[i]-a[i+1];
				int d=a[i]-a[i+1];
				int tmp=d;
				if (tmp>max_rate)
					max_rate=tmp;
			}
		}
		for (int i=0;i<N-1;i++){
			ans2+=min(max_rate,a[i]);
		}
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
