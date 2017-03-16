/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <assert.h>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define deb1(a) cout<<a<<endl;
#define deb2(a,b) cout<<a<<" "<<b<<endl
#define deb3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#define mt 210
#define mod

int main ()
{
    fop;
    int n,i,j,c,t=1,test;
    string a,b;
    vector< pair<char,int> >v1,v2;
    cin>>test;
    while(test--)
    {
        cin>>n;
        cin>>a>>b;
        clr(v1);
        clr(v2);
        c=1;
        for(i=1;i<sz(a);i++)
        {
            if(a[i]==a[i-1])
                c++;
            else
            {
                v1.pb(mp(a[i-1],c));
                c=1;
            }
        }
        v1.pb(mp(a[i-1],c));

        c=1;
        for(i=1;i<sz(b);i++)
        {
            if(b[i]==b[i-1])
                c++;
            else
            {
                v2.pb(mp(b[i-1],c));
                c=1;
            }
        }
        v2.pb(mp(b[i-1],c));

        if(sz(v1)!=sz(v2))
        {
            printf("Case #%d: Fegla Won\n",t++);
            continue;
        }


            c=0;
            bool flag=false;
            for(i=0;i<sz(v1);i++)
                {
                    c+=abs(v1[i].sc-v2[i].sc);
                    if(v1[i].fs != v2[i].fs)
                    {
                        flag=true;
                        break;
                    }
                }

            if(flag)
                printf("Case #%d: Fegla Won\n",t++);
            else
            printf("Case #%d: %d\n",t++,c);

    }
    return 0;
}
