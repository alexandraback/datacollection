#include<bits/stdc++.h>

using namespace std;

// Input macros
#define s(n)                        scanf("%d",&n)
#define _sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount

// Useful container manipulation / traversal macros
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
#define f                           first
#define sc                          second

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str() // converting number (x) to string
#define SST(x) atoi(x) // converting a char array x to number

// Some common useful functions
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> pp;
typedef vector<string> VS;

#define fr(i,s,n)    for(int i=s;i<(n);++i)
#define MOD 1000000007

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

int f(string s1,string s2)
{
    int cost=0;

    vector<pp>a,b;

    int tmp=1;
    for(int i=1;i<s1.length();++i)
    {
        if(s1[i]==s1[i-1])tmp++;
        else
        {

            a.pb(pp(s1[i-1],tmp));
            tmp=1;
        }
    }

    a.pb(pp(s1[s1.length()-1],tmp));

    tmp=1;
    for(int i=1;i<s2.length();++i)
    {

        if(s2[i]==s2[i-1])tmp++;
        else
        {

            b.pb(pp(s2[i-1],tmp));
            tmp=1;
        }
    }
    b.pb(pp(s2[s2.length()-1],tmp));



     cout<<s1<<" "<<s2<<" "<<cost<<endl;
    for(int i=0;i<a.size();++i)cout<<a[i].f<<" "<<a[i].sc<<endl;
    for(int i=0;i<b.size();++i)cout<<b[i].f<<" "<<b[i].sc<<endl;

     if(a.size()!=b.size())return 1e6;

    cost=0;
    for(int i=0;i<a.size();++i)
    {
        if(a[i].f!=b[i].f)return 1e6;
        cost+=abs(a[i].sc-b[i].sc);
    }

     cout<<s1<<" "<<s2<<" "<<cost<<endl;

    return cost;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    freopen("op.txt", "w", stdout);
#endif

    int T;
    s(T);

    for(int t=1;t<=T;++t)
    {
        int n;
        s(n);
        VS a;

        string s;
        for(int i=0;i<n;++i)
        {
            cin>>s;
            a.pb(s);
        }

        vector<vector<pp> >b;
        for(int i=0;i<n;++i)
        {
            vector<pp>b1;
            int tmp=1;
            for(int j=1;j<a[i].length();++j)
            {
                if(a[i][j]==a[i][j-1])tmp++;
                else
                {
                    b1.pb(pp(a[i][j-1],tmp));
                    tmp=1;
                }
            }

            b1.pb(pp(a[i][a[i].length()-1],tmp));
            b.pb(b1);
        }

        int f=1;
        for(int i=1;i<b.size();++i)
        {
            if(b[i].size()!=b[0].size())
            {
                f=0;
                break;
            }
            for(int j=0;j<b[0].size();++j)
            {
                if(b[0][j].f!=b[i][j].f)
                {
                    f=0;
                    break;
                }
            }
        }

        int cost=0;
        if(f)
        {
            int m1=b[0].size();
            for(int i=0;i<m1;++i)
            {
                int m=INF;
                int M=-INF;

                for(int j=0;j<n;++j)
                {
                    m=min(m,b[j][i].sc);
                    M=max(M,b[j][i].sc);
                }

                int ans=INF;
                for(int j=m;j<=M;++j)
                {
                    int tmp=0;
                    for(int k=0;k<n;++k)
                    {
                        tmp+=abs(b[k][i].sc-j);
                    }
                    ans=min(ans,tmp);
                }
                cost+=ans;
            }
        }

        if(f)cout<<"Case #"<<t<<": "<<cost<<endl;
        else cout<<"Case #"<<t<<": "<<"Fegla Won\n";

    }

     return 0;
}

