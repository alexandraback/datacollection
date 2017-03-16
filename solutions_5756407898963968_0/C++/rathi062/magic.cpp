#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long
#define MX 1005
#define MOD 1000002013

#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)
#define inpd(x) scanf("%lf",&x)
#define inpll(x) scanf("%lld",&x)
#define getcx getchar_unlocked
/*inline void inp( int &n )
 {
 n=0;
 int ch=getcx();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
 n=n*sign;
 }*/


using namespace std;


int arr[4][4],sec[4][4];
int main()
{
    int t=0,w,cnt=1,n,m;
    
    inp(t);
    for(int test = 1;test <= t;test++)
    {
        inp(n);
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                inp(arr[i][j]);
        inp(m);
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                inp(sec[i][j]);
        
        int common=0,card;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                //cout<<"\narr = "<<arr[n][i]<<" sec = "<<sec[m][j];
                if(arr[n-1][i]==sec[m-1][j])
                {
                    common++;
                    card=arr[n-1][i];
                    //cout<<"\ncard found : "<<card;
                }
            }
        }
        if(common==1)
        printf("Case #%d: %d\n",test,card);
        else
        if(common>1)
        printf("Case #%d: Bad magician!\n",test);
        else
        printf("Case #%d: Volunteer cheated!\n",test);
        
    }
    return 0;
}