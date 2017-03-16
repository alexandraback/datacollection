#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <ctime>
#include <fstream>
#include <cmath>

using namespace std;

#ifndef LOCAL
#define cerr if(0)cerr
#endif
#define pb push_back
#define mp make_pair

#define F first
#define S second
#define RT fprintf(stderr, "\nTIME = %lf\n", 1.0 * clock()/CLOCKS_PER_SEC);

typedef long long ll;
typedef long double ld;

const int INFint = 2147483547;
const ll INF = 9223372036854775807ll;
const ll MOD = 1000000007ll;

#define FILE "horizon"


int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
//    freopen(FILE".in", "r", stdin); freopen(FILE".out", "w", stdout);
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        int n;
        cin >> n;
        printf("Case #%d: ", TC);
        vector<pair<int, int> > a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].F;
            a[i].S = i;
        }
        sort(a.begin(), a.end());
        vector<string> ans;
        while (a.back().F > a[n - 2].F) {
            char cur = char('A' + a.back().S);
            a.back().F--;
            string s;
            s += cur;
            ans.pb(s);
        }
        for (int i = 0; i < n - 2; i++) {
            while (a[i].F > 0) {
                a[i].F--;
                char cur = char('A' + a[i].S);
                string s;
                s += cur;
                ans.pb(s);
            }
        }
        while (a.back().F > 0) {
            a.back().F--;
            string s;
            s += char('A' + a.back().S);
            s += char('A' + a[n - 2].S);

            ans.pb(s);

        }
        cerr << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
            printf("%s ", ans[i].c_str());
        }
        printf("\n");
    }
    RT;
    return 0;
}