// Magic Card

#include <cstdio>
#include <cstring>
#define NMAX 17
#define LMAX 5
int tests, touch[NMAX];

void iter()
{
    int x, y;
    scanf("%d", &x);
    for (int i = 1; i < LMAX; i++)
        for (int j = 1; j < LMAX; j++)
        {
            scanf("%d", &y);
            if (x == i)
                touch[y]++;
        }
}

int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    
    scanf("%d", &tests);
    int cand, who;
    for (int test_no = 1; test_no <= tests; test_no++)
    {
       memset(touch, 0, sizeof(touch));
       iter();
       iter();
       
       cand = 0;
       for (int i = 1; i < NMAX; i++)
           if (touch[i] == 2)
               cand++, who = i;
        
       printf("Case #%d: ", test_no);
       if (cand >= 2)
           printf("Bad magician!\n");
       else if (cand == 1)
                printf("%d\n", who);
            else if (cand == 0)
                printf("Volunteer cheated!\n");
    }
    return 0;
}
