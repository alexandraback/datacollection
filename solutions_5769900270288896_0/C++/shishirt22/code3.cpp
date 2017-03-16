#include<iostream>
#include<cstdio>
using namespace std;
int A[30][30];
int minfind(int a,int b,int c,int d,int N)
{
    if(N<=0)
    {
        int count=0,i,j;
        for(i=0;i<c;i++)
        {
            for(j=0;j<d;j++)
            {
                if(A[i][j]==1)
                {
                    if(j<d-1)
                    {
                        if(A[i][j+1]==1)
                            count++;
                    }
                    if(i<c-1)
                    {
                        if(A[i+1][j]==1)
                            count++;
                    }
                }
           //     cout<<A[i][j]<<" ";
            }
         //   cout<<endl;
        }
        //cout<<endl<<"*"<<endl;
        return count;
    }
    else
    {
        if(b>=d)
        {
            if(a>=c-1)
                return 1000000;
            else
                {
                    int ans1=0,ans2=0;;
            A[a+1][0]=1;
            ans1=minfind(a+1,1,c,d,N-1);
            A[a+1][0]=0;
            ans2=minfind(a+1,1,c,d,N);
            return min(ans1,ans2);
                }
        }
        else
        {
                    int ans1=0,ans2=0;
            A[a][b]=1;
            ans1=minfind(a,b+1,c,d,N-1);
            A[a][b]=0;
            ans2=minfind(a,b+1,c,d,N);
            return min(ans1,ans2);
        }
    }
}
int main()
{
    int t,i,ans,r,c,n,j,il;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d",&r,&c,&n);
        for(il=0;il<30;il++)
        {
            for(j=0;j<30;j++)
                A[il][j]=0;
        }
        ans=minfind(0,0,r,c,n);
        printf("Case #%d: %d\n",i,ans);
    }
}
