#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;

#define ll long long

int main() {
    int T;
    cin>>T;

    for (int t=1;t<=T;++t) {
        int R, C;
        cin>>R>>C;
        ll N;
        cin>>N;

        int best = 1<<20;
        for (int i=0;i<(1<<(R*C));++i) {
            int c = 0;
            int b = 0;
            for (int j=0;j<R*C;++j) {
                if (!(i & (1<<j))) {
                    continue;
                }
                c++;

                if ((j % C) != C-1 && (i & (1<<(j+1)))) {
                    b++;
                }
                if (i & (1<<(j+C))) {
                    b++;
                }
            }
            if (c == N) {
                best = min(best, b);
            }
        }


        printf("Case #%d: %d\n", t, best);
    }
}
