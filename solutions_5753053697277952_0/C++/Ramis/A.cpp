#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <assert.h>
using namespace std;

void smain();
int main(){
#ifdef TASK
    //freopen(TASK".in","rt",stdin);
    freopen("/Users/ramis/Downloads/A-small-attempt0.in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
    const clock_t start = clock();
#endif
    smain();
#ifdef TASK
    cerr << "\nTotal Execution Time: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

#ifndef M_PI
#define M_PI 3.14159265358979311599796346854418516
#endif
#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define int long long
#define LL __int128
#define mp(a,b) make_pair(a,b)
#define INF 2305843009213693951LL
#define MOD 1000000007
#define EPS 1E-6
#define N 5005
/* --------- END TEMPLATE CODE --------- */
int n, p[N];

void smain() {
    cin >> n;
    for (int cas = 1; cin >> n; ++cas) {
        int m = 0;
        forn(i, n) cin >> p[i], m += p[i];
        vector<string> res;
        if (m & 1) {
            int i = max_element(p, p + n) - p;
            p[i] -= 1;
            m -= 1;
            string t;
            t.push_back('A' + i);
            res.push_back(t);
        }
        for (; m > 0; m -= 2) {
            int i = max_element(p, p + n) - p;
            if (p[i] == 0) break;
            char str[3];
            str[0] = 'A' + i;
            p[i] -= 1;
            int j = max_element(p, p + n) - p;
            p[j] -= 1;
            str[1] = 'A' + j;
            str[2] = 0;
            res.push_back(string(str));
        }
        cout << "Case #" << cas << ":"; for (auto i : res) cout << ' ' << i; cout << '\n';
        cerr << "Case #" << cas << ":"; for (auto i : res) cerr << ' ' << i; cerr << endl;
    }
}
