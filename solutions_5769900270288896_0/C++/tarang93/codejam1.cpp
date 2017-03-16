#include<vector>
#include<iostream>
#include<stdio.h>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<climits>
#include<sstream>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<bitset>

#define ll long long
#define FL(i,a,b) for(ll i=a;i<b;i++)
#define FOR(i,n) for(ll i=0;i<n;i++)
#define SORTF(x) sort(x.begin(),x.end(),func);
#define SORT(x) sort(x.begin(),x.end())
#define pb(x) push_back(x)
#define SET(v, val) memset(v, val, sizeof(v)) ;
#define RSORT(v) { SORT(v) ; REVERSE(v) ; }
#define ALL(v) v.begin(),v.end()
#define REVERSE(v) { reverse(ALL(v)) ; }
#define UNIQUE(v) unique((v).begin(), (v).end())
#define RUNIQUE(v) { SORT(v) ; (v).resize(UNIQUE(v) - (v).begin()) ; }
#define fill(x,n) memset(x,n,sizeof(x))
#define sl(x) scanf("%d",&x)
using namespace std;

ll di[20][20];
int main()
{
   
    ll t;
    cin >> t;
    ll ca = 1;
    while(t--)
    {   
        fill(di,0);
        ll r,c;
        cin >> r >> c;
        ll n;
        cin >> n;
        ll x = 0,x1 = 0;
        ll r1 = 1,c1 = 1;
        for(int i=0;i<n;i++)
        {
            di[r1][c1] = 1;
            cout << r1 << " " << c1 << endl;
            if(c1 + 2  == c+1)
            {
                r1 = (r1)%r + 1;
                    c1 = 1;
                
            }
            else if(c1+2 == c+2)
            {
                r1 = (r1)%r + 1;
                    c1 = 2;
                
            }
            else{
                c1+=2;
            }
        }
        ll ans = 0;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(di[i][j] && di[i-1][j]) ans++;
                if(di[i][j] && di[i][j+1]) ans++;
                if(di[i][j] && di[i+1][j]) ans++;
                if(di[i][j] && di[i][j-1]) ans++;
            }
        }
        cout << ans/2 << endl;
    }   


    return 0;
}