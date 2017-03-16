#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

void resolver(int caso)
{
    int menor=-1, i, r, c, n, q, j, la, ca, k, tot, ok;
    int mat[16][16];
    scanf("%d %d %d", &r, &c, &n);
    for(i=0;i<65536;i++)
    {
        memset(mat, 0, sizeof(mat));
        q = 0;
        ok = 1;
        for(j=0;j<r*c && ok==1;j++)
        {
            //printf("%d %d %d\n", i, j, (1<<j)&i);
            if(((1<<j)&i)!=0)
            {
                //printf("%d - %d\n", i, j);
                //system("PAUSE");
                q++;
                la = j/c;
                ca = j%c;
                mat[la][ca] = 1;
                //if(la>=r || ca>=c)
                //    ok = 0;
            }
        }
        if(q==n && ok==1)
        {
            tot = 0;
            for(j=0;j<r;j++)
            {
                for(k=0;k<c;k++)
                {
                    //if(i==127)
                    //    printf("%d", mat[j][k]);
                    if(mat[j][k]==1)
                    {
                        if(j+1<r && mat[j+1][k]==1)
                            tot++;
                        if(k+1<c && mat[j][k+1]==1)
                            tot++;
                    }
                }
                //if(i==127)
                //    printf("\n");
            }
            //if(i==127)
            //    system("PAUSE");
            if(menor==-1 || tot<menor)
            {
                menor = tot;
            }
        }
    }
    printf("Case #%d: %d\n", caso, menor);
}

int main()
{
    int t, i;
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        resolver(i);
    }
    return 0;
}
