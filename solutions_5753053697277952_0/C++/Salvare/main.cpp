#include<bits/stdc++.h>
using namespace std;


int a[50];
char ans[50000];
bool ok(int f,int n)
{
    a[f]--;
    int z=0,sum=0;
    for(int i=0;i<n;sum+=a[i++])
        z=max(z,a[i]);
    a[f]++;
    if(z>sum-z)return 0;
    else return 1;
}
int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,sum=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i),sum+=a[i];
        int k=0;
        while(sum)
        {
            int f=-1,z=-1;
            for(int j=0;j<n;j++)
                if(f==-1||a[f]<a[j])f=j;
            for(int j=0;j<n;j++)
                if(j!=f)
                {
                    if(z==-1||a[z]<a[j])z=j;
                }
            if(z==-1)z=f;

            a[f]--;
            ans[k++]=' ';
            ans[k++]=f+'A';
            sum--;
            if(a[z]&&ok(z,n))
            {
                a[z]--;
                ans[k++]=z+'A';
                sum--;
            }
        }
        ans[k]=0;
        printf("Case #%d:%s\n",ti++,ans);
    }
	return 0;
}
