#include "../../lib/include.h"

struct solver {

    solver() {
    }

    void solve(bool process, istream &cin, ostream &cout) {


        int n;
        cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        LOGIC;

        int a = 0,
            b = -1;

        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                a += arr[i-1] - arr[i];
            }
        }

        double lo = 0.0,
               hi = 100000;

        // for (int speed = 0; speed <= 10000; speed++) {
        // for (double speed = 0; speed <= 200; speed += 0.01) {
        for (int it = 0; it < 500; it++) {
            double speed = (lo + hi) / 2.0;
            bool ok = true;
            int now = arr[0];
            int cnt = 0;
            for (int i = 1; i < n; i++) {
                cnt += min(now, static_cast<int>(10 * speed));
                now = max(0, now - static_cast<int>(10 * speed));
                if (now > arr[i]) {
                    ok = false;
                }
                now = arr[i];
            }
            if (ok) {
                b = cnt;
                hi = speed;
            } else {
                lo = speed;
            }

            // if (ok) {
            //     // if (b == -1 || cnt < b) {
            //     //     b = cnt;
            //     // }
            //     b = cnt;
            //     cout << speed << " " << cnt << endl;
            //     // break;
            // }
        }

        assert(b != -1);

        OUTPUT;
        cout << a << " " << b << endl;
    }
};

// see https://github.com/SuprDewd/GoogleCodeJamRunner
#include "../../lib/gcj.h"
