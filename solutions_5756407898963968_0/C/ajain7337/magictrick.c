#include<stdio.h>

int main()
{
    int t,a1,a2,arr1[4][4],ans[17],count,fin;
    int i,j,k;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&a1);
        a1--;
        for(j=0;j<4;j++)
        {
            for(k=0;k<4;k++)
            {
                scanf("%d",&arr1[j][k]);
            }
        }
        for(j=0;j<17;j++)
        {
            ans[j]=0;
        }
        for(j=0;j<4;j++)
        {
            ans[arr1[a1][j]]=1;
          //  printf("%d ",ans[arr1[a1][j]]);
        }
        //printf("\n");
        scanf("%d",&a2);
        a2--;
        for(j=0;j<4;j++)
        {
            for(k=0;k<4;k++)
            {
                scanf("%d",&arr1[j][k]);
            }
        }
        for(j=0;j<4;j++)
        {
            ans[arr1[a2][j]]++;
          //    printf("%d ",ans[arr1[a2][j]]);
        }
        //printf("\n");
        count=0;
        for(j=1;j<17;j++)
        {
            if(ans[j]==2)
            {
                count ++;
                fin=j;
             //   printf("%d = %d \n",j,ans[j]);

            }
        }
        if(count==1) printf("Case #%d: %d\n",i+1,fin);
        else if(count>1) printf("Case #%d: Bad magician!\n",i+1);
        else printf("Case #%d: Volunteer cheated!\n",i+1);
    }
}
