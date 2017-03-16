#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    for (int t=1; t<=T; t++) {
            int n;
            scanf("%d", &n);

            int method1 = 0;
            int method2 = 0;
            int max_jump = 0;
            int prev, current;
            scanf("%d", &prev);
            int mushrooms[1000];
            mushrooms[0] = prev;
            for(int i=1; i<n; i++) {
                scanf("%d", &current);
                mushrooms[i]=current;
                if(current < prev) {
                    method1 += prev-current;
                    max_jump = max(max_jump, prev-current);
                }

                prev=current;
            }

            for(int i=0; i<n-1; i++) {
                    method2 += min(max_jump, mushrooms[i]);
            }

            printf("Case #%d: %d %d\n", t, method1, method2);
    }

    return 0;
}
