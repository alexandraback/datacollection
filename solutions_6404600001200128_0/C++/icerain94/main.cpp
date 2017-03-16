#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<string>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define mod 100007
int a[1005];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)    scanf("%d",a+i);
        int fin1=0,fin2=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]<a[i-1])  fin1+=a[i-1]-a[i];
        }
        int temp=0;
        for(int i=1;i<n;i++)
        {
            if(a[i-1]-a[i]>temp)
            {
                temp=a[i-1]-a[i];
            }
        }
        for(int i=0;i<n-1;i++)
        {
            fin2+=min(temp,a[i]);
        }
        printf("Case #%d: %d %d\n",cas++,fin1,fin2);
    }
}
