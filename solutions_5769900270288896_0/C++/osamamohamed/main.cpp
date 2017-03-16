#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int A[17][17];

int main()
{
    freopen("B-small-attempt0.in" , "r" , stdin);
    freopen("out.out" , "w" , stdout);
    int T , c = 0;
    scanf("%d" , &T);
    while(T--)
    {
        ++c;
        int R , C , N;
        scanf("%d%d%d" , &R , &C , &N);

        int ans = (1 << 30);
        for(int i = 0;i < (1 << (R * C));++i)
        {
            if(__builtin_popcount(i) == N)
            {
                int co = 0;
                for(int j = 0;j < R * C;++j)
                    A[j / C][j % C] = ((i & (1 << j))) ? 1 : 0;

                for(int j = 0;j < R;++j)
                {
                    for(int k = 0;k < C;++k)
                    {
                        if(A[j][k])
                        {
                            if(j)
                                co += A[j - 1][k];

                            if(k)
                                co += A[j][k - 1];
                        }
                    }
                }
                ans = min(ans , co);
            }
        }
        printf("Case #%d: %d\n" , c , ans);
    }
    return 0;
}
