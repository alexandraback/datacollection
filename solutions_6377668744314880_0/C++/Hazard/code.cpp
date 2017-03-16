#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Pt{
	long long x,y;
} input[3030];
int ccw(Pt a, Pt b, Pt c){
    long long k = (a.x*b.y + b.x*c.y + c.x*a.y) - (b.x*a.y + c.x*b.y + a.x*c.y);
    if (k > 0) return 1;
    else if (k == 0) return 0;
    else return -1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T,N;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d",&N);
		memset(input,0,sizeof(input));
		int ans[3030]={0,};
		for(int i=0;i<N;i++){
			scanf("%lld%lld",&input[i].x,&input[i].y);
			ans[i]=N+5;
		}

		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(i==j) continue;
				int cnt=0,cnt2=0;
				for(int k=0;k<N;k++){
					if(j==k || i==k) continue;

					if(ccw(input[i],input[j],input[k])>0){
						cnt++;
					}
					if(ccw(input[i],input[j],input[k])<0){
						cnt2++;
					}
				}
				ans[i]=min(ans[i],cnt);
				ans[i]=min(ans[i],cnt2);
				ans[j]=min(ans[j],cnt);
				ans[j]=min(ans[j],cnt2);
			}
		}
		if(N==1){
			ans[0]=0;
		}
		printf("Case #%d:\n",t);
		for(int i=0;i<N;i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
