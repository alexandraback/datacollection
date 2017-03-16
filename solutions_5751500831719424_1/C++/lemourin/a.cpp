#include <cstdio>
#include <string>
#include <algorithm>
#define scanf(args...) (scanf(args) ? : 0)
const int MAXN = 105;
const int INF = 1e9;

std::string str[MAXN];
char buf[MAXN];
int pos[MAXN];
int count[MAXN];

int main() {
    int test;
    scanf("%d", &test);
    
    for (int t=1; t<=test; t++) {
        int n;
        scanf("%d", &n);

        for (int i=0; i<n; i++) {
            scanf("%s", buf);
            str[i] = buf;
        }
        
        for (int i=0; i<n; i++)
            pos[i] = 0;

        int res = 0;
        while (true) {
            bool fail = false;
            int finished = n;
            for (int i=0; i<n && !fail; i++) {
                if (pos[i] < str[i].size()) {
                    finished--;
                    if (str[i][pos[i]] != str[0][pos[0]]) 
                        fail = true;
                }
            }

            if (finished == n)
                break;

            if (fail || finished != 0) {
                res = -1;
                break;
            }

            for (int i=0; i<n; i++) {
                char c = str[i][pos[i]];
                count[i] = 0;
                while (pos[i] < str[i].size() && str[i][pos[i]] == c)
                    count[i]++, pos[i]++;
            }
            //for (int i=0; i<n; i++)
            //    printf("count[%d] = %d, %d\n", i, count[i], pos[i]);
            
            int max = *std::max_element(count, count+n), best = INF;
            for (int i=1; i<=max; i++) {
                int current = 0;
                for (int j=0; j<n; j++)
                    current += std::abs(count[j]-i);
                best = std::min(best, current);
            }
            //printf("best = %d\n", best);

            res += best;
        }

        printf("Case #%d: ", t);
        if (res == -1)
            printf("Fegla Won\n");
        else
            printf("%d\n", res);
    }
}
