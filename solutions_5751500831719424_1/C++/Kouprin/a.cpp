#pragma comment(linker, "/STACK:65000000")
#include <algorithm>
#include <cmath>
#include <cstdio> 
#include <cstring> 
#include <iostream> 
#include <map> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <string> 
#include <vector> 

using namespace std; 

template<class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long long lng;
typedef long double ld;
typedef stringstream istr;

#define TynKogep TOPCODER
#define bublic public:
#define pb push_back
#define sz(x) ((int)(x).size())
#define mp make_pair
#define first fi
#define second se
#define clr(a) memset((a),0,sizeof(a))

vector<char> let;
vector<int> v[120];
bool lose;

void upd(string s, int x) {
    vector<char> here;
    vector<int> w;
    s = s + " ";
    int cnt = 1;
    for(int i = 1; i < sz(s); ++i) {
        if (s[i - 1] != s[i]) {
            here.pb(s[i - 1]);
            w.pb(cnt);
            cnt = 1;
        } else {
            ++cnt;
        }
    }
    if (sz(let)) {
        if (let != here) {
            lose = true;
        }
    } else {
        let = here;
    }
    v[x] = w;
}

int main() {
    int t, n;
    string s;
    cin >> t;
    for(int T = 0; T < t; ++T) {
        cout << "Case #" << T + 1 << ": ";

        let.clear();
        cin >> n;
        lose = false;
        for(int i = 0; i < n; ++i) {
            v[i].clear();
            cin >> s;
            upd(s, i);
        }
        if (lose) {
            cout << "Fegla Won" << endl;
            continue;
        } else {
            int ans = 0;
            for(int i = 0; i < sz(let); ++i) {
                int bst = 1000000000;
                for(int j = 1; j < 120; ++j) {
                    int cur = 0;
                    for(int k = 0; k < n; ++k) {
                        cur += abs(v[k][i] - j);
                    }
 //                   cerr << cur << endl;
                    bst = min(bst, cur);
                }
                ans += bst;
            }
            cout << ans << endl;
        }
    }
    return 0;
};
