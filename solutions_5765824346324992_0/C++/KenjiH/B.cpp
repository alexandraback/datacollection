#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define MP(x,y) make_pair(x,y)
#define REP(i,n) for(int i=0; i<(int)(n); i++)

int b, n;
int m[1000];

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);    
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

void solve() {
    cin >> b >> n;
    REP (i, b) cin >> m[i];

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

    REP (i, b)
        q.push(MP(0, i));

    long long l = 1;
    REP (i, b) l = lcm(l, m[i]);
    long long c = 0;
    REP (i, b) c += l / m[i];
    n = (n - 1) % c + 1;

    int ret = 0;
    REP (i, n) {
        int x = q.top().second;
        int y = q.top().first;
        
        ret = x;
        q.pop();
        q.push(MP(y + m[x], x));
    }
    
    cout << ++ret << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    REP (i, T) {
        cerr << "Case #" << i+1 << ": " << endl;
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
