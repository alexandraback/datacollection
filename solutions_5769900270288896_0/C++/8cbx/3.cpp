#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int maz[20][20];
int chose[20];
int main()
{
    int t,cases,n,r,c;
    while(scanf("%d",&t)!=EOF)
    {
        cases=0;
        while(t--)
        {
            cases++;
            int maxx=99999999;
            scanf("%d%d%d",&r,&c,&n);
            int now=1<<(r*c);
            now--;
            while(now>=0)
            {
                memset(chose,0,sizeof(chose));
                int tmp=now;
                int i=1;
                int coun=0;
                while(tmp>0)
                {
                    if(tmp%2==1)
                    {
                        chose[i]=1;
                        coun++;
                    }
                    tmp/=2;
                    i++;
                }
                //if(coun==n)printf("--%d\n",coun);
                int ans=0;
                memset(maz,0,sizeof(maz));
                if(coun==n)
                {
                    int tim=1;
                    for(int k=1; k<=r; k++)
                    {
                        for(int j=1; j<=c; j++)
                        {
                            maz[k][j]=chose[tim];
                            tim++;
                            if(maz[k][j]==1)
                            {
                                if(maz[k-1][j]==1)
                                {
                                    ans++;
                                }
                                if(maz[k][j-1]==1)
                                {
                                    ans++;
                                }
                                if(maz[k+1][j]==1)
                                {
                                    ans++;
                                }
                                if(maz[k][j+1]==1)
                                {
                                    ans++;
                                }

                            }
                            //printf("%d\n",ans);
                        }
                    }
                    /*printf("%d %d\n",ans,maxx);
                    for(int k=1; k<=r; k++)
                    {
                        for(int j=1; j<=c; j++)
                        {
                            printf("%d ",maz[k][j]);
                        }
                        printf("\n");
                    }*/
                    if(ans<maxx)
                    {
                        maxx=ans;
                    }
                }
                now--;
            }
            printf("Case #%d: %d\n",cases,maxx);
        }
    }
    return 0;
}
