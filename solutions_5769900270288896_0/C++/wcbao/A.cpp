#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) (A/gcd(A,B)*B)
#define clr(A) memset(A,0,sizeof(A))


using namespace std;

typedef long long LL;
typedef pair<int,int> P;
typedef pair<P,int> pp;
const int mod = 1000000007;
const int root = 1;
const int mm = 1000005;


int R,C,n;

int solve(int s){
    int mp[R][C];
    clr(mp);
    for(int i = 0; s; i++,s >>= 1){
        if(s&1) mp[i/C][i%C] = 1;
    }
    int res = 0;
    for(int i = 0; i < R; i++)
    for(int j = 0;j < C; j++)
    if(mp[i][j]){
        if(i+1<R && mp[i+1][j]) res++;
        if(j+1<C && mp[i][j+1]) res++;
    }
    return res;
}
int main()
{
//   freopen("wcbao.in","r",stdin);
//   freopen("wcbao.out","w",stdout);
    int T = 0, cas = 0;
    cin >> T;
    while(T--)
    {
        printf("Case #%d: ",++cas);
        cin >> R >> C >> n;
        int comb = (1<<n) - 1;
        int ans = R*C*4;
        while(comb && (comb < 1 << (R*C))){
            int x = comb & -comb, y = comb+x;
            ans = min(ans,solve(comb));
            comb = ((comb&~y)/x>>1)|y;
        }
        if(n==0) ans = 0;
        cout << ans<< endl;
    }
    return 0;
}
