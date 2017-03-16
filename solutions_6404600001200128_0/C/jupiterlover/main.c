#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cases, num, max_num, res1, res2, max_diff;
    int i, j, k;
    int a[10000];

    freopen("1.in","r",stdin);
    freopen("1.out","w+",stdout);

    scanf("%d ",&cases);

    for(i = 0;i<cases;i++){
        scanf("%d ",&max_num);
        res1 = 0;
        res2 = 0;
        num = 0;
        max_diff = 0;
        scanf("%d",&a[0]);
        for(j=1;j<max_num;j++){
            scanf("%d",&a[j]);
            num = a[j-1] - a[j];
            if( num > 0 )
                res1 += num;
            if( num > max_diff)
                max_diff = num;
        }

        for(j=0;j<max_num-1;j++){
            if( a[j] < max_diff )
            {
                res2 += a[j];
            }
            else
            {
                res2 += max_diff;
            }
        }

       // res = (max_num-res)>0?max_num-res:0;
        printf("Case #%d: %ld %ld\n",i+1,res1, res2);
    }

    return 0;
}
