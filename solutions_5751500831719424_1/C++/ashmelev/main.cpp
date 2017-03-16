#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define spc(i,n) " \n"[i == n - 1]

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

template<class T> T abs(T x) { return x > 0 ? x : -x;}

#define FILENAME ""

int m;
int n;

vector<pair<char, int> > parse(string s) {
    vector<pair<char, int> > ans;
    int p = 0;
    while (p < sz(s)) {
        int c = 0;
        char cur = s[p];
        while (p < sz(s) && s[p] == cur) {
            c++;
            p++;
        }
        ans.pb(mp(cur, c));
    }
    re ans;
}

int check(vector<vector<pair<char, int> > > v) {
    int n = sz(v);
    int m = sz(v[0]);
    rep(i, n)
        if (sz(v[i]) != m)
            re 0;
    rep(i, n) rep(j, i)
        rep(k, m)
            if (v[i][k].fi != v[j][k].fi)
                re 0;
    re 1;
}

int getans(vi v) {
    sort(all(v));
    int x = v[sz(v) / 2];
    int ans = 0;
    rep(i, sz(v))
        ans += abs(v[i] - x);
    re ans;
}

int getans(vector<vector<pair<char, int> > > v) {
    int n = sz(v);
    int m = sz(v[0]);
    int ans = 0;
    rep(i, m) {
        vi tmp;
        rep(j, n)
            tmp.pb(v[j][i].se);
        ans += getans(tmp);
    }
    re ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;
    rep(tt, tc) {
        cout << "Case #" << tt + 1 << ": ";

        cin >> n;
        vector<vector<pair<char, int> > > v;
        rep(i, n) {
            string s;
            cin >> s;
            v.pb(parse(s));
        }

        if (!check(v)) {
            cout << "Fegla Won" << endl;
            continue;
        }

        int tmp = getans(v);
        cout << tmp << endl;
    }

    re 0;
}
