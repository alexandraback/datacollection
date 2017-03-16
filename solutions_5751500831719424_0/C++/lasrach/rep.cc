#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

int main() {
    int T = 0;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {

        int N;
        char buf1[128], buf2[128];
        scanf(" %d %s %s", &N, buf1, buf2);

        int i=0, j=0, cost=0;
        bool fail = false;
        while(buf1[i] || buf2[j]) {
            if (buf1[i] != buf2[j]) {
                fail = true;
                break;
            }
            char c = buf1[i];
            while (buf1[i]==c && buf2[j]==c) {
                i++; j++;
            }
            while (buf1[i]==c) {
                i++; cost++;
            }
            while (buf2[j]==c) {
                j++; cost++;
            }
        }

        if (fail) {
            printf("Case #%d: Fegla Won\n", t, cost);
        }else{
            printf("Case #%d: %d\n", t, cost);
        }
    }
}

// vim: set ff=unix ai tw=80 ts=4 sts=4 sw=4 et:
