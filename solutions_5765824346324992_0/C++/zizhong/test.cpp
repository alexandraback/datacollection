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
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
void solveBsmall(int ncase) {
    // Mk <= 25
    int b, n;
    cin >> b >> n;
    vector<int> barber(b);
    for(int i = 0; i < barber.size(); i ++) {
        cin >> barber[i];
    }
    ll lcm = 1;
    for(auto x : barber) {
        lcm = lcm * x / gcd(lcm, x);
    }
    ll batch = 0;
    for(auto x : barber) {
        batch += lcm / x;
    }
    n %= batch;
    if (n == 0) n = batch;
    vector<int> barberBusy(b, 0);
    int ret = 0;
    while(1) {
        for(int i = 0; i < b; i ++) {
            if (barberBusy[i] == 0) {
                n --;
                barberBusy[i] = barber[i];
                if (n == 0) {
                    ret = i + 1;
                    break;
                }
            }
        }
        for(int i = 0; i < b; i ++) barberBusy[i] --;
        if (ret > 0) break;
    }
    cout << "Case #" << ncase << ": " << ret << endl;
}
void solve(int ncase) {
    solveBsmall(ncase);
}

int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    //freopen("in.txt", "r", stdin);

    freopen("B-small-attempt0.in", "r", stdin);
    //freopen("A-large.in", "r", stdin);
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
