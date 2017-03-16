#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
#include <iterator>
#include <list>
#include <set>
#include <map>
#include <bitset>

using namespace std;

#define MEMSET(x,v) memset(x,v,sizeof(x))
template<class A, class B> inline bool mina(A &x, B y) {return (x > y)?(x=y,1):0;}
template<class A, class B> inline bool maxa(A &x, B y) {return (x < y)?(x=y,1):0;}
typedef long long int LL;

int main()
{
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        int N;
        scanf("%d", &N);

        int P[26];
        for(int i = 0; i < N; i++)
            scanf("%d", &P[i]);

        int sum = 0;
        for(int i = 0; i < N; i++)
            sum += P[i];

        printf("Case #%d:", t);
        while(sum > 0)
        {
            int maxCount = 0;
            int p = 0;
            for(int i = 0; i < N; i++)
            {
                if(P[i] > maxCount)
                {
                    maxCount = P[i];
                    p = i;
                }
            }

            printf(" %c", p+'A');
            P[p]--;
            sum--;

            for(int i = 0; i < N; i++)
            {
                if(P[i] > sum/2)
                {
                    printf("%c", i+'A');
                    P[i]--;
                    sum--;
                    break;
                }
            }
        }

        printf("\n");
    }
}
