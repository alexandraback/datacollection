#include <bits/stdc++.h>
using namespace std;
#define MEM(a) memset(a,0,sizeof(a))
#define rp(i,a,n) for ( i=a;i<n;i++)
#define pr(i,a,n) for ( i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define IT(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define MAX 105000
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<ll> vll;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int dr[8] = {1,1,0,-1,-1,-1, 0, 1};
int dc[8] = {0,1,1, 1, 0,-1,-1,-1};
int dh[4] = {0, 1, 0, -1};
int dv[4] = {-1, 0, 1, 0};
int p[2000];
void solve(int yy)
{
    int n; cin>>n;
    MEM(p);
    int i;rp(i,0,n) cin>>p[i];
    vector <string> v;
    int sm=0; rp(i,0,n) sm+=p[i];
    cout<<"Case #"<<yy<<":";
    while(sm)
    {
        int m1=0;int i1=-1;int i2=-1;
        rp(i,0,n)
        {
            if(p[i]>m1) {m1=p[i];i1=i;}
        }
        rp(i,0,n)
        {
            if(p[i]==m1&&i!=i1) i2=i;
        }
        if(i1==-1) break;
        if(i2==-1)
        {
            unsigned char q=('A'+i1);
            cout<<" "<<q;
            p[i1]--;
            sm--;
        }
        else
        {
unsigned char q1=('A'+i1);unsigned char q2=('A'+i2);
p[i1]--;p[i2]--;
sm-=2;
if(sm==1)
{
    cout<<" "<<q1;
    rp(i,0,n) if(p[i]) break;
    unsigned char q3='A'+i;
    cout<<" "<<q2<<q3;
    cout<<endl;
    return ;
}
cout<<" "<<q1<<q2;
        }
    }
        cout<<endl;


}
int main()
{
  freopen("in.in","r",stdin);
  freopen("out.txt","w",stdout);
    int t,y;cin>>t;
    rp(y,1,t+1) solve(y);
    return 0;
}
