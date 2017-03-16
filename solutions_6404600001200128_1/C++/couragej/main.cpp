#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 10005;//数据规模，可修改

int m[N];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cases;
    scanf ("%d", &cases);
    for(int cas = 1; cas <= cases; cas ++) {
        int n;
        scanf ("%d", &n);
        int y = 0, z = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &m[i]);
        }
        int num = 0;
        for (int i = 1; i < n; i++) {
            if (m[i - 1] > m[i]) {
                y += m[i - 1] - m[i];
            }
            num = max(num, m[i - 1] - m[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            if(m[i] <= num) {
                z += m[i];
            }
            else {
                z += num;
            }
        }


        printf ("Case #%d: %d %d\n", cas, y, z);
    }

    return 0;
}
