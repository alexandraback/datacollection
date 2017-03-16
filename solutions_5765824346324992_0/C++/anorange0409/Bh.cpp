#include <iostream>
#include <cstdio>
using namespace std;
long long a[10000];
int n;
long long m;
long long gcd( long long a, long long b){
    if (b ==0) return a;
    else return gcd(b, a % b);
}
int main()
{
    freopen("B-small-attempt2.in", "r",stdin);
    freopen("B-small_heh.out", "w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++)
    {
        cin >> n >> m;
        long long mul = 1;
        long long g = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mul *= a[i];
            g = gcd(g, a[i]);
        }
        mul /= g;
        int b = 0;
        for (int i = 0; i < n; i++)
            b += mul / a[i];
        if(m%b!=0)
            m %= b;
        else
            m = b;
        int ans = -1;
        for (int i = 0; i < mul; i++) {
            for (int j = 0; j < n; j++)
                if (i % a[j] == 0) {
                    m--;
                    if (m==0) {ans = j + 1; break;}
                }
            if (ans != -1) break;
        }
        printf("Case #%d: %d\n",o,ans);
    }
}
