//    In the name of God
#include <bits/stdc++.h>
#define For(i,x,y) for(__typeof(y)i=(x)-((x)>(y));i!=(y)-((x)>(y));i+=1-2*((x)>(y)))
#define rep(i , n) for(int (i) = (0); (i) < (n); ++(i))
inline int in() { int x; scanf("%d", &x); return x; }
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define all(x) x.begin() , x.end()
#define REP(i , c) for(auto i : c)
#define sz(x) (((int)x.size()))
#define mp make_pair
#define pb push_back
#define pp pop_back
#define S second
#define F first
//#define cerr if(0)cerr
//#define int long long
using namespace std;
typedef pair<int,int> pii;
typedef long double dd;
typedef long long ll;
/*#include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
 using namespace __gnu_pbds;
 typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OS;*/
constexpr int inf = 1e9 + 7, base = 541;
constexpr int mod = 1e9+7, N = 1e6 + 7;


int32_t main(){
    int T; cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        int n, a[30] = {}; cin >> n;
        cout << "Case #" << tt << ": ";
        vector<pii> v;
        for (int i = 0; i < n; i++) cin >> a[i], v.push_back({a[i], i});
        sort(all(v));
        while (v[sz(v)-1].F > v[sz(v)-2].F) {
            cout << char('A' + v[sz(v)-1].S) << ' ';
            v.back().F--;
        }
        for (int i = 0; i < v.size()-2; i++)
            for (int j = 0; j < v[i].F; j++)
                cout << char('A' + v[i].S) << ' ';
        for (int i = 0; i < v.back().F; i++) {
            cout << char('A' + v.back().S) << char('A' + v[sz(v)-2].S)<< ' ';
        }
        cout << endl;
    }
}