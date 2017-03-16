#include<bits/stdc++.h>

using namespace std;

#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define all(x) x.begin(),x.end()
#define mset(x,v) memset(x, v, sizeof(x))
#define sz(x) (int)x.size()

int eval(int g[16][16],int r,int c)
{
    int i,j;
    int x = 0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(!g[i][j])
                continue;
            if(i+1<r && g[i+1][j])
                x++;
            if(j+1<c && g[i][j+1])
                x++;
        }
    }
    return x;
}

int solve(int r,int c,int n)
{
    int i,j,k;
    int m = r*c;
    int ret = INF;
    for(i=0;i<(1<<m);i++)
    {
        int cc = 0;
        int g[16][16] = {0};
        for(j=0;j<m;j++)
        {
            if(i&(1<<j))
            {
                cc++;
                int x = j/c , y = j%c;
                g[x][y] = 1;
            }
        }
        if(cc != n)
            continue;
        //dbg(i);
        /*dbg2(r,c);
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"-----------\n";
        dbg(eval(g,r,c))
        getchar();
        */
        ret = min(ret,eval(g,r,c));

    }
    return ret;
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int tc=1,t;
    scanf("%d",&t);
    while(t--)
    {
        int r,c,n;
        scanf("%d%d%d",&r,&c,&n);
        int ans = solve(r,c,n);
        printf("Case #%d: %d\n",tc++,ans);
    }
    return 0;
}

