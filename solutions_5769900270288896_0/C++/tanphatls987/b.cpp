#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B-small-attempt1.in","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;

int test,n,m,x,sum[2],h[2][5];
int main(){
    INPUT;OUTPUT;
    scanf("%d",&test);
    FOR(T,1,test){
        scanf("%d%d%d",&n,&m,&x);
        sum[1]=sum[0]=0;
        FOR(i,1,n)
            FOR(j,1,m) sum[(i+j)%2]++;
        int sel=(sum[1]>sum[0]),ans=0;
        if (x>sum[sel]){
            x=n*m-x;
            memset(h,0,sizeof(h));
            FOR(i,1,n)
                FOR(j,1,m)
                    h[(i+j)%2][(i>1)+(i<n)+(j>1)+(j<m)]++;
            //FOR(j,0,1)
                //FOR(i,0,4) cout<<h[j][i]<<" \n"[i==4];
            ans=(m-1)*n+(n-1)*m;
            FOR(j,0,1){
                int cur=4,de=0,tmp=x;
                while (tmp){
                    while (!h[j][cur]) cur--;
                    h[j][cur]--,tmp--;
                    de+=cur;
                }
                //cout<<j<<" "<<de<<'\n';
                ans=min(ans,(m-1)*n+(n-1)*m-de);
            }
        }
        printf("Case #%d: %d\n",T,ans);
    }
}
