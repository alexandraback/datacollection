#include<bits/stdc++.h>
#define MP make_pair
#define MQ(a,b,c,d) make_pair(make_pair(a,b),make_pair(c,d))
#define PB push_back
#define X first
#define Y second

using namespace std;
char maps[20][20];
int x[20];
int result[20];
int r,c,n;
int mn=99999999;
void gen(int idx,int cot)
{
    int i,j;
    //printf("%d %d\n",idx,cot);
    if(idx>r*c)
        return;
    if(idx==r*c&&cot==n)
    {
        int sum=0;
        for(i=0;i<r*c;i+=c)
        {
            for(j=0;j<c;j++)
            {
                maps[i/c][j]=result[i+j];
                //printf("%d",result[i+j]);
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                //maps[i/c][j]=result[i+j];
                if(maps[i][j]==1)
                {
                    if(maps[i+1][j]==1)
                        sum++;
                    if(maps[i][j+1]==1)
                        sum++;
                }
                //printf("%d",maps[i][j]);
            }
            //printf("\n");
        }
        //printf("%d\n",sum);
        mn=min(mn,sum);
        return;
    }
    if(cot+1<=n){
        result[idx]=1;
        gen(idx+1,cot+1);
    }
    result[idx]=0;
    gen(idx+1,cot);
}
int main()
{
    //freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,t,i,j,k;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        mn=99999999;
        memset(maps,0,sizeof maps);
        scanf("%d %d %d",&r,&c,&n);
        printf("Case #%d: ",t);
        if(n==0)
        {
            printf("0\n");
            continue;
        }
        gen(0,0);
        printf("%d\n",mn);
    }
}

