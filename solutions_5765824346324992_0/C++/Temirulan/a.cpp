#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int t, b, a[20000], n;

ll calc(ll t) {
    ll ans = 0;
    for(int i = 0; i < b; i++) {
        ans += (t + a[i] - 1) / a[i];
        ans = min(ans, (ll)1e18);
    }
    return ans;
}

bool cmp(pii a, pii b) {
    if(a.f != b.f) return a.f < b.f;
    return a.s > b.s;
}

void solve(int num) {
    scanf("%d%d", &b, &n);
    for(int i = 0; i < b; i++) {
        scanf("%d", a + i);
    }
    ll l = 0, r = (ll)1e18;
    ll ans = r;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(calc(mid) >= n) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    int res = -1;
    ll k = calc(ans);
    vector<int> v;
    ll x = inf;
    for(int i = 0; i < b; i++) {
        x = min(x, ans % a[i]);
    }
    for(int i = 0; i < b; i++) {
        if(ans % a[i] == x) v.pb(i + 1);
    }
    reverse(all(v));
    res = v[k-n];
    /*
    for(int i = 0; i < b; i++) cout << v[i].f << " " << v[i].s << endl;
    k -= n;
    cout << k << endl;
    res = v[k].s;
     */
    printf("Case #%d: %d\n", num, res);
}

int main(){
    
    scanf("%d", &t);
    
    for(int i = 1; i <= t; i++) solve(i);
        
    return 0;
}
