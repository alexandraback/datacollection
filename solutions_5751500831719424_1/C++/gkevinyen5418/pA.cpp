#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

int T, N, Ans, vn;
char c[200]; int A[200]; int cn;

vector<int> ch[200], amt[200];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    scanf("%d", &T);

    for(int Ti = 1; Ti <= T; Ti++)
    {
        scanf("%d", &N);

        for(int Ni = 0; Ni < N; Ni++)
        {
            ch[Ni].clear(); amt[Ni].clear();
            scanf("%s", c); cn = strlen(c);

            int now = -1, cnt = 0;

            for(int ci = 0; ci <= cn; ci++)
            {
                int p = c[ci]-'a';

                if( p != now )
                {
                    if( now != -1 ) amt[Ni].push_back(cnt), ch[Ni].push_back(now);
                    now = p; cnt = 0;
                }

                cnt++;
            }
        }

        printf("Case #%d: ", Ti);

        for(int Ni = 0; Ni < N; Ni++)
            for(int Nj = Ni+1; Nj < N; Nj++)
            {
                if( ch[Ni].size() != ch[Nj].size() ){ puts("Fegla Won"); goto ed; }

                vn = ch[Ni].size();
                for(int vi = 0; vi < vn; vi++)
                    if( ch[Ni][vi] != ch[Nj][vi] ){ puts("Fegla Won"); goto ed; }
            }

        Ans = 0;
        vn = ch[0].size();

        for(int vi = 0; vi < vn; vi++)
        {
            for(int Ni = 0; Ni < N; Ni++)
                A[Ni] = amt[Ni][vi];

            sort(A, A+N);

            int p = A[N/2];

            for(int Ni = 0; Ni < N; Ni++)
                Ans += abs(A[Ni]-p);
        }

        printf("%d\n", Ans);
        ed:;
    }
}
