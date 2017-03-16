//#define WYTE
#include<bits/stdc++.h>
#define X first
#define Y second
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define ALL(x) (x).begin(),(x).end()
#define INIT(x,y) memset((x),(y),sizeof(x))
#define PQ priority_queue
#define IT iterator
#define INF 1e9
#define EPS 1e-9
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,ii,n,m[1005],i,eat1,eat2,rate;
    cin>>t;
    for(ii=1;ii<=t;ii++)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>m[i];
        }
        eat1=0;
        for(i=1;i<n;i++)
        {
            eat1+=max(m[i-1]-m[i],0);
        }
        eat2=0;
        rate=0;
        for(i=1;i<n;i++)
        {
            rate=max(rate,max(m[i-1]-m[i],0));
        }
        for(i=0;i<n-1;i++)
        {
            eat2+=min(m[i],rate);
        }
        cout<<"Case #"<<ii<<": "<<eat1<<" "<<eat2<<"\n";
    }
}
