#include <iostream>
#include <cstdio>

using namespace std;

int T;
int M[2000];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    scanf("%d", &T);

    for(int Ti = 1; Ti <= T; Ti++)
    {
        int Ans1 = 0, Ans2 = 0;

        int N;
        scanf("%d", &N);

        for(int Ni = 0; Ni < N; Ni++)
            scanf("%d", &M[Ni]);

        int mx = 0;

        for(int Ni = 0; Ni < N-1; Ni++)
        {
            if( M[Ni] > M[Ni+1] ) Ans1 += M[Ni]-M[Ni+1];
            mx = max(mx, M[Ni]-M[Ni+1]);
        }

        for(int Ni = 0; Ni < N-1; Ni++)
            Ans2 += min(mx, M[Ni]);

        printf("Case #%d: %d %d\n", Ti, Ans1, Ans2);
    }
}
