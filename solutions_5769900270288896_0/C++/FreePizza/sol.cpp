#include <bits/stdc++.h>
using namespace std;
int cnt[1 << 18];
long int R, C, N;
long int solve(long int i)
{
    int r,c,ans = 0;
    for(r=0;r<R;r++)
        for(c=0;c<C;c++)
        {
            if(c > 0 && (i & (1 << (r * C + c))) && (i & (1 << (r * C + c - 1))))
                ans++;
            if(r > 0 && (i & (1 << (r * C + c))) && (i & (1 << (r * C + c - C))))
                ans++;
        }
    return ans;
}
int main()
{
    freopen("B-small-attempt0","r",stdin);
freopen("output.out","w",stdout);
    long int i,j,t,ans;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>R>>C>>N;
        ans=R*C*N*100;
        for(j=1;j< (1 << (R * C));j++)
        {
            cnt[j]=cnt[j-(j & -j)]+1;
            if(cnt[j] == N)
                ans=min(ans,solve(j));
        }
        printf("Case #%d: %d\n", i, ans);
    }
}
