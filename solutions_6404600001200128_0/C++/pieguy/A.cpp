#include <cstdio>
#include <algorithm>

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int N, M[10005];
        scanf("%d", &N);
        int a1=0;
        int a2=0;
        for(int i=0; i<N; i++)
        {
            scanf("%d", M+i);
            if (i > 0)
            {
                a1+=std::max(M[i-1]-M[i], 0);
                a2=std::max(a2, M[i-1]-M[i]);
            }
        }
        int a3=0;
        for(int i=1; i<N; i++)
        {
            a3+=std::min(a2, M[i-1]);
        }
        printf("Case #%d: %d %d\n", t, a1, a3);
    }
}
