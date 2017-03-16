#include<cstdio>
#include<cstring>

int t,q1,a[4],q2,b[4],ans;

void solve()
{
    int i,j,k;
    ans=0;
    for(i=1;i<=4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i==q1)
                scanf("%d",a+j);
            else
                scanf("%*d");
        }
    }
    scanf("%d",&q2);
    for(i=1;i<=4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i==q2)
                scanf("%d",b+j);
            else
                scanf("%*d");
        }
    }
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(a[i]==b[j])
            {
                ans++;
                k=a[i];
            }
    printf("Case #%d: ",++t);
    if(ans==1)
        printf("%d\n",k);
    else if(ans>1)
        puts("Bad magician!");
    else
        puts("Volunteer cheated!");
}

int main()
{
    scanf("%*d");
    while(~scanf("%d",&q1))
        solve();
    return 0;
}
