#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 1000
int a[N + 1];
int main()
{
    int tc,t;
    freopen("C:\\Users\\dell\\Downloads\\inputa.txt","r",stdin);
    freopen("C:\\Users\\dell\\Desktop\\temp\\CODING\\REPOSITORY\\GCJ\\2015\\Round 1A\\outputA.txt","w",stdout);
    scanf("%d",&tc);
    for(t = 1 ; t<=tc ; t++)
    {
        int ans1 =0,ans2=0;
        int n,i,mx=0;
        scanf("%d",&n);
        for(i = 1 ; i<=n ; i++)
        {
            scanf("%d",&a[i]);
        }
        for(i = 2 ; i<=n ; i++)
        {
            mx = max(mx,a[i-1]-a[i]);
            if(a[i-1] > a[i]) ans1 = ans1 + a[i-1] - a[i];
        }
        for(i = 1 ; i<n ; i++)
        {
            ans2 = ans2 + min(a[i],mx);
        }


        // Printing Starts here for the Test Case
        printf("Case #%d: ",t);
        // Print the result of the code here
        printf("%d %d",ans1,ans2);
        //Don't do anything after this.
        printf("\n");
    }
    return 0;
}
