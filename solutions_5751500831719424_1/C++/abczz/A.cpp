#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>

#define REP(i,n) for(int i=0;i<(n);i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define SIZE(x) (int)(x).size()

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

string Gao(string s, vector<int>& a) {
    string t = "";
    a.clear();
    for (int i = 0; i < s.length();) {
        int ii = i;
        while (ii < s.length() && s[ii] == s[i]) ++ii;
        a.PB(ii - i);
        t += s[i];
        i = ii;
    }
    return t;
}

void Solve() {
    int n;
    string s[110];
    vector<int> a[110];
    cin >> n;
    REP(i, n) {
        cin >> s[i];
    }
    string tmp = Gao(s[0], a[0]);
    bool flag = true;
    for (int i = 1; i < n; ++i) {
        if (tmp != Gao(s[i], a[i])) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        puts("Fegla Won");
        return;
    }
    int ans = 0, m = SIZE(a[0]);
    REP(i, m) {
        int best = 1e7;
        for (int j = 1; j <= 100; ++j) {
            int cnt = 0;
            REP(k, n) {
                cnt += abs(a[k][i] - j);
            }
            best = min(best, cnt);
        }
        ans += best;
    }
    cout << ans << endl;
}

int main() {
//  freopen("A.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
    int cas;
    cin >> cas;
    for (int T = 1; T <= cas; ++T) {
        printf("Case #%d: ", T);
        Solve();
    }
    return 0;
}

