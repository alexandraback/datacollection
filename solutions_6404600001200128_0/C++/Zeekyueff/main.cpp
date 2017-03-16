#include <iostream>
#include <cstdio>

using namespace std;

int T,N,ar[1000],ans1,ans2,maxDiff;

int main()
{
    freopen("CJ15R1AP1.in","r",stdin);
    freopen("CJ15R1AP1.out","w",stdout);
    scanf("%d",&T);
    for (int z = 1; z <= T; z++){
        ans1 = ans2 = maxDiff = 0;
        scanf("%d",&N);
        for (int i = 0; i < N; i++) scanf("%d",&ar[i]);
        for (int i = 0; i < N-1; i++){
            if (ar[i+1] < ar[i]) ans1 += ar[i]-ar[i+1];
            maxDiff = max(maxDiff,ar[i]-ar[i+1]);
        }
        for (int i = 0; i < N-1; i++){
            ans2 += min(ar[i],maxDiff);
        }
        printf("Case #%d: %d %d\n",z,ans1,ans2);
    }
    return 0;
}

