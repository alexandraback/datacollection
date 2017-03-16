#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> occ[26];

int main() {
    int T;
    scanf("%d", &T);
    for(int test = 1; test <= T; ++test) {
        printf("Case #%d: ", test);

        int N;
        scanf("%d", &N);
        for(int i = 0; i < N; ++i) {
            int c;
            scanf("%d", &c);
            occ[i] = pair<int, int>(c, i);
        }
        sort(occ, occ+N);
        reverse(occ, occ+N);
        while(true) {
            int f = -1;
            int s = -1;
            for(int i = 0; i < N; ++i) {
                if(occ[i].first > 0) {
                    if(f == -1) {
                        f = occ[i].second;
                        --occ[i].first;
                        continue;
                    }
                    if(s == -1) {
                        s = occ[i].second;
                        --occ[i].first;
                        break;
                    }
                }
            }
            if(f == -1 && s == -1)
                break;
            if(s == -1) {
                printf("%c ", f + 'A');
            }
            if(s != -1) {
                printf("%c%c ", f + 'A', s + 'A');
            }
        }

        printf("\n");
    }

    return 0;
}
