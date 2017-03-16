#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <limits>
#include <iomanip>

#define INF 1000000000
#define Inf 1000000000000000000
#define mp make_pair
#define pb push_back
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

map<pair<vi,int>, int> m;
int r,c,n, currentAns;

int solve(vi vec, int count, int ans) {
    if (ans >= currentAns) return INF;
    //cout << count << " " << ans << endl;
    /*for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j)
            if (vec[i] & (1 << j)) cout << 1;
            else cout << 0;
        cout << endl;
    }
    cout << endl;*/
    if (count == n) return ans;
    if (count > n) return INF;
    pair<vi,int> p = mp(vec,count);
    if (m.count(p) > 0) return INF;
    m[p] = ans;
    int minAns = INF;
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if (vec[i] & (1 << j)) continue;
            int anss = ans;
            vec[i] |= (1 << j);
            if (i > 0 && (vec[i - 1] & (1 << j))) ++anss;
            if (i < r - 1 && (vec[i + 1] & (1 << j))) ++anss;
            if (j > 0 && (vec[i] & (1 << (j - 1)))) ++anss;
            if (j < c - 1 && (vec[i] & (1 << (j + 1)))) ++anss;
            minAns = min(minAns,solve(vec,count + 1, anss));
            vec[i] &= ~(1 << j);
        }
    }
    currentAns = min(currentAns,minAns);
    return minAns;
}

int main() {
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; ++cas)
    {
        m.clear();
        currentAns = INF;
        cin >> r >> c >> n;
        vi vec(r);
        solve(vec,0,0);
        cout << "Case #" << cas << ": " << ((currentAns >= INF) ? 0 : currentAns) << endl;
    }
    return 0;
}
