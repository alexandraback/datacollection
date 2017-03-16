#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define OUT(x) {cout << #x << " = " << x << endl;}
#define FOUT(x,a,b) {cout << #x << " = "; For(_,a,b) cout << x[_] << ' '; cout << endl;}
#define FOUT2(x,a,b,c,d) {cout << #x << " = " << endl; For(_,a,b){For(__,c,d) cout << x[_][__] << " "; cout << endl;}}
#define fi first
#define se second
#define mp make_pair
#define sz(x) (int)x.size()
#define BIT(s,i) ((s&(1<<i))>0)

typedef long long ll;

int T, n;
string s[111], tmp, tmp2;
vector<int> cnt[111], v;

void solve() {
    cin >> n;
    For(i, 1, n) cin >> s[i];

    tmp.clear();
    For(i, 1, n) cnt[i].clear();

    int inc = 0;
    For(i, 0, sz(s[1]) - 1) {
        ++inc;
        if (i == sz(s[1]) - 1 || s[1][i] != s[1][i + 1]) {
            tmp += s[1][i];
            cnt[1].push_back(inc);
            inc = 0;
        }
    }
    For(i, 2, n) {
        inc = 0;
        tmp2.clear();
        For(j, 0, sz(s[i]) - 1) {
            ++inc;
            if (j == sz(s[i]) - 1 || s[i][j] != s[i][j + 1]) {
                tmp2 += s[i][j];
                cnt[i].push_back(inc);
                inc = 0;
            }
        }
        if (tmp2 != tmp) {
            cout << "Fegla Won" << endl;
            return;
        }
    }
    /*For(i, 1, n) {
        For(j, 0, sz(cnt[i]) - 1)
            cout << cnt[i][j] << " ";
        cout << endl;
    }*/

    int res = 0;
    For(j, 0, sz(tmp) - 1) {
        v.clear();
        For(i, 1, n) v.push_back(cnt[i][j]);
        sort(v.begin(), v.end());
        //FOUT(v, 0, sz(v) - 1);
        int mid = v[n / 2];
        For(i, 0, n - 1)
            res += abs(mid - v[i]);
    }
    cout << res << endl;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    cin >> T;
    For(i, 1, T) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
