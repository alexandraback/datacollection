#include <bits/stdc++.h>
using namespace std;
int cas;
int n;
int a[5050];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tt;
    scanf("%d",&tt);
    for (cas = 1; cas <= tt; cas++){
        scanf("%d",&n);
        memset(a,0,sizeof a);
        for (int i = 0; i < n; i++) scanf("%d",&a[i]);
        int ans1 = 0, ans2 = 0;
        int maxsub = 0;
        for (int i = 1; i < n; i++){
            if (a[i] < a[i-1]) {
                    ans1+=(a[i-1] - a[i]);
                    maxsub = max(maxsub,a[i-1] - a[i]);
            }
        }
        for (int i = 0; i < n-1; i++){
            if (a[i] < maxsub) ans2+=a[i];
            else ans2+=maxsub;
        }
        printf("Case #%d: %d %d\n",cas,ans1,ans2);
    }
    return 0;
}
