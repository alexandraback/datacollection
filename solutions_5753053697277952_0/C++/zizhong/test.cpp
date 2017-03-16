#include <vector>
#include <cstdio>
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
typedef pair<ll, ll> PII;
typedef pair<int, double> PID;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
typedef pair<PII, int> PIP;
void precalc(){};
int n, sum;
int p[26];
void solve(int ncase) {
    cin >> n;
    cout << "Case #" << ncase << ":";
    sum = 0;
    vector<PII> v;
    for(int i = 0; i < n; i ++) {
        cin >> p[i];
        sum += p[i];
        v.push_back(PII(p[i], i));
    }
    for(int i = 0; sum > 0; i ++) {
        sort(v.begin(), v.end(), greater<PII>());
        // try rm 1 max
        int maxe = max(v[0].first - 1, v[1].first);
        if (maxe * 2 <= sum - 1) {
            v[0].first --;
            cout << ' '<< char('A' + v[0].second);
            sum --;
            continue;
        }
        sum -= 2;
        cout << ' ' << char('A' + v[0].second);
        v[0].first --;
        sort(v.begin(), v.end(), greater<PII>());
        cout << char('A' + v[0].second);
        v[0].first --;
    }
    cout << endl;
}
int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    //freopen("in.txt", "r", stdin);
    //freopen("A-small-practice.in", "r", stdin);
    //freopen("A-large-practice.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    //precalc();
    //cin >> T;
    scanf("%d", &T);
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
