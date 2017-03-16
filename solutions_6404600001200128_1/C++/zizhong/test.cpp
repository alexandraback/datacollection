#include <vector>
#include<cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#endif
#include <ctime>
#include <queue>
#include <stack>
#include<iomanip>
#include <sstream>
#include <cmath>
#include <list>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, double> PID;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
typedef pair<PII, int> PIP;
void solve(int ncase) {
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i ++) {
        cin >> num[i];
    }
    ll res1 = 0, res2 = 0;
    for(int i = 1; i < n; i ++) {
        if (num[i] < num[i - 1]) res1 += num[i - 1] - num[i];
    }
    int maxe = 0;
    for(int i = 1; i < n; i ++) {
        maxe = max(num[i - 1] - num[i], maxe);
    }
    for(int i = 0; i < n - 1; i ++) {
        res2 += min(maxe, num[i]);
    }
    cout << "Case #" << ncase <<": " << res1 << " " << res2 << endl;
}

int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    //freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //init();
    int T = 1;
    cin >> T;
    //scanf("%d", &T);
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
