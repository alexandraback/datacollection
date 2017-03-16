#include<bits/stdc++.h>
#define scf scanf
#define ptf printf
#define forp(i,j,k) for(int i=j;i<k;i++)
#define form(i,j,k) for(int i=j;i>k;i--)
#define sz(x) (int)x.size()
#define pb push_back
#define fst first
#define scd second
#define m_p make_pair
#define pct __builtin_popcount
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int T;
    scf("%d",&T);
    int R,C,n;
    forp(tcnt,0,T)
    {
        scf("%d%d%d",&R,&C,&n);
        int ans=R*C*4,tans;
        forp(st,0,1<<(R*C))
        {
            if(pct(st)==n)
            {
                tans=0;
                forp(i,0,R)
                    forp(j,0,C)
                    {
                        if(i+1<R&&(st&(1<<(i*C+j)))&&(st&(1<<(i*C+j+C))))tans++;
                        if(j+1<C&&(st&(1<<(i*C+j)))&&(st&(1<<(i*C+j+1))))tans++;
                    }
                ans=min(ans,tans);
            }
        }
        ptf("Case #%d: %d\n",tcnt+1,ans);
    }
    return 0;
}
