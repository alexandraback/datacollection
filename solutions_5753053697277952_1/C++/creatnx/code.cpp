#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <complex>
#include <cstring>

using namespace std;
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a); i > (b); i--)
#define forIt(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define forRev(it, a) for(__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
#define ft(a) __typeof((a).begin())
#define ll long long
#define ld long double
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define sz(a) (a).size()
#define all(a) (a).begin(), (a).end()
#define Rep(i,n) for(int i = 0; i < (n); ++i)

typedef complex<ld> cplex;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int N = 1e6 + 7;
const int M = 107;
const int mod = 998244353;
const int inf = 1e9 + 7;
const double pi = acos(-1);
const int maxn = N * 2;
const double PI = acos(-1);

int p[30];
priority_queue<ii> heap;

void solve() {
    int sum = 0;
    while (!heap.empty()) heap.pop();
    int n;
    cin >> n;
    rep(i, 0, n) {
        scanf("%d", p + i);
        heap.push(mk(p[i], i));
        sum += p[i];
    }
    if ((sum % 2 == 1) && !heap.empty()) {
        printf("%c ", char(heap.top().second + 'A'));
        int u = heap.top().second;
        heap.pop();
        //cout << u <<" " << heap.size()<< "\n";
        p[u]--;
        if (p[u] > 0) heap.push(mk(p[u], u));
        sum--;
    }
    while (!heap.empty()) {
        //cout << sum <<" " << heap.size()<< "\n";
        if (heap.size() == 1) {
            printf("%c", char(heap.top().second + 'A'));
            break;
        }
        int u = heap.top().second; heap.pop();
        int v = heap.top().second; heap.pop();
        printf("%c%c ", char(u + 'A'), char(v + 'A'));
        p[u]--; p[v]--;
        //cout << p[u] << " " << p[v] << "\n";
        if (p[u] > 0) {
            heap.push(mk(p[u], u));
            //cout << p[u] << " " << u << "\n";
        }
        if (p[v] > 0) heap.push(mk(p[v], v));
        sum -= 2;
    }
    
    puts("");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    rep(i, 1, T + 1) {
        printf("Case #%d: ", i);
        solve();
        //puts("");
    }
}