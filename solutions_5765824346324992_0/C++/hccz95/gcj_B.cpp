#include <cstdio>
#include <algorithm>
using namespace std;
inline int gcd(int a, int b){
    int c;
    while (b){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}
int n, m;
int t[2000], next[2000];
int main(){

freopen("B.out", "w", stdout);
freopen("B.in", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int T=1; T<=test; T++){
        scanf("%d %d", &m, &n);
        int div = 0;
        int lcm = 1;
        for (int i=1; i<=m; i++){
            scanf("%d", &t[i]);
            lcm *= t[i];
            div = gcd(div, t[i]);
        }
        lcm /= div;
        int sum = 0;
        for (int i=1; i<=m; i++)
            sum += lcm/t[i];
//        printf("sum = %d\n", sum);
        n %= sum;
        if (n == 0) n = sum;
        for (int i=1; i<=m; i++)
            next[i] = 0;
        for (int i=1; i<=n; i++){
            int mark = 1;
            for (int j=1; j<=m; j++) if (next[j] < next[mark]){
                mark = j;
            }
            next[mark] += t[mark];
            if (i == n){
                printf("Case #%d: %d\n", T, mark);
                break;
            }
        }
    }
    return 0;
}
