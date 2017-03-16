#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
#define pb push_back
#define MP make_pair
#define fi  first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define SZ(X) ((int)(v).size())
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define READ freopen("a.in","r",stdin);freopen("a.out","w",stdout)
void read(string t)
{
    freopen((t+".in").c_str(),"r",stdin);
    freopen((t+".out").c_str(),"w",stdout);
}
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef pair<int,int> pii;
template <class T>
void Max(T &a, T b) { a=max(a, b); }
int R,C,n;
int main()
{
    READ;
    int re,ca=1;
    cin>>re;
    while (re--) {
        cin>>R>>C>>n;
        int ans = inf;
        int m = R*C;
        for (int s=0;s<(1<<m);s++) {
            //int a[16][16];
            int a[56];
            memset(a,0,sizeof a);
            int cnt = 0;
            int t = 0;
            for (int i=0;i<m;i++)
            {
                int x=i/C, y=i%C;
                if (s>>i & 1)
                {
                    a[i] = 1, cnt++;
                }
                else a[i] = 0;
            }

            for (int i=0;i<m;i++) if (a[i]){
                int x=i/C, y=i%C;
                if (i%C>=1 && a[i-1]) t++;
                if (i/C > 0 && a[i-C]) t++;
                if (i%C<C-1 && a[i+1]) t++;
                if (i/C < R-1 && a[i+C]) t++;
            }
            t/=2;
            if (cnt==n) ans = min(ans, t);

        }
        printf("Case #%d: %d\n", ca++, ans);
    }
}
