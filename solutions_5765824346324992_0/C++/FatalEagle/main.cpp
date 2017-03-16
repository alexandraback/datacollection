#include <bits/stdc++.h>

using namespace std;

int N, X;
int A[10000];

void _main()
{
    scanf("%d%d", &N, &X);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    if(X<=N)
    {
        printf("%d\n", X);
        return;
    }
    long long lo=0, mid, hi=1000000000000000LL;
    long long pos;
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        pos=N;
        for(int i=0; i<N; i++)
            pos+=mid/A[i];
        if(X<=pos)
            hi=mid;
        else
            lo=mid+1;
    }
    pos=N;
    for(int i=0; i<N; i++)
        pos+=(lo-1)/A[i];
    long long amt=pos;
    long long wait=X-amt-1;
    for(int i=0; i<N; i++) if(lo%A[i]==0)
    {
        if(wait==0)
        {
            printf("%d\n", i+1);
            return;
        }
        wait--;
    }
    assert(0);
}

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        printf("Case #%d: ", i);
        _main();
    }
    return 0;
}
