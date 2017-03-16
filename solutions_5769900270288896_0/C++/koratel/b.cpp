#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int INF = 1 << 30;
const double EPS = 1e-8;

int d[20][20];

void solve(int num)
{
    int r, c, n;
    cin>>r>>c>>n;
    if(c>r) swap(r,c);

    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++) d[i][j]=0;
    }

    int ans=INF;
    for(int mask=0;mask<(1<<(r*c));mask++)
    {
        int cur=0, sum=0;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                d[i][j]=((mask&(1<<cur))>0);
                sum+=d[i][j];
                cur++;
            }
        }
        if(sum!=n) continue;
        int meh=0;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(!d[i][j]) continue;
                meh+=d[i][j-1]+d[i][j+1]+d[i-1][j]+d[i+1][j];
            }
        }


        ans=min(ans,meh/2);
    }

    cout<<"Case #"<<num<<": "<<ans<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        solve(i);
    }
}

