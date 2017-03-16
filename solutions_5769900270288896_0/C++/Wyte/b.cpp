//#define WYTE
#include<bits/stdc++.h>
#define X first
#define Y second
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define ALL(x) (x).begin(),(x).end()
#define INIT(x,y) memset((x),(y),sizeof(x))
#define PQ priority_queue
#define IT iterator
#define INF 1e9
#define EPS 1e-9
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main()
{
    freopen("B-small-attempt0.in","rb",stdin);
    freopen("output.txt","wb",stdout);
    int t,ii,r,c,n,i,j,k,tb[20][20],cnt,ans,tmp;
    scanf("%d",&t);
    for(ii=1;ii<=t;ii++)
    {
        scanf("%d %d %d",&r,&c,&n);
        ans=INF;
        for(i=0;i<(1<<(r*c));i++)
        {
            INIT(tb,0);
            cnt=0;
            for(j=0;j<r*c;j++)
            {
                if(i&(1<<j))
                {
                    tb[j/c][j%c]=1;
                    cnt++;
                }
            }
            if(cnt==n)
            {
                tmp=0;
                for(j=0;j<r;j++)
                {
                    for(k=0;k<c;k++)
                    {
                        if(tb[j][k])
                        {
                            if(j-1>=0&&tb[j-1][k])tmp++;
                            if(k-1>=0&&tb[j][k-1])tmp++;
                        }
                    }
                }
                ans=min(ans,tmp);
            }
        }
        printf("Case #%d: %d\n",ii,ans);
    }
}
