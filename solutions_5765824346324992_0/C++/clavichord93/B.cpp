/**************************************************
 *        Problem:  GCJ 2015 Round 1A Problem B
 *         Author:  clavichord93
 *          State:  
 **************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_N = 1005;

int n, m;
int a[MAX_N];

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d %d", &n, &m);
        long long limit = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            limit = max(limit, (long long)a[i]);
        }

        if (n >= m) {
            printf("Case #%d: %d\n", cas, m);
        }
        else {
            limit *= m;
            
            long long l = 0, r = limit, ans = limit;
            while (l <= r) {
                long long mid = (l + r) >> 1;
                long long cnt = 0;
                for (int i = 0; i < n; i++) {
                    cnt += mid / a[i];
                }
                if (cnt + n >= m) {
                    r = mid - 1;
                    ans = mid;
                }
                else {
                    l = mid + 1;
                }
            }

            long long cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += (ans - 1) / a[i];
            }
            int res = 0;
            for (int i = 0; i < n; i++) {
                if (ans % a[i] == 0) {
                    cnt++;
                    if (cnt + n == m) {
                        res = i + 1;
                        break;
                    }
                }
            }
            printf("Case #%d: %d\n", cas, res);
        }
    }

    return 0;
}

/*
const int main_stack = 16;
char my_stack[128<<20];

int main() {
    __asm__("movl %%esp, (%%eax);\n"::"a"(my_stack):"memory");
    __asm__("movl %%eax, %%esp;\n"::"a"(my_stack + sizeof(my_stack) - main_stack):"%esp");
    Main();
    __asm__("movl (%%eax), %%esp;\n"::"a"(my_stack):"%esp");
    return 0;
}
*/
