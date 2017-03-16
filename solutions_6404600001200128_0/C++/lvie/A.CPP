#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1010;

int n, t;
int a[N];

int cal1(){
    int s = 0; t = 0;
    for(int i = 2; i <= n; i++)
        if (a[i] < a[i-1]) {
            s += a[i-1] - a[i];
            if (a[i-1] - a[i] > t) t = a[i-1] - a[i];
        }
    return s;
}

int cal2(){
    int s = 0, now = 0;
    for(int i = 1; i < n; i ++){
        if (a[i] < t) s += a[i];
            else s += t;
    }
    return s;
}

int main(){
    //freopen("A.txt", "r", stdin);
    freopen("A3.txt", "w", stdout);
    int T, cas = 0; scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        int s1 = cal1(), s2 = cal2();
        printf("Case #%d: %d %d\n", ++cas, s1, s2);
    }
    return 0;
}
