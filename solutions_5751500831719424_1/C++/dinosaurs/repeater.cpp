#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAXL = 101, MAXN = 101;

int T, N, len[MAXN], cur[MAXN], vals[MAXN];
char strings[MAXN][MAXL];

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            cur[i] = 0;
            scanf("%s", strings[i]);
            len[i] = strlen(strings[i]);
        }

        int answer = 0;
        bool fail = false;
        while (true) {
            bool done = true;
            for (int i = 0; i < N; i++) {
                if (cur[i] < len[i]) {
                    done = false;
                }
            }
            if (done) {
                break;
            }

            char next_char = strings[0][cur[0]];
            for (int i = 0; i < N; i++) {
                if (strings[i][cur[i]] != next_char) {
                    fail = true;
                    break;
                }

                vals[i] = 0;
                while (cur[i] < len[i] && strings[i][cur[i]] == next_char) {
                    vals[i]++;
                    cur[i]++;
                }
            }

            if (fail) {
                break;
            }

            sort(vals, vals + N);
            int med = vals[N / 2];
            for (int i = 0; i < N; i++) {
                answer += abs(med - vals[i]);
            }
        }

        if (fail) {
            printf("Case #%d: Fegla Won\n", t);
        } else {
            printf("Case #%d: %d\n", t, answer);
        }
    }

    return 0;
}
