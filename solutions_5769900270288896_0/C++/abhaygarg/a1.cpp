#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define ll long long
#define mod 1000000007LL
#define pii pair<int,int>
#define pll pair<ll,ll>
map<ll,int>dp,visited;
//map< vector< vector<int> > , int>dp;
//map< vector< vector<int> > , int>visited;
int x1[2]={-1,1},r,c;
int dfs(ll v,int n)
{
    int i,j;
    //printf("%lld %d\n",v,n);
//    for(i=0;i<r;i++)
//    {
//        for(j=0;j<c;j++)
//            printf("%d ",v[i][j]);
//        printf("\n");
//    }
//    printf("%d\n",n);
    if(visited[v])
        return dp[v];
    if(n==0)
        return 0;
    dp[v]=1000000;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(!(v&(1LL<<(((ll)c*(ll)(r-i-1))+(ll)(c-j-1)))))
            {
//                vector<vector<int> >d;
//                for(int k=0; k<r; k++)
//                {
//                    vector<int>p;
//                    for(int l=0; l<c; l++)
//                        if(k==i&&l==j)
//                            p.pb(1);
//                        else
//                            p.pb(v[k][l]);
//                    d.pb(p);
//                }
                int s=0,x,y;
                for(int l=0; l<2; l++)
                {
                    x=i+x1[l];
                    y=j;
                    if(x>=0&&x<r&&y>=0&&y<c)
                        if(v&(1LL<<(((ll)c*(ll)(r-x-1))+(ll)(c-y-1))))
                            s++;
                }
                for(int l=0; l<2; l++)
                {
                    x=i;
                    y=j+x1[l];
                    if(x>=0&&x<r&&y>=0&&y<c)
                        if(v&(1LL<<(((ll)c*(ll)(r-x-1))+(ll)(c-y-1))))
                            s++;
                }
                ll d=v+(1LL<<(((ll)c*(ll)(r-i-1))+(ll)(c-j-1)));
                dp[v]=min(dp[v],s+dfs(d,n-1));
            }
        }
    }
    visited[v]=1;
    return dp[v];
}
int main()
{
    freopen("inp.in","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,k,ans,l,n,m,t,c1=1,x1[2]= {-1,1},x,y,s;
    scanf("%d",&t);
    //printf("%d\n",t);
    while(t--)
    {
        scanf("%d %d %d",&r,&c,&n);
        //printf("%d %d %d\n",r,c,n);
//        vector<vector<int> >d;
//        for(i=0;i<r;i++)
//        {
//            vector<int>p;
//            for(j=0;j<c;j++)
//                p.pb(0);
//            d.pb(p);
//        }
        ans=dfs(0LL,n);
        printf("Case #%d: %d\n",c1,ans);
        c1++;
        dp.clear();
        visited.clear();
    }
    return 0;
}

