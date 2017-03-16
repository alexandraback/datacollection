#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <ctime>
#include <list>
#include <set>

using namespace std;

#define N 26
int cnt[N];

int main() {
    int test, n;
    scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        scanf("%d", &n);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", cnt + i);
            sum += cnt[i];
        }
        printf("Case #%d:", cas);

        while (sum) {
            int ma = 0, ida = -1, mb = 0, idb = -1;
            for (int i = 0; i < n; i++) {
                if (cnt[i] >= ma) {
                    mb = ma;
                    idb = ida;
                    ma = cnt[i];
                    ida = i;
                }
                else if (cnt[i] > mb) {
                    mb = cnt[i];
                    idb = i;
                }
            }

            if (2 * mb > sum - 1) {
                cnt[ida]--;
                cnt[idb]--;
                sum -= 2;
                printf(" %c%c", ida + 'A', idb + 'A');
            }
            else {
                cnt[ida]--;
                sum--;
                printf(" %c", (char)(ida + 'A'));
            }
        }
        puts("");
    }
    return 0;
}

