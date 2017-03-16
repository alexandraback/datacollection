/*
Farsid
BUET
CSE
10
*/

#define filer() freopen("far.in","r",stdin)
#define filew() freopen("far.in","w",stdout)

#include <set>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include <map>
#include<ctime>
#define SET(a, x) memset((a), (x), sizeof(a))
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define i64 ll
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define MAX
#define xx first
#define yy second
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<ll> VL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;

const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


template<class X>void debug(vector<X>&v){for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;}


int main()
{
    //filer();
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B_small.out","w",stdout);
    int i,j,k ,T,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        int R,C,N;
        cin>>R>>C>>N;
        int p=R*C,mask,bit,ans=inf,mx;
        mx=((1<<p)-1);
        for(mask=0;mask<=mx;mask++)
        {
            int cnt=0;
            for(i=0;i<p;i++)
            {
                bit=(1<<i);
                if(bit & mask)
                {
                    cnt++;
                }
            }
//            if(mask==63)
//            {
//                cout<<cnt<<endl;
//            }
            if(cnt!=N)continue;
            int nw=0;
            for(i=0;i<R;i++)
            {
                for(j=0;j<C;j++)
                {
                    if(i==0 && j==0)continue;
                    k=(i*C)+j;
                    bit=(1<<k);
                    if(!(mask & bit))continue;
                    if(i==0)
                    {
                        k=(i*C)+j-1;
                        bit=(1<<k);
                        if(mask & bit)
                        {
                            nw++;
                        }

                    }
                    else if(j==0)
                    {
                        k=((i-1)*C)+j;
                        bit=(1<<k);
                        if(mask & bit)
                        {
                            nw++;
                        }
                    }
                    else
                    {
                        k=(i*C)+j-1;
                        bit=(1<<k);
                        if(mask & bit)
                        {
                            nw++;
                        }

                        k=((i-1)*C)+j;
                        bit=(1<<k);
                        if(mask & bit)
                        {
                            nw++;
                        }
                    }
                }
            }
            ans=min(nw,ans);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
/*Test Cases


*/
