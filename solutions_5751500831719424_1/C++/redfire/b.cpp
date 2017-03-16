/* @author Ishita Gupta*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define vi vector<int>
#define vvi vector< vi >
#define vs vector<string>
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define fori(s,e) for(int i=s;i<=e;i++)
#define forj(s,e) for(int j=s;j<=e;j++)
#define fork(s,e) for(k=s;k<=e;k++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define ull unsigned long long
#define ll long long
#define imax INT_MAX
#define imin INT_MIN
#define mem(x,y) memset(x,y,sizeof(x));
#define pii pair<int,int>
#define aa first
#define bb second
using namespace std;
vector<pair<char,int> > arr[102];
int main()
{
    ios::sync_with_stdio ( false );
    int t,i,j,k,m,n,x,y;
     freopen ( "A-large.in","r",stdin );
     freopen ( "A-large.txt","w",stdout );
    // cout<<remoovedup("ishhhhiiiiiita");
    cin>>t;
    rep ( T,1,t )
    {
        cin>>n;
        int ans=0;
        fori ( 0,n-1 )
        {
            string s;
            cin>>s;
            int len=s.size();
            j=0;
            while ( j<len )
            {
                char c=s[j];
                int count=0;
                while ( j<len-1 && s[j]==s[j+1] )
                {
                    count++;
                    j++;
                }
                arr[i].pb ( mp ( c,count ) );
                j++;
            }
        }
        int chars=arr[0].size(),flag=0;
        fori ( 1,n-1 )
        {
            if ( arr[i].size() !=chars )
            {
                flag=-1;
                break;
            }
            forj ( 0,chars-1 )
            {
                if ( arr[i][j].aa!=arr[0][j].aa )
                {
                    flag=-1;
                    break;
                }
                else ans+=abs(arr[i][j].bb-arr[0][j].bb);
            }
            if(flag==-1) break;
        }
        printf ( "Case #%d: ",T );
        if(flag==-1) printf("Fegla Won\n");
        else
        {
            ans=0;
            forj(0,chars-1)
            {
                vi v;
                fori(0,n-1)
                {
                    v.pb(arr[i][j].bb);
                }
                sort(v.begin(),v.end());
                int med=v[n/2];
                fori(0,n-1) ans+=abs(arr[i][j].bb-med);
            }
            printf("%d\n",ans);
        }
        fori ( 0,n-1 ) arr[i].clear();

    }
    return 0;
}

