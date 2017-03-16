#include "../../lib/include.h"

struct cmp {
    bool operator ()(const ii& a, const ii &b) const {
        if (a.first != b.first) return !(a.first < b.first);
        if (a.second != b.second) return !(a.second < b.second);
        return true;
    }
};

struct solver {

    solver() {
    }

    void solve(bool process, istream &cin, ostream &cout) {
        int b;
        cin >> b;

        ll n;
        cin >> n;
        n--;

        vi len(b);
        for (int i = 0; i < b; i++) {
            cin >> len[i];
        }

        LOGIC;
        int res = -1;

        ll lo = 0,
           hi = 1000000000LL * 100000LL * 100LL;
        ll start = -1;

        while (lo <= hi) {
            ll t = lo + (hi - lo) / 2;

            ll at = 0;
            for (int i = 0; i < b; i++) {
                // at += t / len[i];
                at += (t + len[i] - 1) / len[i];
            }

            if (at <= n) {
                start = t;
                lo = t + 1;
            } else {
                hi = t - 1;
            }
        }

        // start = 0;

        priority_queue<pair<ll, int>, vector<pair<ll, int> >, cmp> barber;
        ll at = 0;
        for (int i = 0; i < b; i++) {
            at += (start + len[i] - 1) / len[i];
            barber.push(make_pair((start + len[i] - 1) / len[i] * len[i], i));
            // barber.push(make_pair(0, i));
        }

        while (at < n) {
            at++;
            pair<ll, int> cur = barber.top();
            barber.pop();

            // cout << "on time " << cur.first << " " << (at - 1) << " gets barber " << cur.second << endl;

            barber.push(make_pair(cur.first + len[cur.second], cur.second));
        }

        res = barber.top().second;

        // assert(res != -1);
        OUTPUT;
        cout << res + 1 << endl;
    }
};

// see https://github.com/SuprDewd/GoogleCodeJamRunner
#include "../../lib/gcj.h"
