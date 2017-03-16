#include <cstdio>
#include <algorithm>
using namespace std;

int r, c, n;

inline int bit (int x, int y) {
    return x + y * c;
}

inline int sum (int st) {
    int s = 0;

    for (int y = 0; y < r; ++y) {
        for (int x = 0; x < c; ++x) {
            int b = bit (x, y);

            if (st & (1 << b)) {
                int b1 = bit (x + 1, y);
                int b2 = bit (x, y + 1);

                if (x + 1 < c && st & (1 << b1))
                    ++s;
                if (y + 1 < r && st & (1 << b2))
                    ++s;
            }
        }
    }

    return s;
}

int rez () {
    int sol = 1000000, p = r * c;
    int m = 1 << (p);

    for (int i = 0; i < m; ++i) {
        int bit =  0;
        for (int j = 0; j < p; ++j)
            if (i & (1 <<j))
                ++bit;
        if (bit == n) {
            int s = sum (i);
            sol = min (sol, s);
        }
    }

    return sol;
}

int main () {
    //freopen ("date.in", "r", stdin);
    //freopen ("date.out", "w", stdout);
    int t;

    scanf ("%d", &t);

    for (int i = 1; i <= t; ++i) {
        scanf ("%d%d%d", &r, &c, &n);

        int sol = rez ();

        printf ("Case #%d: %d\n", i, sol);
    }

    return 0;
}
