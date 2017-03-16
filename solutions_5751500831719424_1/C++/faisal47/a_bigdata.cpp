/// "All the praises be to Allah, the Lord of the 'Alamin (worlds i.e. mankind, jinns and all that exists)"///

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
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

#define mt 110
#define mod

int main ()
{
    fop;
    int i,j,n,test,t=1,c,matra;
    string arr[mt];
    bool flag;
    vec_<pair<char,int> >v[mt];
    cin>>test;
    while(test--)
    {
        flag=false;
        cin>>n;

        for(i=0; i<n; i++)
        {
            cin>>arr[i];
            clr(v[i]);

            c=1;

            for(j=1; j<sz(arr[i]); j++)
            {
                if(arr[i][j] != arr[i][j-1])
                {
                    v[i].pb(mp(arr[i][j-1],c));
                    c=1;
                }
                else
                    c++;
            }
            v[i].pb(mp(arr[i][j-1],c));

            if(!i)
            {
                matra=sz(v[i]);
                continue;
            }

            if(!flag)
            {
                if(matra != sz(v[i]))
                {
                    //cout<<"hello";
                    flag=true;
                    continue;
                }
            }
        }

        c=0;
        char pre;
        for(i=0; i<sz(v[0]); i++)
        {
            if(flag)
                break;

            pre=v[0][i].fs;
            if(!flag)
            {
                for(j=1; j<n; j++)
                    if(v[j][i].fs != pre)
                    {
                        flag=true;
                        break;
                    }
            }
        }

        vec_<int>emne;
        int mid;

        if(flag)
        {
            printf("Case #%d: Fegla Won\n",t++);
        }
        else
        {
            int ans=0;
            for(i=0;i<sz(v[0]);i++)
            {
                clr(emne);
                for(j=0;j<n;j++)
                {
                    emne.pb(v[j][i].sc);
                }
                sort(all(emne));
                if(sz(emne) & 1)
                {
                    mid=emne[sz(emne)/2];
                }
                else
                {
                    mid=emne[sz(emne)/2];
                    mid+=emne[(sz(emne)/2)-1];
                    mid/=2;
                }
                for(j=0;j<sz(emne);j++)
                    {
                        ans+=abs(emne[j]-mid);
                       // cout<<emne[j]<<endl;
                    }
            }
            printf("Case #%d: %d\n",t++,ans);
        }

    }
    return 0;
}
