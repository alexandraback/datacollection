#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>

using namespace std;

#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;

int ma[1005];

int method1(int n) {
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(ma[i] < ma[i - 1])
            ans += ma[i - 1] - ma[i];
    }
    return ans;
}

int method2(int n) {
    int speed = 0;
    for(int i = 1; i < n; i++) {
        if(ma[i] < ma[i - 1])
            speed = max(speed, ma[i - 1] - ma[i]);
    }
    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(ma[i] <= speed) ans += ma[i];
        else ans += speed;
    }
    return ans;
}

int main() {
    int cn;
    scanf("%d", &cn);
    for(int ci = 1; ci <= cn; ci++) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &ma[i]);
        printf("Case #%d: %d %d\n", ci, method1(n), method2(n));
    }
    return 0;
}

