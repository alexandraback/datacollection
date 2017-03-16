#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string.h>
#include <queue>
#include <map>
#define INT64 long long
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    int r,c,n;
    int a[16][16];

    for (int _T = 1; _T <= T; ++_T)
    {
        int ans = 1e9;
        scanf("%d %d %d",&r,&c,&n);

        for (int i = 0; i < 1<<(r*c) ; ++i)
        {
            //printf("xx%d\n", i);
            int num = 0;
            int t = i;

            for (int x = 0; x < r; ++x)
            for (int y = 0; y < c; ++y)
            {
                a[x][y] = t % 2;
                num += t%2;
                //printf("%d\n", a[x][y]);
                t >>= 1;

            }
            if(num != n)
                continue;

            int now = 0;
            for (int x = 0; x < r; ++x)
            for (int y = 0; y < c; ++y)
            {
                if(a[x][y] == 0)
                    continue;

                if(x < r - 1)
                    if(a[x+1][y]== 1)
                        now++;
                if(y < c - 1)
                    if(a[x][y+1]== 1)
                        now++;
            }
            //printf("now:%d\n",now);
            ans = min(ans, now);
        }
        
        printf("Case #%d: %d\n", _T, ans);
    }
    
    
}