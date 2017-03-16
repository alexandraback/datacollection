#include <bits/stdc++.h>
using namespace std;
int n,m,k;
void sol()
{
    if(k<=(n*m+1)/2)
    {
        puts("0");
        return;
    }
    if(n>m)
        swap(n,m);
    if(n==1)
    {
        printf("%d\n",m-1-(m-k)*2);
    }
    else if(n%2+m%2<2)
    {
        int remove=n*m-k;
        int cur=n*(m-1)+m*(n-1);
        int min4=(n-2)*(m-2)/2;
        int min2=2;
        int min3=n*m/2-min2-min4;
        if(remove<=min4)
            printf("%d\n",cur-remove*4);
        else if(remove<=min4+min3)
            printf("%d\n",cur-min4*4-(remove-min4)*3);
        else
            printf("%d\n",cur-min4*4-min3*3-(remove-min4-min3)*2);
    }
    else
    {
        int remove=n*m-k;
        int cur=n*(m-1)+m*(n-1);
        int min4=((n-2)*(m-2)+1)/2;
        int min2=4;
        int min3=(n*m+1)/2-min2-min4;
        int ans;
        if(remove<=min4)
            ans=cur-remove*4;
        else if(remove<=min4+min3)
            ans=cur-min4*4-(remove-min4)*3;
        else
            ans=cur-min4*4-min3*3-(remove-min4-min3)*2;
        min4=((n-2)*(m-2))/2;
        min2=0;
        min3=n*m/2-min2-min4;
        if(remove<=min4)
            ans=min(ans,cur-remove*4);
        else if(remove<=min4+min3)
            ans=min(ans,cur-min4*4-(remove-min4)*3);
        else
            ans=min(ans,cur-min4*4-min3*3-(remove-min4-min3)*2);
        printf("%d\n",ans);
    }
}
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d %d %d",&n,&m,&k);
        printf("Case #%d: ",cas);
        sol();
    }
    return 0;
}
