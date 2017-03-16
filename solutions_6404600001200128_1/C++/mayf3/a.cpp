#include <cstdio>

const int N = 2333;

int n;
int v[N];

int main(){
    int test;
    scanf("%d", &test);
    for(int cas = 1; cas <= test; cas++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }
        int ans1 = 0, ans2 = 0, tmp = 0;
        for(int i = 0; i < n - 1; i++){
            if (v[i] < v[i + 1]) continue;
            ans1 += v[i] - v[i + 1];
            if (v[i] - v[i + 1] > tmp) tmp = v[i] - v[i + 1];
        }
        for(int i = 0; i < n - 1; i++){
            if (tmp < v[i]) ans2 += tmp;
            else ans2 += v[i];
        }
        printf("Case #%d: %d %d\n", cas, ans1, ans2);
    }
}
