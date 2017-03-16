#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> A[5000];

long long cross(pair<int, int> A, pair<int, int> B, pair<int, int> C)
{
    C.first-=B.first;
    C.second-=B.second;
    B.first-=A.first;
    B.second-=A.second;
    return 1LL*C.first*B.second-1LL*B.first*C.second;
}

void _main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &A[i].first, &A[i].second);
    if(N==1)
    {
        printf("0\n");
        return;
    }
    if(N==2)
    {
        printf("0\n0\n");
        return;
    }
    for(int i=0; i<N; i++)
    {
        int ans=0x3f3f3f3f;
        for(int j=0; j<N; j++) if(i!=j)
        {
            int cnt0=0, cnt1=0;
            for(int k=0; k<N; k++) if(i!=k && j!=k)
            {
                long long c=cross(A[i], A[j], A[k]);
                if(c<0)
                    cnt0++;
                else if(c>0)
                    cnt1++;
            }
            ans=min(ans, min(cnt0, cnt1));
        }
        printf("%d\n", ans);
    }
}

int main()
{
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        printf("Case #%d:\n", i);
        _main();
    }
    return 0;
}
