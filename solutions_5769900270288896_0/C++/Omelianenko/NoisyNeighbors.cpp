#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define y0 hi1
#define y1 hi2
#define ll long long
#define mp make_pair
#define pb push_back
#define sqr(a) (a)*(a)
#define ld long double
#define all(a) (a).begin(), (a).end()

using namespace std;
const int inf=2000000000;

int cnt(int x)
{
    int r=0;
    while(x>0)
    {
        r+=x&1;
        x>>=1;
    }
    return r;
}

int f(int n, int m, int mask)
{
    int a[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            a[i][j]=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            a[i][j]=mask&1;
            mask>>=1;
        }
    int ans=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(j+1<m&&a[i][j]&&a[i][j+1])ans++;
            if(i+1<n&&a[i][j]&&a[i+1][j])ans++;
        }
    return ans;
}

main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    cin>>T;
    for(int num=1; num<=T; num++)
    {
        cout<<"Case #"<<num<<": ";
        int n, m, x, ans=inf, mep;
        cin>>n>>m>>x;
        int mask=(1<<n*m);
        for(int i=0; i<mask; i++)
        {
            if(cnt(i)==x)
            {
                int y=f(n, m, i);
                if(y<ans)
                {
                    ans=y;
                    mep=i;
                }
            }
        }
        cout<<ans<<"\n";
    }
}
