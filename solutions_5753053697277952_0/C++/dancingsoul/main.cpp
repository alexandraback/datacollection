#include <bits/stdc++.h>
using namespace std;



typedef double DB;
typedef long long LL;

const int N = 26;


int b[N], p[N];

bool cmp(int i, int j) { return p[i] < p[j];}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int CAS, n;
    scanf("%d", &CAS);
    for (int cas = 1; cas <= CAS; cas++) {
        printf("Case #%d:", cas);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            b[i] = i;
        }
        sort(b, b + n, cmp);
        while (p[b[n - 1]] > p[b[n - 2]]) {
            p[b[n - 1]] -= 1;
            printf(" %c", b[n - 1] + 'A');

        }
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < p[b[i]]; j++) {
                printf(" %c", b[i] + 'A');
            }
        }
        for (int i = 0; i < p[b[n - 1]]; i++) {
            printf(" %c%c", b[n - 2] + 'A', b[n - 1] + 'A');
        }
        puts("");
    }


}
