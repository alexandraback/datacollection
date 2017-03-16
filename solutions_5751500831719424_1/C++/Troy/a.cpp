#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int N = 111;

int n;
string s[N];
int ptr[N];
bool is_done() {
    REP(i, n) {
        if (ptr[i] < s[i].size()) return false;
    }
    return true;
}

void calc(vi &vec) {
    char ch = '#';
    REP(i, n) {
        if (ptr[i] >= s[i].size()) continue;
        if (ch == '#')  ch = s[i][ptr[i]];
        int cnt = 0;
        while (ptr[i] < s[i].size() && s[i][ptr[i]] == ch) ptr[i]++, cnt++;
        if (cnt == 0) return;
        vec.pb(cnt);
    }
}
int solve() {
    int ret = 0;
    memset(ptr, 0, sizeof(ptr));
    vi vec;
    while (!is_done()) {
        vec.clear();
        calc(vec);
        if (vec.size() != n) return -1;
        sort(all(vec));
        int mid = vec[vec.size() / 2];
        REP(i, vec.size())
            ret += abs(vec[i] - mid);
    }
    return ret;
}
int main() 
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T, ca = 0;
    cin >>T;
    while (T--) {
        cin >>n;
        REP(i, n) cin >>s[i];
        int ans = solve();
        cout <<"Case #" <<++ca <<": ";
        if (ans == -1) cout <<"Fegla Won" <<endl;
        else cout <<ans <<endl;
    } 
    return 0;
}

