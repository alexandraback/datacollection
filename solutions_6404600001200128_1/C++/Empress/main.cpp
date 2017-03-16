#include <bits/stdc++.h>
using namespace std;

int a[1005];
int main()
{
    freopen("A-large (1).in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, ca=1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int ans=-INT_MAX;
        for(int i=0;i<n;i++)
        {
            scanf("%d", &a[i]);
            if(i)
                ans=max(ans, a[i-1]-a[i]);
        }
        int ans1=0, ans2=0;
        for(int i=1;i<n;i++)
            if(a[i-1]>a[i])
                ans1+=a[i-1]-a[i];
        for(int i=0;i<n-1;i++)
            if(a[i]<ans)
                ans2+=a[i];
            else
                ans2+=ans;
        printf("Case #%d: %d %d\n", ca++, ans1, ans2);
    }
    return 0;
}
