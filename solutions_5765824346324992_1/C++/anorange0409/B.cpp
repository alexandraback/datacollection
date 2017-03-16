#include <iostream>
#include <cstdio>
using namespace std;
long long a[10000];
int n;
long long m;
long long get(long long t) {
    long long re = 0;
    for (int i = 0; i < n; i++)
        {
            re += (t/a[i])+1;
        }
    return re;
}
long long gcd( long long a, long long b){
    if (b ==0) return a;
    else return gcd(b, a % b);
}
int main()
{
    freopen("B-large.in", "r",stdin);
    freopen("B-large.out", "w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++)
    {
        cin >> n >> m;
        long long g = 1;
        long long l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i]>r) r =a[i];
            g = gcd(g, a[i]);
        }
        r*=m;
        while (l+1<r) {
            long long mid = (l+r)/2;
            long long k = get(mid);
            if (k >= m) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        l=r;
        while (get(l) >= m) l--;
        int k = get(l);

        while (l > 0 && get(l-1)==k)
            l--;
        l++;
        int ans=-1;
        while (ans == -1) {
            for (int i = 0; i < n; i++)
                if (l%a[i]==0) {
                    k++;
                    if (k == m) {
                        ans=i+1;
                        break;
                    }
                }
            l+=g;
        }

        printf("Case #%d: %d\n",o,ans);
    }
}
