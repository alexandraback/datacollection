#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int t,r,c,n,i,power,j,k,l,counter,temp,res;
    int mat[20][20];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&r,&c,&n);
        res=1000000;
        power=r*c;
        power=1<<power;
        for(j=0;j<power;j++)
        {
            k=0;
            l=j;
            temp=0;
            while(l)
            {
                mat[k/c][k%c]=l%2;
                temp+=l%2;
                l/=2;
                k++;
            }
            while(k<r*c)
            {
                mat[k/c][k%c]=0;
                k++;
            }
            if(temp==n)
            {
                temp=0;
                for(k=0;k<r;k++)
                {
                    for(l=0;l<c;l++)
                    {
                        if(mat[k][l]==1)
                        {
                            if(l<c-1&&mat[k][l+1]==1)
                                temp++;
                            if(k<r-1&&mat[k+1][l]==1)
                                temp++;
                        }
                    }
                }
                res=min(res,temp);
            }
        }
        printf("Case #%d: %d\n",i,res);
    }
    return 0;
}
