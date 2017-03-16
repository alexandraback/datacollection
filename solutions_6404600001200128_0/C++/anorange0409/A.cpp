#include <iostream>
#include <cstdio>
using namespace std;
int a[10000], n;
int main()
{
    freopen("A-small-attempt0.in", "r",stdin);
    freopen("A-small.out", "w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans1=0,ans2=0;
        int m = 0;
        for (int i = 1; i < n; i++)
            if (a[i]<a[i-1])
            {
                ans1+=a[i-1]-a[i];
                if (a[i-1] - a[i]>m)
                    m = a[i-1] - a[i];
            }
        for (int i = 0; i < n-1; i++) {
            if (a[i] < m) ans2+=a[i];
            else ans2+=m;
        }
        printf("Case #%d: %d %d\n",o,ans1,ans2);
    }
}
