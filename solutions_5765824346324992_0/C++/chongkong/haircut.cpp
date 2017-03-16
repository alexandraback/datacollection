#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int time_taken[1000];
int available[1000000];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        memset(available, 0, sizeof available);

        int b, n;
        cin >> b >> n;
        for (int i = 0; i < b; i++) {
            cin >> time_taken[i];
        }

        double cut_power = 0.0;
        for (int i = 0; i < b; i++) {
            cut_power += 1.0 / time_taken[i];
        }

        long long estimate_time = (n-b) / cut_power - 1;
        int done_customer = 0;
        for (int i = 0; i < b; i++) {
            done_customer += 1 + (estimate_time-1) / time_taken[i];
        }

        for (int i = 0; i < b; i++) {
            int base = (time_taken[i] - (estimate_time % time_taken[i])) % time_taken[i];
            int offset = time_taken[i];
            for (int j = 0;; j++) {
                if (base > 1000000) break;
                available[base] += 1;
                base += offset;
            }
        }

        // first c is always smaller than n - available[0]
        int ans = -1;
        for (long long c = done_customer, t = 0; t < 1000000 && ans == -1;) {
            if (c + available[t] < n) {
                c += available[t];
                t++;
            }
            else {
                int customer_left = n - c;
                for (int i = 0; i < b; i++) {
                    if ((estimate_time + t) % time_taken[i] == 0) {
                        customer_left--;
                        if (customer_left == 0) {
                            ans = i + 1;
                        }
                    }
                }
            }
        }

        fprintf(stderr, "Case #%d done\n", tc);
        cout << "Case #" << tc << ": " << ans << endl;
    }
}