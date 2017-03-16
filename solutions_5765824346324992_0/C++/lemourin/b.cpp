#include <cstdio>
#include <algorithm>
#define scanf(args...) (scanf(args) ? : 0)
typedef long long int LL;
const LL INF = 1e15;
const int MAXN = 1005;

int T[MAXN], timeLeft[MAXN], id[MAXN];

bool cmp(int a, int b) {
    if (timeLeft[a] == timeLeft[b])
        return a < b;
    return timeLeft[a] < timeLeft[b];
}

int main() {
    int t;
    scanf("%d", &t);

    for (int test=1; test<=t; test++) {
        int b, n;
        scanf("%d%d", &b, &n);

        for (int i=0; i<b; i++)
            scanf("%d", &T[i]);

        LL start = 0, stop = INF, center;
        while (start < stop) {
            center = (start+stop+1)/2;
            
            LL count = 0;
            for (int i=0; i<b; i++)
                count += (center+T[i]-1)/T[i];

            if (count < n)
                start = center;
            else
                stop = center-1;
        }
        
        LL done = 0;
        for (int i=0; i<b; i++) {
            done += (start+T[i]-1)/T[i];
            timeLeft[i] = start%T[i];
            id[i] = i;
        }

        std::sort(id, id+b, cmp);
        //printf("sum = %Ld, done=%Ld\n", start, done);
        
        printf("Case #%d: %d\n", test, id[n-done-1]+1);
    }
}
