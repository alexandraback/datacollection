#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[5][5],b[5][5],r1,r2,ans,t;
main()
{
        scanf("%d",&t);
        for(int r=1;r<=t;r++)
        {
                scanf("%d",&r1);
                for(int i=1;i<=4;i++)
                {
                        for(int j=1;j<=4;j++)
                        {
                                scanf("%d",&a[i][j]);
                        }
                }
                scanf("%d",&r2);
                for(int i=1;i<=4;i++)
                {
                        for(int j=1;j<=4;j++)
                        {
                                scanf("%d",&b[i][j]);
                        }
                }
                ans=0;
                for(int i=1;i<=4;i++)
                {
                        for(int j=1;j<=4;j++)
                        {
                                if(a[r1][i]==b[r2][j])
                                {
                                        if(ans==0) ans=a[r1][i];
                                        else ans=17;
                                }
                        }
                }
                printf("Case #%d: ",r);
                if(ans==0)
                printf("Volunteer cheated!\n");
                else if(ans==17)
                printf("Bad magician!\n");
                else
                printf("%d\n",ans);
        }
}
                                
                
