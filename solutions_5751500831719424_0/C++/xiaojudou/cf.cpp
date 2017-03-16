#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;


int t;
int a[110][110],b[110][110];
int tx[110];
int ans,tt[110][110];
int n;
char s[200];

int gao(int x,int y)
{
    int t1=tx[x],t2=tx[y];
    if(t1!=t2)return -1;
    int pans=0;
    for(int i=0;i<t1;++i)
    {
        if(a[x][i]!=a[y][i])return -1;

        pans+=abs(b[x][i]-b[y][i]);
    }
    return pans;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&t);
    int __=0;
    while(t--){
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(tx,0,sizeof(tx));getchar();
        int tm=0;
        for(int i=0;i<n;++i)
        {

            scanf("%s",s);
            //cout<<"S:::"<<s<<endl;
            char c='*';
            tm=-1;
            for(int j=0;j<strlen(s);++j)
            {
                if(s[j]!=c)
                {
                    tm++;
                    a[i][tm]=s[j]-'a'+1;
                    b[i][tm]++;
                    c=s[j];
                }else{
                    b[i][tm]++;
                }
            }
            tx[i]=tm+1;
        }

//        for(int i=0;i<n;++i)
//        {
//            for(int j=0;j<tx[i];++j)
//             cout<<a[i][j]<<" ";
//            cout<<endl;
//        }




        ans=1<<30;
        int tp=0;

        memset(tt,0,sizeof(tt));
        for(int i=0;i<n;++i)
            if(ans>=0)
            for(int j=i+1;j<n;++j)
            {
                tt[i][j]=tt[j][i]=gao(i,j);
                if(tt[i][j]<0)
                {
                    //cout<<a[i]<<"::::"<<a[j]<<endl;
                    ans=-1;break;
                }
            }
        for(int i=0;i<n;++i)
        {
            tp=0;
            for(int j=0;j<n;++j)
                tp+=tt[i][j];
            if(tp<ans)ans=tp;
        }
        if(ans>=0)
        printf("Case #%d: %d\n",++__,ans);
        else
        printf("Case #%d: Fegla Won\n",++__);
    }
    return 0;
}
