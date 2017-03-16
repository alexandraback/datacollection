#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    freopen("A-small-attempt0.in.","r",stdin);
    freopen("Aans","w",stdout);
    int t, T, i, j, k, r, cnt, ans[4], tmp, pt;
    scanf("%d",&T);
    for ( t = 0 ; t < T ; t ++ )
    {
        scanf("%d",&r);
        for ( i = 0 ; i < 4 ; i ++ )
        {
            for ( j = 0 ; j < 4 ; j ++)
            {
                scanf("%d",&tmp);
                if ( i == r-1 ) ans[j] = tmp;
            }
        }

        scanf("%d",&r);
        cnt = 0;
        for ( i = 0 ; i < 4 ; i ++ )
        {
            for ( j = 0 ; j < 4 ; j ++ )
            {
                scanf("%d",&tmp);
                if ( i == r-1 )
                {
                    for ( k = 0 ; k < 4 ; k ++ )
                    {
                        if ( ans[k] == tmp )
                        {
                            cnt ++;
                            pt = tmp;
                        }
                    }
                }
            }
        }

        if ( cnt == 0 )
        {
            printf("Case #%d: Volunteer cheated!\n",t+1);
        }
        else if ( cnt == 1 )
        {
            printf("Case #%d: %d\n",t+1, pt);
        }
        else
        {
            printf("Case #%d: Bad magician!\n",t+1);
        }
    }

    return 0;
}
