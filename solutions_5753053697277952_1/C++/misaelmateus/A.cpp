#include<bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
bool funcao(ii a, ii b){ return a.first < b.first;}
int main()
{
    int T;
    scanf("%d", &T);
    for(int l = 1; l <= T; l++)
    {
        printf("Case #%d:", l);
        int tot = 0, n;
        scanf("%d", &n);
        pair<int, int> s[n];
        for(int i = 0; i < n; i++){
            int aux;
            scanf("%d", &aux);
            s[i] = make_pair(aux, i);
            tot += aux;
        }

        while(tot > 0)
        {
            sort(s, s+n, funcao);
            int a = s[n-1].first, ai = s[n-1].second;
            int b = s[n-2].first, bi = s[n-2].second;
            s[n-1].first--;
            printf(" %c", (char)('A'+ai));
            tot--;
            if(tot > 0 && (n <= 2 || 2*s[n-3].first <= tot-1) )
            {
                printf("%c", (char)('A' + bi));
                tot--;
                s[n-2].first--;
            }
        }
        printf("\n");
    }
}
