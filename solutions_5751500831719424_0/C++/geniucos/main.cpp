#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int l,i,j,k,pt,T,n,nr[109],x[109][109],y[109][109],s[109],v[109],cost;
char sir[109];
int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
int C()
{
    int S=0,mini=1000000;
    sort(v+1,v+n+1);
    for(i=1;i<=n;i++)
        s[i]=s[i-1]+v[i];
    for(i=1;i<=n;i++)
    {
        S=v[i]*i-s[i];
        S+=s[n]-s[i]-v[i]*(n-i);
        if(S<mini) mini=S;
    }
    return mini;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&T);
while(T)
{
    pt++;
    T--;
    printf("Case #%d: ",pt);
    scanf("%d\n",&n);
    for(i=1;i<=n;i++)
    {
        gets(sir+1);
        l=strlen(sir+1);
        nr[i]=0;
        for(j=1;j<=l;j++)
        {
            for(k=j;k<=l;k++)
                if(sir[k]!=sir[j]) break;
            k--;
            x[i][++nr[i]]=sir[j];
            y[i][nr[i]]=k-j+1;
            j=k;
        }
    }
    for(i=2;i<=n;i++)
        if(nr[i]!=nr[1]) break;
    if(i<=n)
    {
        printf("Fegla Won\n");
        continue;
    }
    for(j=1;j<=nr[1];j++)
    {
        for(i=2;i<=n;i++)
            if(x[i][j]!=x[1][j]) break;
        if(i<=n) break;
    }
    if(j<=nr[1])
    {
        printf("Fegla Won\n");
        continue;
    }
    cost=0;
    for(j=1;j<=nr[1];j++)
    {
        for(i=1;i<=n;i++)
            v[i]=y[i][j];
        cost+=C();
    }
    printf("%d\n",cost);
}
return 0;
}
