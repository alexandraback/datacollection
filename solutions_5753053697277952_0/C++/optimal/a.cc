#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <functional>
#include <cassert>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;

int main()
{
#ifdef MICRO_LOCAL
	freopen("in.put", "r", stdin);
	clock_t timer_start = clock();
#endif
/*------------------------------------------------------------------------------------*/
    int T;
    scanf("%d",&T);
    for (int tc=1; tc<=T; tc++) {
        int n,a[27],ans=0,sum=0;
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", a+i);
            sum += a[i];
        }
        printf("Case #%d: ", tc);
        while (sum) {
            int mx = 0, idx = -1;
            for (int i=0; i<n; i++) {
                if (a[i] > mx) {
                    idx = i;
                    mx = a[i];
                }
            }
            a[idx]--;
            sum--;
            printf("%c", idx+'A');
            if (sum == 0) break;

            mx = 0, idx = -1;
            for (int i=0; i<n; i++) {
                if (a[i] > mx) {
                    idx = i;
                    mx = a[i];
                }
            }
            if (a[idx] * 2 > sum) {
                printf("%c", idx+'A');
                a[idx]--;
                sum--;
                if (sum == 0) break;
            }

            for (int i=0; i<n; i++) {
            }

            printf(" ");
        }
        puts("");
    }
/*------------------------------------------------------------------------------------*/
#ifdef MICRO_LOCAL
	printf("\nElapsed time : %.2lfms\n", ((double)clock() - (double)timer_start)/1000.0);
#endif
	return 0;
}
