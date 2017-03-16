#include <bits/stdc++.h>

using namespace std;

#define FILE_IO

#define fs first
#define sc second

typedef pair<int, char> pic;
pic v[105];
int main()
{
    #ifdef FILE_IO
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    #endif

    int T;
    scanf("%d\n", &T);

    for(int t = 1; t <= T; t ++)
    {
        printf("Case #%d: ", t);
        int N;
        int M = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &v[i].fs);
            M += v[i].fs;
            v[i].sc = 'A' + i;
        }
        N--;
        while(M)
        {
            sort(v, v + N + 1);

            if(v[N].fs == 1 && M % 2 == 1)
            {
                printf("%c ", v[N].sc);
                v[N].fs--;
                M--;
                continue;
            }

            if(v[N].fs == 1)
            {
                printf("%c%c ", v[N].sc, v[N - 1].sc);
                v[N].fs--;
                v[N - 1].fs--;
                M -= 2;
                continue;
            }

            if(v[N - 1].fs > (M - 2) / 2)
            {
                v[N - 1].fs--;
                v[N].fs--;
                M -= 2;
                printf("%c%c ", v[N].sc, v[N - 1].sc);
            }
            else
            {
                v[N].fs -= 2;
                M -= 2;
                printf("%c%c ", v[N].sc, v[N].sc);
            }

        }
        printf("\n");
    }

    return 0;
}
