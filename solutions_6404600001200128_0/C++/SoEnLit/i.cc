#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <cassert>
#include <map>
#define INF 0x3f3f3f3f
#define mem(a, b) memset((a), (b), sizeof(a))

using namespace std;

const double eps = 1e-8;
const long long mod = 1000000007ll;
const long long _3 =   333333336ll;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

long long fpow(long long a, long long b) {
    long long ret = 1;
    while(b) {
        if(b % 2 == 1) {
            ret *= a;
            ret %= mod;
        }
        a = a * a;
        a %= mod;
        b /= 2;
    }
    return ret;
}

double sqr(double a) {
    return a * a;
}

const double pi = acos(-1.0);

int n;
int num[100009];

int MAIN() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    int ans1 = 0, ans2 = 0;
    int rate = 0;
    for(int i = 1; i < n; i++) {
        if(num[i] < num[i - 1]) {
            ans1 += num[i - 1] - num[i];
            rate = max(rate, num[i - 1] - num[i]);
        }
    }
    for(int i = 1; i < n; i++) {
        ans2 += min(rate, num[i - 1]);
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}

int main() {
    int cases;
    scanf("%d", &cases);
    int cc = 1;
    while(cases--) {
//    while(~scanf("%d", &n)) {
    
        printf("Case #%d: ", cc++);
        MAIN();
    }
    return 0;
}
