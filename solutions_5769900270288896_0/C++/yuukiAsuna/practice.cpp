#include<cstdio>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#define PB push_back
#define FT first
#define SD second
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int ,int> P;
const int maxn=10+1e5;

int main()
{
        freopen("B-small-attempt0.in","r",stdin);
        freopen("B-small-attempt0.out","w",stdout);
        int T,ca=0;
        scanf("%d",&T);
        while(T--){
                  int R,C,N,ans=1e5;
                  bool G[50][50];
                  scanf("%d%d%d",&R,&C,&N);
                  int en=(1<<(R*C));
                  for(int i=0;i<en;i++){
                           int cnt=0,tmp=i;
                           int t=0;
                           memset(G,0,sizeof(G));
                           while(tmp){
                                   if(tmp&1) cnt++,G[t/R][t%R]=1;
                                   tmp>>=1;
                                   t++;
                           }
                           if(cnt==N) {
                                   //cout<<i<<endl;
                                   int now=0;
                                   for(int j=0;j<C;j++)
                                             for(int k=0;k<R;k++)  if(G[j][k]){
                                                      //printf("%d ",G[j][k]);
                                                      if(G[j][k+1]) now++;
                                                      if(G[j+1][k]) now++;
                                             }
                                   ans=min(ans,now);

                           }
                  }

	printf("Case #%d: %d\n",++ca,ans);
        }

	return 0;
}
