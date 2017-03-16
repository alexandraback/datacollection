#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <array>
#include <tuple>
#include <utility>
#include <cctype>
#include <typeinfo>
using namespace std;

#define pp make_pair
#define ss size()
#define aa push_back
#define ff(a, b)    for (int a = 0; a < int(b); ++a)
#define oo(a, b)    for (int a = 1; a < int(b); ++a)
#define ii(n)    ff(i, n)
#define kk(n)    ff(k, n)
#define mm(n)    ff(m, n)
#define fff(a, b, c) for (int a = int(b); a < int(c); ++a)
#define iii(a, b) fff(i, a, b)
#define kkk(a, b) fff(k, a, b)
#define mmm(a, b) fff(m, a, b)
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define all(x)  (x).bb, (x).ee
#define ite(v)   decltype((v).bb)
#define fe(i, v) for(ite(v) i = (v).bb; i != (v).ee; ++i)
#define err(...)    { fprintf(stderr, __VA_ARGS__); fflush(stderr); }

using LL = long long;


pair<vector<int>, string> canonicalise(string s) {
    
    string canonical;
    vector<int> counts(1, 1);
    canonical += s[0];
    oo (i, s.ss) {
        if (s[i-1] != s[i]) {
            canonical += s[i];
            counts.aa(1);
        } else {
            counts[counts.ss-1] += 1;
        }
    }
    return pp(counts, canonical);
}

int main() {
    
    int T;
    cin >> T;
    ff (icase, T) {
        int N;
        cin >> N;
        string strs[N];
        ii (N)
            cin >> strs[i];

        vector<vector<int> > allcounts;
        string canonical;
        bool fail = false;
        ii (N) {
            pair<vector<int>, string> p = canonicalise(strs[i]);
            allcounts.aa(p.xx);
            if (0 == i) {
                canonical = p.yy;
            } else {
                if (canonical != p.yy) {
                    fail = true;
                    break;
                }
            }
        }

        int re = 0;
        if (!fail) {
            ii (allcounts[0].ss) {
                int best = 1 << 30;
                oo (k, 101) {
                    int here = 0;
                    mm (allcounts.ss) {
                        here += abs(allcounts[m][i] - k);
                    }
                    best = min(best, here);
                }
                re += best;
            }
        }

        printf("Case #%d: ", icase+1);
        if (fail) {
            printf("Fegla Won\n");
        } else
            printf("%d\n", re);
    }

    return 0;
}







