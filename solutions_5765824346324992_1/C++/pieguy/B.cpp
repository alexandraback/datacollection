#include <cstdio>
#include <algorithm>
#include <cassert>

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int N, B, M[1005];
        scanf("%d %d", &B, &N);
        for(int i=0; i<B; i++)
        {
            scanf("%d", M+i);
        }
        if (N <= B)
        {
            printf("Case #%d: %d\n", t, N);
            continue;
        }
        N--;
        long long lo=0, hi=1e18;
        while(lo+1 < hi)
        {
            long long mid = (lo+hi)/2;
            long long cnt=0;
            for(int i=0; i<B; i++)
            {
                cnt += mid/M[i] + 1;
            }
            if (cnt <= N) lo=mid;
            else hi=mid;
        }
        for(int i=0; i<B; i++)
        {
            N-=lo/M[i] + 1;
        }
        assert(N>=0);
        int ans=-1;
        for(int i=0; i<B; i++)
        {
            if ((hi % M[i]) == 0)
            {
                if (!N)
                {
                    ans=i+1;
                    break;
                }
                else
                    N--;
            }
        }
        assert(ans!=-1);
        printf("Case #%d: %d\n", t, ans);
    }
}
