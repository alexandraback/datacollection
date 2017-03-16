#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct tree {
    long long x;
    long long y;
};

int pos(tree p1, tree p2, tree p3) {
    long long ccw = (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
    if (ccw == 0)
        return 0;
    else if (ccw > 0)
        return 1;
    else
        return -1;
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int t=1; t<=T; t++) {
            int N;
            scanf("%d", &N);
            int x, y;
            tree trees[15];

            for (int i=0; i<N; i++) {
                scanf("%d %d", &x, &y);
                trees[i].x=x;
                trees[i].y=y;
            }

            printf("Case #%d:\n", t);

            for (int i=0; i<N; i++) {
                    int best=N-1;
                    for (int j=0; j<N; j++) {
                        if (i!=j) {
                            int above = 0;
                            int below = 0;
                            for (int k=0; k<N; k++) {
                                int ccw = pos(trees[i], trees[j], trees[k]);
                                if(ccw<0)
                                    below++;
                                else if(ccw>0)
                                    above++;
                            }
                            //printf("%d %d | ", above, below);
                            best=min(best, min(above, below));
                        }
                    }
                    printf("%d\n", best);
            }

    }

    return 0;
}
