#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
struct abc
{
        char c;
        int b;
};
int compare(const void* a, const void* b)
{
        return -((*(struct abc*)a).b-(*(struct abc*)b).b);
}
int main()
{
        int t, cn;
        scanf("%d", &t);
        for(cn=1; cn<=t; cn++)
        {
                int n, i;
                struct abc p[27];
                scanf("%d", &n);
                for(i=0;i<n;i++)
                {
                        scanf("%d", &p[i].b);
                        p[i].c=i+'A';
                }
                qsort(p, n, sizeof(struct abc), compare);
                printf("Case #%d:", cn);
                while(p[0].b!=0)
                {
                        if(p[0].b!=0 && p[1].b!=0 && p[2].b==0)
                        {
                                printf(" %c%c", p[0].c, p[1].c);
                                p[0].b--;
                                p[1].b--;
                                continue;
                        }
                        printf(" %c", p[0].c);
                        p[0].b--;
                        qsort(p, n, sizeof(struct abc), compare);
                }
                printf("\n");
        }
        return 0;
}
