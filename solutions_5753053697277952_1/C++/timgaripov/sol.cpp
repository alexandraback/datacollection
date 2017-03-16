#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long int int64;
typedef long double ext;




int main() {
    int T;
    scanf("%d", &T);
    for (int test = 0; test < T; test++) {
        vector<int> cnt(26, 0);
        string res;
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &cnt[i]);
        }
        for (;;) {
            int id = 0;
            for (int i = 0; i < N; i++) {
                if (cnt[i] > cnt[id])
                    id = i;
            }
            if (cnt[id] == 0)
                break;
            res += ('A' + id);
            cnt[id]--;
        }
        printf("Case #%d:", test + 1);
        int p = 0;
        if (res.size() % 2) {
            printf(" %c", res[0]);
            p++;
        }
        for (int i = p; i < res.size(); i += 2) {
            printf(" %c", res[i]);            
            printf("%c", res[i  + 1]);            
        }
        printf("\n");        
    }
    return 0;
};
