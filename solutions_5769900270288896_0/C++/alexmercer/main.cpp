#define FROM_FILE
#define TO_FILE

//-Wl,--stack,52800000
#include <bits/stdc++.h>

using namespace std;

#define foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define All(n) (n).begin(), (n).end()

typedef long long int lli;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef vector<int> vi;

#ifdef FROM_FILE
void* __VERY__LONG__FROM=freopen("in.txt","r",stdin);
#endif

#ifdef TO_FILE
void* __VERY__LONG__TO=freopen("out.txt","w",stdout);
#endif

const int MAXN=100;
//const int MOD=1000*1000*1000 + 7;
//const lli INF=1000000000000000000ll;
int ans[MAXN][MAXN];
int t[20][20];
int main()
{
	ios::sync_with_stdio(false);
	memset(ans,-1,sizeof ans);
	int tt;
	cin>>tt;
	for(int _z=1;_z<=tt;_z++)
	{
        int r,c,n;
        cin>>r>>c>>n;
        int bst=10000;
        if(ans[r][c]==-1)
        {

            for(int x=0;x<(1<<(r*c));x++)
            {
                if(__builtin_popcount(x)!=n)
                    continue;
                memset(t,0,sizeof t);
                for(int i=0;i<18;i++)
                    if((1<<i)&x)
                        t[(i/r) + 1][(i%r) + 1]=1;
                int sm=0;
                const int dx[]={-1,0,1,0};
                const int dy[]={0,-1,0,1};
                for(int i=1;i<=c;i++)
                    for(int j=1;j<=r;j++)
                        for(int k=0;k<4;k++)
                            if(t[i][j] && t[i+dx[k]][j+dy[k]])
                                sm++;
                bst=min(bst,sm);

            }
//            ans[r][c]=bst/2;
        }
        printf("Case #%d: %d\n",_z,bst/2);
	}
    return 0;
}
