#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>
 
typedef long long ll;
 
using namespace std;
 
int cmp(const void *_a, const void *_b)
{
    int *a = (int *)_a;
    int *b = (int *)_b;
 
    return b[0] - a[0];
}
 
int p[26];
int q[26][2];
 
int main(void)
{
    int T;
 
    scanf("%d", &T);
 
    for (int t = 1; t <= T; t++)
    {
        int N;
         
        int sum = 0;
 
        scanf("%d", &N);
 
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &p[i]);
            sum += p[i];
        }
 
        printf("Case #%d:", t);
 
        while (sum > 0)
        {
            for (int i = 0; i < N; i++)
            {
                q[i][0] = p[i];
                q[i][1] = i;
            }
 
            qsort(q, N, sizeof(int[2]), cmp);
 
            if (sum > 3)
            {
                printf(" %c%c", q[0][1] + 'A', q[1][1] + 'A');
                p[q[0][1]]--;
                p[q[1][1]]--;
                sum -= 2;
            }
            else if (sum == 3)
            {
                printf(" %c", q[0][1] + 'A');
                p[q[0][1]]--;
                sum--;
            }
            else if (sum == 2)
            {
                if (q[0][0] == 1)
                {
                    printf(" %c%c", q[0][1] + 'A', q[1][1] + 'A');
                    p[q[0][1]]--;
                    p[q[1][1]]--;
                    sum -= 2;
                }
                else
                {
                    printf(" %c%c", q[0][1] + 'A', q[0][1] + 'A');
                    p[q[0][1]] -= 2;
                    sum -= 2;
                }
            }
            else
            {
                printf(" %c", q[0][1] + 'A');
                p[q[0][1]]--;
                sum--;
            }
        }
 
        printf("\n");
    }
}