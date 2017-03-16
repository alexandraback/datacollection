#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define INF 2e9
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < n; i++)
#define MAXN 200

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <long long> vll;

int tests, n;
string s[MAXN];
string t;
vector <int> d[MAXN];

bool p(string & s, int ind) {
    string r;
    int x = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!i || s[i] != s[i - 1]) {
            r += s[i];
            d[ind].pb(1);
        } else {
            d[ind][d[ind].size() - 1]++;
        }
    }
    if (t == "") {
        t = r;
    }
    return t == r;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tests;
    forn (it, tests) {
        cin >> n;
        printf("Case #%d: ", it + 1);
        forn (i, MAXN) d[i].clear();
        t = "";
        bool flag = true;
        forn (i, n) {
            cin >> s[i];
            flag &= p(s[i], i);
        }
        if (!flag) {
            cout << "Fegla Won\n";
            continue;
        }
        int m = d[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {

            int mx = 0, rs = INF;
            for (int j = 0; j < n; j++) {
                mx = max(mx, d[j][i]);
            }
            for (int b = 1; b <= mx; b++) {
                int r = 0;
                for (int w = 0; w < n; w++) {
                    r += abs(b - d[w][i]);
                }
                rs = min(rs, r);
            }
            ans += rs;
        }
        cout << ans << endl;
    }
    return 0;
}
