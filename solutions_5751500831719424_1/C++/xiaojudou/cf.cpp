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
int tmp[110];

void gao()
{
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
        {
            if(tx[i]!=tx[j])
            {
                ans=-1;return;
            }
        }
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
        {
            for(int k=0;k<tx[i];++k)
            if(a[i][k]!=a[j][k])
            {
                ans=-1;return;
            }
        }
    int pans=1<<30;
    int ptmp;
    for(int i=0;i<tx[0];++i)
    {
        for(int j=0;j<n;++j)
        {
            tmp[j]=b[j][i];
        }
        sort(tmp,tmp+n);
        pans=1<<30;
        for(int j=tmp[0];j<=tmp[n-1];++j)
        {
            ptmp=0;
            for(int k=0;k<n;++k)
                ptmp+=abs(tmp[k]-j);
            if(ptmp<pans)pans=ptmp;
        }
        ans+=pans;
    }
}
int main()
{
    freopen("A-large.in","r",stdin);
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

        ans=0;
        gao();
        if(ans>=0)
        printf("Case #%d: %d\n",++__,ans);
        else
        printf("Case #%d: Fegla Won\n",++__);
    }
    return 0;
}
