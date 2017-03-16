#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int calc(int n, int c0, int c1, int c2, int c3) {
    int ret = 0;
    if (n > c0) {
        n = n - c0;
        if (n <= c1) {
            ret += n;
        } else {
            ret += c1;
            n = n - c1;
            if (n <= c2) {
                ret += n * 2;
            } else {
                ret += c2 * 2;
                n = n - c2;
                if (n <= c3) {
                    ret += n * 3;
                } else {
                    ret += c3 * 3;
                    n = n - c3;
                    ret += n * 4;
                }
            }
        }
    }
    return ret;
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int tt;
    cin >> tt;
    for (int ti = 1; ti <= tt; ++ti) {
        int r, c, n;
        cin >> r >> c >> n;
        int answer = 2e9;
        if (r == 1) {
            int c0 = (c + 1) / 2;
            int c1 = c % 2 == 0;
            int c2 = c0 - 1;
            answer = calc(n, c0, c1, c2, 0);
        } else if (c == 1) {
            int c0 = (r + 1) / 2;
            int c1 = r % 2 == 0;
            int c2 = c0 - 1;
            answer = calc(n, c0, c1, c2, 0);
        } else {
            int odd_cnt = (c + 1) / 2;
            int eve_cnt = (c + 0) / 2;
            {
                int odd = (r + 1) / 2;
                int eve = (r + 0) / 2;
                int c0 = odd * odd_cnt + eve * eve_cnt;
                int c2 = 0, c3 = r + c - 2;
                if (r % 2 == 0 || (r % 2 == 1 && c % 2 == 0)) {
                    c2 = 2;
                    c3 = c3 - 2;
                }
                answer = min(answer, calc(n, c0, 0, c2, c3));
            }
            {
                int odd = (r + 0) / 2;
                int eve = (r + 1) / 2;
                int c0 = odd * odd_cnt + eve * eve_cnt;
                int c2 = 2, c3 = r + c - 2;
                if (r % 2 && c % 2) {
                    c2 = c2 + 2;
                }
                c3 = c3 - c2;
                answer = min(answer, calc(n, c0, 0, c2, c3));
            }
        }
        cout << "Case #" << ti << ": " << answer << '\n';
    }
}
