#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits.h>
#include <iostream>
#define MAXN 10100
using namespace std;
typedef long long LL;
int n;
int a[MAXN];
int main() {
    freopen("in.in", "r", stdin);
    freopen("Aout.out", "w", stdout);
    int t;
    int numCase = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        int ans1 = 0;
        int ans2 = 0;
        int temp = 0;
        for(int i = 0; i < n - 1; i++) {
            if(a[i] > a[i + 1]) {
                ans1 += (a[i] - a[i + 1]);
            } else
                ans1 += 0;
        }
        for(int i = 0; i < n - 1; i++) {
            if(a[i] > a[i + 1]) {
                temp = max(temp, a[i] - a[i + 1]);
            }
        }
        for(int i = 0; i < n - 1; i++) {
            if(a[i] >= temp) ans2 += temp;
            else
                ans2 += a[i];
        }
        printf("Case #%d: %d %d\n", numCase++, ans1, ans2);
    }
    return 0;
}
