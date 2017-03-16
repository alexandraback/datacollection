#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double degree[6005];
int p[3005][2];
double pi;

double getdegree(int x, int y)
{
    if (x == 0)
    {
        if (y > 0)
        {
            return pi / 2;
        }
        else
        {
            return pi * 3 / 2;
        }
    }
    
    if (y == 0)
    {
        if (x > 0)
        {
            return 0;
        }
        else
        {
            return pi;
        }
    }
    
    long long int x2 = x;
    x2 *= x;
    long long int y2 = y;
    y2 *= y;
    double r = sqrt(x2 + y2);
    double th = acos(x / r);
    if (y < 0)
    {
        th = 2 * pi - th;
    }
    return th;
}

int comp(const void *x, const void *y)
{
    if ((*(double*)x) > (*(double*)y))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    /*
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);*/
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    
    pi = acos(-1.0);
    int cases;
    scanf("%d", &cases);
    for (int c = 1; c <= cases; c++)
    {
        int N;
        scanf("%d", &N);
        for (int i = 1; i <= N; i++)
        {
            scanf("%d %d", &p[i][0], &p[i][1]);
        }
        
        printf("Case #%d:\n", c);
        if (N == 1)
        {
            printf("0\n");
        }
        else
        {
        for (int index = 1; index <= N; index++)
        {
            int num = 0;
            for (int i = 1; i <= N; i++)
            {
                if (i != index)
                {
                    double de = getdegree(p[i][0] - p[index][0], p[i][1] - p[index][1]);
                    degree[num] = de;
                    degree[num + 1] = de + pi * 2;
                    num += 2;
                }
            }
            //for (int i = 0; i < num; i++) printf("%.3f ", degree[i] * 180 / pi);printf("\n");
            qsort(degree, num, sizeof(double), comp);
            
            int ans = 1;
            int cnum = 1;
            int last = 0;
            int next = 1;
            for (;;)
            {
                if (next == num)
                {
                    break;
                }
                if (degree[next] < degree[last] + pi + 1e-9)
                {
                    cnum++;
                    next++;
                }
                else
                {
                    cnum--;
                    last++;
                }
                
                if (cnum > ans)
                {
                    ans = cnum;
                }
            }
            printf("%d\n", N - 1 - ans);
        }
        }
    }
    return 0;
}
