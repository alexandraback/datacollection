#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define EPS 1e-10
typedef long long LL;

LL gcd(LL a, LL b){
    return b ? gcd(b, a%b) : a;
}

LL lcm(LL a, LL b){
    return a / gcd(a, b)*b;
}

class barber {
public:
    int t;
    int num;
    barber(int _t, int _num) : t(_t), num(_num) {}
    bool operator<(const barber& rhs) const {
        if (t != rhs.t) return t > rhs.t;
        return num > rhs.num;
    }
};

void run() {
    int b, n;
    cin >> b >> n;
    vector<int> m(b);
    int l = 1;
    REP(i, b) {
        cin >> m[i];
        l = lcm(l, m[i]);
    }
    int tot = 0;
    REP(i, b) tot += l / m[i];
    n %= tot;
    if (n == 0) n = tot;

    int res = -1;
    priority_queue<barber> que;
    REP(i, b) que.push(barber(0, i + 1));
    int cur = 1;
    while (true) {
        barber tp = que.top();
        que.pop();
        if (cur == n) {
            res = tp.num;
            break;
        }
        tp.t += m[tp.num - 1];
        que.push(tp);
        ++cur;
    }

    cout << res << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
