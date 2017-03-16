#include<stdio.h>
#include<queue>
using namespace std;
int bitcount(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=x%2;
        x/=2;
    }
    return ans;
}
int main()
{
    int t,test=1;
    scanf("%d",&t);
    while(t--)
    {
        int R,C,i,j,k;
        scanf("%d%d",&R,&C);
        int n=R*C,N,ans11=1000000000;
        scanf("%d",&N);
        for(i=0;i<(1<<n);i++)
        {
            if(bitcount(i)==N)
            {
                //printf("i=%d\n",i);
                bool s[200][200]={0};
                int val=0;
                for(j=0;j<n;j++)
                {
                    if(i&(1<<j))
                    {
                        int x=j/C,y=j-x*C;
                        //printf("x=%d y=%d j=%d\n",x,y,j);
                        s[x][y]=1;
                    }
                }
                for(j=0;j<R;j++)
                {
                    for(k=0;k<C;k++)
                    {
                        //printf("%d ",s[j][k]);
                        if(s[j][k])
                        {
                            if(s[j+1][k])
                                val++;
                            if(s[j][k+1])
                                val++;
                        }
                    }
                    //printf("\n");
                }
                if(val<ans11)
                    ans11=val;
            }
        }
        printf("Case #%d: %d\n",test,ans11);
        test++;
    }
    return 0;
}
