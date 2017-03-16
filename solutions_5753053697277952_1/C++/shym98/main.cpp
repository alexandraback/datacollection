#pragma comment(linker,"/STACK:100000000000,100000000000")

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define D long double
#define pi pair<int,int>
#define F first
#define S second
#define forn(i,n) for (int(i)=0;(i)<(n);i++)
#define forr(i,x,y) for (int(i)=(x);(i)<=(y);i++)
#define ford(i,x,y) for (int(i)=(x);(i)>=(y);i--)
#define rev reverse
#define in insert
#define er erase
#define all(n) (n).begin(),(n).end()
#define graf vector<vector<pi> >
#define graf1 vector<vector<ll> >
#define sqr(a) (a)*(a)
#define file freopen("a.in","r",stdin);freopen("a.out","w",stdout);
#define y1 asdadasdasd

const int INF = 1e9;
const D cp = 2 * asin(1.0);
const D eps = 1e-9;
const ll mod = 1000000007;

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    //file;
    int T;
    cin>>T;
    forn(Q,T)
    {
        cout<<"Case #"<<Q+1<<": ";
        vector<pair<int,int> > res;
        int n;
        cin>>n;
        int a[100],all=0;
        forn(i,n)
            cin>>a[i],all+=a[i];
        while(1)
        {
            bool ok=false;
            forn(i,n)
            {
                if (a[i])
                {
                    bool ck = true;
                    forn(j,n)
                    {
                        if ((D)((i==j)?a[j]-1:a[j])/(D)(all-1)-0.5>0.000001) {ck=false;break;}
                    }
                    if (ck)
                    {
                        res.pb(mp(i,-1));
                        a[i]--;
                        ok=true;
                        all--;
                        break;
                    }
                }
            }
            if (!ok)
            {
                forn(i,n)
                    forr(j,i,n-1)
                    {
                        if (a[i] && a[j])
                        {
                            bool ck = true;
                            forn(k,n)
                            {
                                int e;
                                if (i==j && i==k) e=a[i]-2; else
                                if (i==k || j==k) e=a[k]-1; else
                                    e = a[k];
                                if ((D)(e)/(D)(all-1)-0.5>0.000001) {ck=false;break;}
                            }
                            if (ck)
                            {
                                res.pb(mp(i,j));
                                a[i]--;
                                a[j]--;
                                ok=true;
                                all-=2;
                                goto end;
                            }
                        }
                    }
            }
            end:if (all==0) break;
        }
        forn(i,res.size())
        {
            cout<<char(int('A')+res[i].F);
            if (res[i].S!=-1) cout<<char(int('A')+res[i].S);
            cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
