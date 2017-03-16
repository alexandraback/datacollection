
// Author : Vivek Hamirwasia (viv001)
#include<bits/stdc++.h>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define LET(x,a) __typeof(a) x(a)
#define MP make_pair
#define tr(container , it) for(LET(it,container.begin) ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LLD long long
#define VI vector < int >
#define PII pair < int , int >
#define MAX 1000000000
#define gi(x) scanf("%d",&x)
//_____starts____here_______
bool P[20][20];
int main()
{
    int t;
    gi(t);
    int kase = 0;
    while(t--)
    {
        kase++;
        int r,c,n;
        gi(r);
        gi(c);
        gi(n);
        
        int val = r*c;

        int ans = INF;
        for(int i=0;i<(1<<val);i++)
        {
            if(__builtin_popcount(i)!=n)
                continue;

            memset(P,false,sizeof P);
            for(int j=0;j<val;j++)
            {
                if((1<<j)&i)
                {
                    int si = j/c;
                    int sj = j%c;
                    P[si][sj]=true;
                }
            }

            int cnt = 0;
            for(int k=0;k<r;k++)
                for(int l=0;l<c;l++)
                {
                    if(!P[k][l]) continue;
                    if(k+1<r && P[k+1][l]) cnt++;
                    if(l+1<c && P[k][l+1]) cnt++;
                }
           ans = min(ans,cnt);
        }
        cout<<"Case #"<<kase<<": "<<ans<<endl;
    }

    return 0;
}


