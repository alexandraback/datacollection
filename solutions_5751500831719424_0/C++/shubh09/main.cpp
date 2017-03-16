#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					cin>>n
#define p(n)					cout<<n<<'\n'
#define sd(n)					int n;cin>>n;
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define mp(a,b)                                 make_pair(a,b)
#define ps(str)                                 cout<<str<<'\n'
#define pans(t,ans)                             do{cout<<"Case #"<<t<<": "<<ans<<endl;} while(0)

#define INF                                     INT_MAX
#define UINF                                    UINT_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX
#define PI 3.14159265358979323846

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<pair<int,int> > > TG;

int median(vi &arr)
{
    int n=sz(arr);
    sort(all(arr));
    if (n&1) return arr[n/2];
    else return (arr[n/2]+arr[n/2-1])/2;
}

int main()
{
    //File IO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    sd(T);
    int i,j,t;
    FOR(t,0,T)
    {
        sd(n);
        string str;
        vstr v;
        string temp;
        cin>>temp;
        int l=sz(temp);
        v.pb(temp);
        str.pb(temp[0]);
        FOR(i,1,l) if (temp[i]!=str[sz(str)-1]) str.pb(temp[i]);
        bool succ=true;
//        cout<<str<<endl;
        FOR(i,1,n)
        {
            string temp;
            cin>>temp;
            v.pb(temp);
            l=sz(temp);
            string str2;
            str2.pb(temp[0]);
            FOR(j,1,l) if (temp[j]!=str2[sz(str2)-1]) str2.pb(temp[j]);
            if (str!=str2) succ=false;
//            cout<<str2<<endl;
        }
        if (!succ)
        {
            pans(t+1,"Fegla Won");
            continue;
        }
        int n2=sz(str);
        int ans=0;
        vi cur(n,0);
        FOR(i,0,n2)
        {
            char c=str[i];
            vi arr(n,0);
            FOR(j,0,n)
            {
                while (cur[j]<sz(v[j])&&v[j][cur[j]]==c)
                {
                    cur[j]++;
                    arr[j]++;
                }
            }
            int med=median(arr);
//            cout<<c<<' '<<med<<endl;
            FOR(j,0,n) ans+=abs(med-arr[j]);
        }
        pans(t+1,ans);
    }
}
