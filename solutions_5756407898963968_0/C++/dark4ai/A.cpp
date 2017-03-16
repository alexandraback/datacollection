#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>

#define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define printf_debug(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define printf_debug(fmt, args...)
#endif

typedef long long llong;

using namespace std;

int used[17], r;

int main() {
#ifdef DEBUG
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        memset(used, 0, sizeof(used));
        for(int k = 0; k < 2; ++k) {
            cin >> r;
            for(int i = 0; i < 4; ++i) {
                for(int j = 0; j < 4; ++j) {
                    int tmp;
                    cin >> tmp;
                    if(i + 1 == r) {
                        used[tmp]++;
                    }
                }
            }
        }
        int cnt = 0;
        int ans = -1;
        for(int i = 1; i <= 16; ++i) {
            assert(used[i] <= 2);
            cnt += (used[i] == 2);
            if(used[i] == 2) {
                ans = i;
            }
        }
        printf("Case #%d: ", t);
        if(cnt == 0) {
            printf("Volunteer cheated!");
        } else if(cnt == 1) {
            printf("%d", ans);
        } else {
            printf("Bad magician!");
        }
        printf("\n");
    }
    return 0;
}