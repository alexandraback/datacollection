using namespace std;
#include<bits/stdc++.h>

#define BG begin()
#define ED end()
#define st first
#define nd second
#define PB push_back
#define PF push_front
#define FOR(i,a,b) for (long long i=a;i<b;i++)
#define FORE(i,a,b) for (long long i=a;i<=b;i++)
#define FORD(i,a,b) for (long long i=a;i>=b; i--)
#define ri(n)({\
    int neg=0;\
    n=0;\
    char ch;\
    for(ch=getchar(); ch<'0' || ch>'9'; ch=getchar()) if (ch=='-') neg=1-neg;\
    n=ch-48;\
    for(ch=getchar(); ch>='0' && ch<='9'; ch=getchar()) n=(n<<3)+(n<<1)+ch-48;\
    if (neg) n=-n;\
})

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> II;
typedef pair<ll,ll> LL;
const ll INF=1000000;
const double esp=1e-13;
const double pi=3.141592653589;

ll canhai(ll n)
{
    ll fi,la,mid;
    fi=0;
    la=n+1;
    while (fi+1<la)
    {
        mid=fi/2+la/2;
        if (fi%2 && la%2) mid++;
        if (mid>n/mid) la=mid;
        else fi=mid;
    }
    return fi;
}

int a[100+10],test,n,r,c,dem,f2[100+10][100+10],ans,kq,f[100+10];

void xuli(int i)
{
    if (i>r*c)
    {
        int dong=1;
        int vtht=1;
        FORE(k,1,r*c)
        {
            f2[dong][vtht]=a[k];
            vtht++;
            if (vtht==c+1)
            {
                dong++;
                vtht=1;
            }
        }
        int kq=0;
        FORE(i,1,r)
        FORE(j,1,c)
        if (f2[i][j]==1)
        {
            if (f2[i][j]==f2[i-1][j]) kq++;
            if (f2[i][j]==f2[i][j-1]) kq++;
        }
        ans=min(ans,kq);
        return;
    }
    FORE(j,0,1)
    if (f[j]>0)
    {
        a[i]=j;
        f[j]--;
        xuli(i+1);
        f[j]++;
    }
}

int main()
{
    freopen("codeforces.inp", "r", stdin);
    freopen("8224486B.out", "w", stdout);
    dem=0;
    cin >> test;
    while (test--)
    {
        dem++;
        cin >> r >> c >> n;
        f[1]=n;
        f[0]=r*c-n;
        ans=INF;
        xuli(1);
        cout << "Case #" << dem << ": " << ans << "\n";
    }
}

