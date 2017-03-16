#include <cstdio>

typedef long long LL;

const int N = 2333;

int n, m;
int v[N];

LL calc(LL tim){
    LL ret = 0;
    for(int i = 0; i < n; i++){
        ret += (tim + v[i] - 1) / v[i];
    }
    return ret;
}

int main(){
    int test;
    scanf("%d", &test);
    for(int cas = 1; cas <= test; cas++){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }
        LL l = 0, r = 1000000000000000LL, mid;
        while(l + 1 < r){
            mid = l + (r - l) / 2;
            if (calc(mid) < m) l = mid;
            else r = mid;
        }
        int add = m - calc(r - 1);
        int ans = -1;
        for(int i = 0; i < n; i++){
            if (r % v[i] == 1 || v[i] == 1){
                add--;
                if (add == 0){
                    ans = i + 1;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
}
