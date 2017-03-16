#include<stdio.h>
#include<algorithm>
using namespace std;
int r,c,minna;
int noisy[20][20];
void gen(int ro,int col,int idx,int sum)
{
    int ct=0;
    if(ro==r&&col==c)
    {
        if(idx==0)
            minna=min(sum,minna);
        return;
    }
    if(idx==0)
        return;
    if(col==c)
    {
        gen(ro+1,1,idx,sum);
        noisy[ro+1][1]=1;
        if(noisy[ro][1]==1)
            ct++;
        gen(ro+1,1,idx-1,sum+ct);
        noisy[ro+1][1]=0;
    }
    else
    {
        gen(ro,col+1,idx,sum);
        noisy[ro][col+1]=1;
        if(noisy[ro][col]==1)
            ct++;
        if(noisy[ro-1][col+1]==1)
            ct++;
        gen(ro,col+1,idx-1,sum+ct);
        noisy[ro][col+1]=0;
    }
}
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,n,i=0;
    scanf("%d",&t);
    while(t--)
    {
        i++;
        minna=1000000005;
        scanf("%d%d%d",&r,&c,&n);
        gen(1,1,n,0);
        noisy[1][1]=1;
        gen(1,1,n-1,0);
        noisy[1][1]=0;
        if(minna==1000000005)
            printf("Case #%d: 0\n",i);
        else
            printf("Case #%d: %d\n",i,minna);
    }
    scanf(" ");
}
