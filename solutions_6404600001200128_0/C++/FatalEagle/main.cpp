#include <bits/stdc++.h>

using namespace std;

int N;
int A[10000];

void _main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    int ans1=0;
    int rate=0;
    for(int i=2; i<=N; i++) if(A[i-1]>A[i])
    {
        ans1+=A[i-1]-A[i];
        rate=max(rate, A[i-1]-A[i]);
    }
    int ans2=0;
    for(int i=1; i<N; i++)
        ans2+=min(A[i], rate);
    printf("%d %d\n", ans1, ans2);
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        printf("Case #%d: ", i);
        _main();
    }
    return 0;
}
