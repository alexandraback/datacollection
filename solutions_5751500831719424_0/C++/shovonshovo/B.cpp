#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<fstream>
#include<sstream>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<utility>
#include<climits>
#include<iomanip>
#include<ctime>
#include<complex>
#include<set>

using namespace std;


#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf INT_MAX/3
#define INF INT_MAX/3
#define PB push_back
#define pb push_back
#define MP make_pair
#define mp make_pair
#define ALL(a) (a).begin(),(a).end()
#define all(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define PII pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define debug(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in.txt","r",stdin)
#define OUTFILE()freopen("out.txt","w",stdout)
#define in scanf
#define out printf
#define LL long long
#define ll long long
#define ULL unsigned long long
#define ull unsigned long long
#define eps 1e-14
#define MOD 1000000007


//TYO conversion
template<typename T>inline string toString(T a)
{
    ostringstream os("");
    os<<a;
    return os.str();
}
template<typename T>inline ll toLong(T a)
{
    ll res;
    istringstream os(a);
    os>>res;
    return res;
}
//MATHEMATICS
template<typename T>inline T  S(T a)
{
    return a*a;
}
template<typename T>inline T gcd(T a, T b)
{
    if (b == 0)return a;
    else return gcd(b, a % b);
}
template<typename T>inline ull bigmod(T a, T b, T m)
{
    if (b == 0)return 1;
    else if (b % 2 == 0)return S(bigmod(a, b / 2, m)) % m;
    else return (a % m*bigmod(a, b - 1, m)) % m;
}
template<typename T>inline VS parse(T str)
{
    VS res;
    string s;
    istringstream os(str);
    while(os>>s)res.pb(s);
    return res;
}
template<typename T>inline ull  dist(T A,T B)
{
    ull res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    return res;
}
template<typename T>inline double cosAngle(T a,T b,T c)
{
    double res=a*a+b*b-c*c;
    res=res/(2*a*b);
    res=acos(res);
    return res;
}
template<typename T>inline T power(T base,int po)
{
    T res=1;
    if(base==0)return 0;
    FOR(i,0,po)res*=base;
    return res;
}
//BIT
template<typename T>inline bool isOn(T mask,T pos)
{
    return mask&(1<<pos);
}
template<typename T>inline int Off(T mask,T pos)
{
    return mask^(1<<pos);
}
template<typename T>inline int On(T mask,T pos)
{
    return mask|(1<<pos);
}

//node * root =new node(0,n-1);

int mat[105][105];
vector<char>v[105];
VI save[105],tmp[105];

bool okey(int x, int y)
{
    if(v[x].size()!=v[y].size())return false;

    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=v[y][i])return false;
    }
    return true;
}

int main()
{

    INFILE();
    OUTFILE();

    int ks,cas;
    int i,j,k,n;
    cin>>ks;

    bool stat;
    for(cas=1; cas<=ks; cas++)
    {
        stat=1;
        scanf("%d",&n);
        for(i=0; i<=100; i++){
            v[i].clear();
            save[i].clear();
            tmp[i].clear();

        }
        string str;



        for(i=0; i<n; i++)
        {
            cin>>str;
            char ch='*';
            int cnt=0;
            int idx=0;
            for(j=0; j<str.length(); j++)
            {
                if(str[j]==ch)
                {
                    cnt++;
                }
                else
                {
                    if(j)
                    {

                        save[idx].PB(cnt);
                        v[i].PB(ch);
                        ++idx;

                    }
                    cnt=1;
                    ch=str[j];
                }
            }
            save[idx].PB(cnt);
            v[i].PB(ch);
        }



    cout<<"Case #"<<cas<<": ";
        for(i=1;i<n;i++)
        {
            if(!okey(i,i-1))stat=0;
        }



        int sz=v[0].size();

        if(stat)
        {


            int ans=0;

            for(i=0;i<sz;i++)
            {
                int best=100000;
                VI vv=save[i];
                int mx=vv.back();
                for(j=1;j<=mx;j++ )
                {
                    int Now=0;
                    for(k=0;k<n;k++)
                    {
                        Now+=abs(j-vv[k] );
                    }
                    if(Now<best)best=Now;
                }
                ans+=best;
            }
            cout<<ans<<endl;
        }
        else cout<<"Fegla Won"<<endl;

    }

    return 0;
}
