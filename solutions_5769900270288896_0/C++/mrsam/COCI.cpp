#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <cctype>
#include <complex>
#include <numeric>

#define foreach(i, store) for(__typeof((store).begin()) i = (store).begin() ; i != (store).end() ; i++)
#define sqr(x) ((x)*(x))
#define comb2(x) ((x)*((x)-1)/2)
#define mod(x) ((x + MOD) % MOD)
#define All(store) store.begin(), store.end()
#define Unique(store) store.resize(unique(All(store)) - store.begin())
#define Assign(a, b, s, e) for(int i = s ; i <= e ; i++) b[i] = a[i];
#define IF(condition, x, y) ((condition) ? (x) : (y))
#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define create make_pair
#define pii pair<int, int>
#define ppi pair< pii, int>
#define pic pair<int, char>
#define pll pair<ll, ll>
#define X first
#define Y second
#define Min(x, y) IF(x < y, x, y)
#define Max(x, y) IF(x > y, x, y)

using namespace std;

ifstream fin ("B-small-attempt0.in");
ofstream fout ("out.out");

typedef long long ll;
const int N = 20, INF = 1e8, pw[] = {1, 2, 4, 8, 16, 32, 64};
int dp[N][N][N][N];
int t, n, r, c;

int calc(int i, int j, int cnt, int mask)
{
    int &ret = dp[i][j][cnt][mask];
    
    if(ret != -1) return ret;
    
    if(j == c) return ret = calc(i+1, 0, cnt, mask);
    
    if(i == r) return ret = IF(n == cnt, 0, INF);
    
    int added = !!(pw[c-1] & mask);
    if(j) added += !!(pw[0] & mask);
    
    int msk = mask & ~pw[c-1];
    msk <<= 1;
    ret = min(calc(i, j+1, cnt+1, msk|1) + added, calc(i, j+1, cnt, msk));
    
    return ret;
}

inline int solve()
{
    memset(dp, -1, sizeof dp);
    return calc(0, 0, 0, 0);    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    fin >> t;

    for(int i = 1 ; i <= t ; i++)
    {
        fin >> r >> c >> n;
        
        if(c > r) swap(r, c);
        
        fout << "Case #" << i << ": " << solve() << endl;      
    }

    return 0;
}
