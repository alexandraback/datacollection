#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <complex>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>

#define all(x) (x).begin(), (x).end()

#ifdef KAZAR
    #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

using namespace std;

template<class T> inline void umax(T &a,T b){if(a<b) a = b ; }
template<class T> inline void umin(T &a,T b){if(a>b) a = b ; }
template<class T> inline T abs(T a){return a>0 ? a : -a;}
template<class T> inline T gcd(T a,T b){return __gcd(a, b);}
template<class T> inline T lcm(T a,T b){return a/gcd(a,b)*b;}

typedef long long ll;
typedef pair<int, int> ii;

const int inf = 1e9 + 143;
const ll longinf = 1e18 + 143;

inline int read(){int x;scanf(" %d",&x);return x;}

int a[55][55];

int get(int a,int b,int k,int t){
    vector<int> d;
    int have = 0;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            int x = (i + j) % 2;
            if(x == t){
                have++;
            }else{
                int cd = 0;
                cd += (i > 0);
                cd += (j > 0);
                cd += (i + 1 < a);
                cd += (j + 1 < b);
                d.push_back(cd);
            }
        }
    }
    sort(all(d));
    int res = 0;
    int ptr = 0;
    while(have < k){
        assert(ptr < d.size());
        res += d[ptr++];
        ++have;
    }
    return res;
}

int calc(int a,int b,int k){
    return min(get(a, b, k, 0), get(a, b, k, 1));
}

int brute(int r,int c,int n){
    int ans = inf;
    for(int mask = 0; mask < (1 << (r * c)); mask++){
        if(__builtin_popcount(mask) != n)
            continue;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                a[i][j] = (mask >> (i * c + j)) & 1;
            }
        }
        int cur = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(a[i][j]){
                    if(i + 1 < r) cur += a[i + 1][j];
                    if(j + 1 < c) cur += a[i][j + 1];
                }
            }
        }
        umin(ans, cur);
    }
    return ans;
}

void solve(){
    /*int r = rand() % 5 + 1;
    int c = rand() % 5 + 1;
    int n = rand() % (r * c) + 1;
    */
    int r = read();
    int c = read();
    int n = read();
    /*if(brute(r, c, n) != calc(r, c, n)){
        eprintf("r = %d, c = %d, n = %d\n", r, c, n);
        eprintf("ans = %d\n", brute(r, c, n));
        eprintf("calc = %d\n", calc(r, c, n));
        exit(123);
    }*/
    printf("%d\n", calc(r, c, n));
}

int main(){

#ifdef KAZAR
    freopen("f.input","r",stdin);
    freopen("f.output","w",stdout);
    freopen("error","w",stderr);
#endif

    srand(time(0));
    int tc = read();

    for(int i = 1; i <= tc; i++){
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
