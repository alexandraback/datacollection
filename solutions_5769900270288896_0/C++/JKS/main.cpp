#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()
#define int long long

int bits(int i)
{
    int result = 0;
    while(i != 0){
        result += i & 1;
        i /= 2;
    }
    return result;
}
bool a[20][20];
int solve2(int r, int c, int n){
    int temp = pow(2,r*c);
    int result = 1e9;
    REP(q, temp){
        if(bits(q) != n){
            continue;
        }
        REP(i, r){
            REP(j, c){
                int k = j + i * c;
                bool bit = (q & ( 1 << k )) >> k;
                a[i][j] = bit;
            }
        }
        int unhap = 0;
        REP(i, r){
            REP(j,c){
                if(a[i][j]){
                    if(i != 0){
                        unhap += a[i - 1][j];
                    }
                    if(i != r - 1){
                        unhap += a[i + 1][j];
                    }
                    if(j != 0){
                        unhap += a[i][j - 1];
                    }
                    if(j != c - 1){
                        unhap += a[i][j + 1];
                    }
                }
            }
        }
        result = min(result,unhap / 2);
    }
    return result;
}

#undef int
int main()
{
#define int long long
#define name "B-small-attempt0"
    freopen(name ".in","r",stdin);
    freopen(name ".out","w",stdout);
    int t;
    cin>>t;
    REP(q,t){
        int r,c,n;
        cin>>r>>c>>n;
        cout<<"Case #"<<q + 1<<": "<<solve2(r,c,n)<<'\n';
    }

    return 0;
}

