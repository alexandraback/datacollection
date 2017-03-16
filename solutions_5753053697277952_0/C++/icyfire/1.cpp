#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,char>
#define V(x) vector<x>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back

#define SORT(ls) sort(ls.begin(), ls.end())
#define DESC(ls) sort(ls.rbegin(), ls.rend());

#define FORLL(i,a,n) for(long long int i=(a); i<(n); ++i)
#define FORDLL(i,a,n) for(long long int i=(a);i>=(n);--i)
#define FOR(c, f, t) for(int c=f;c<t;c++)
#define FORD(c, f, t) for(int c=f;c>=t;c--)
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define memo(a,v) memset(a,v,sizeof(a))
#define CLR(a) memo(a,0)
#define SET(a) memo(a,-1)
#define M 1000000007
#define isactive(x,k) (x&(1<<k))

#define OIN(x) cin>>x
#define DIN(x, y) cin>>x>>y
#define TIN(x, y, z) cin>>x>>y>>z
#define FIN(w, x, y, z) cin>>w>>x>>y>>z

#define SOP(x) cout<<x<<"\n"
#define DOP(x, y) cout<<x<<" "<<y<<"\n"
#define TOP(x, y, z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define FOP(w, x, y, z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"

#define PRESENT(container, x) container.find(x) != container.end()
#define fi first
#define se second
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define MAX INT_MAX
#define MIN INT_MIN
#define DEBUG cout<<"hello\n";
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("1.in", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t=1,T;
    OIN(T);
    while(t<=T)
    {
        int n;
        OIN(n);
        set<pii> myset;
        int sum=0;
        FOR(i,0,n){
            int x;
            OIN(x);
            sum += x;
            pii p({x,'A'+i});
            myset.insert(p);
        }
        vector<string> res;
        while(!myset.empty()){
            pii p = *myset.rbegin();
            string str;
            str += p.se;
            myset.erase(p);
            sum--;
            p.fi--;
            if(p.fi>0){
                myset.insert(p);
            }
            if(!myset.empty()){
            pii pyt = *myset.rbegin();
            double d = (double)pyt.fi/sum;
            if(d-0.5 > 0){
                myset.erase(pyt);
                sum--;
                str+=pyt.se;
                pyt.fi--;
                if(pyt.fi > 0){
                    myset.insert(pyt);
                }
            }
            }
            res.pb(str);
        }
        cout<<"Case #"<<t<<": ";
        for(auto it : res)
            cout << it<<" ";
        cout<<endl;
        t++;
    }

   return 0;
}
