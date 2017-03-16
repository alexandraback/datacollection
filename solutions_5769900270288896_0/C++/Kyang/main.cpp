#include <iostream>
#include <fstream>
#define DEBUG
using namespace std;
int r,c,n;
int b[1000][17],d[1000][17];
int cc[1000],e[1000];
int finda(int p,int j)
{
    int ru[4]={-c,c,-1,1};
    int an=0;
    for (int i=0;i<4;i++)
    if (j+ru[i]>0 && j+ru[i]<=r*c)
    {
        if (j%c==1 && i==2) continue;
        if (j%c==0 && i==3) continue;
        if (c==1 && (i==2 || i==3)) continue;
        if (b[p][j+ru[i]]>0) an++;
    }
    return an;
}
int bfs()
{
    int len=1;
    b[1][0]=r*c;
    for (int i=1;i<=r*c;i++)
        b[1][i]=1;
    cc[1]=(r-1)*c+r*(c-1);
    for (int i=r*c;i>n;i--)
    {
        int p=1;
        for (int j=1;j<=len;j++)
            if (cc[j]<cc[p])
                p=j;
        int k=0;
        for (int j=1;j<=r*c;j++)
            if (b[p][j]>0)
            {
                memcpy(d[++k],b[p],sizeof(int)*17);
                d[k][j]=0;
                e[k]=cc[p]-finda(p,j);
            }
        len=k;
        memcpy(b,d,sizeof(b));
        memcpy(cc,e,sizeof(cc));
    }
    int p=1;
    for (int i=1;i<=len;i++)
    if (cc[i]<cc[p])
        p=i;
    return cc[p];
}
int main()
{
    int t,iCase=0;
    FILE *out=fopen("1.out","w");
    #ifdef DEBUG
        fstream in("1.in");
        in>>t;
        #else
        cin>>t;
    #endif // DEBUG
    while(t--)
    {
        #ifdef DEBUG
            in>>r>>c>>n;
            #else
            cin>>r>>c>>n;
        #endif // DEBUG
        if (n<=r*c/2)
        {
            fprintf(out,"Case #%d: %d\n",++iCase,0);
            //printf("Case #%d: %d\n",++iCase,0);
            continue;
        }
        int ans=bfs();
        fprintf(out,"Case #%d: %d\n",++iCase,ans);
        //printf("Case #%d: %d\n",++iCase,ans);
    }
    return 0;
}
