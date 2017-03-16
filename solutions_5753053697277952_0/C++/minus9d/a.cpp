#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>
#include <complex>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef pair<int, int> P;

bool fault(priority_queue<P, vector<P>> q) {
    int sum = 0;
    int maj = 0;
    while (!q.empty()) {
        P p = q.top(); q.pop();
        sum += p.first;
        maj = max(maj, p.first);
    }

    //printf("sum, maj = %d,%d\n", sum, maj);
    return (maj * 2 > sum);
}

void solve(void)
{
    int N;
    cin >> N;
    vector<int> Ps(N);
    REP(n, N) cin >> Ps[n];

    priority_queue<P, vector<P>> q;
    REP(n, N) {
        q.push(mp(Ps[n], n));
    }

    while (!q.empty()) {
        P p = q.top();
        q.pop();
        p.first--;
        if (p.first > 0) {
            q.push(p);
        }

        char t = 'A' + p.second;
        string ans(1, t);

        if (!q.empty() && fault(q)) {
            P p2 = q.top();
            q.pop();
            p2.first--;
            if (p2.first > 0) {
                q.push(p2);
            }

            char t2 = 'A' + p2.second;
            ans += string(1, t2);
        }

        cout << " " << ans;
    }
}

int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        cout << "Case #" << (test+1) << ":";
        solve();
        cout << endl;
    }

    return 0;
}
