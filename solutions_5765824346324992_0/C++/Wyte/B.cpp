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
    int t,ii,b,n,m[1005],i;
    ll f,l,mid,cnt,cnt_,ans;
    cin>>t;
    for(ii=1;ii<=t;ii++)
    {
        cin>>b>>n;
        for(i=0;i<b;i++)
        {
            cin>>m[i];
        }
        f=0;
        l=1e14;
        while(f<=l)
        {
            mid=(f+l)/2;
            cnt=0;
            for(i=0;i<b;i++)
            {
                cnt+=mid/m[i]+1;
            }
            if(cnt>=n)
            {
                cnt_=cnt;
                for(i=0;i<b;i++)
                {
                    if(mid%m[i]==0)
                    {
                        cnt_--;
                    }
                }
                for(i=0;i<b;i++)
                {
                    if(mid%m[i]==0)
                    {
                        cnt_++;
                        if(cnt_>=n)
                        {
                            ans=i+1;
                            break;
                        }
                    }
                }
                l=mid-1;
            }
            else
            {
                f=mid+1;
            }
        }
        cout<<"Case #"<<ii<<": "<<ans<<"\n";
    }
}
