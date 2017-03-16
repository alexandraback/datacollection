/**************************************************
 *        Problem:  GCJ 2015 Round 1A Problem A
 *         Author:  clavichord93
 *          State:  
 **************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_N = 1005;

int n;
int a[MAX_N];

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T ; cas++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int ans1 = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                ans1 += a[i - 1] - a[i];
            }
        }
        int ans2 = 0;
        int rate = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                rate = max(rate, a[i - 1] - a[i]);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            ans2 += min(a[i], rate);
        }

        printf("Case #%d: %d %d\n", cas, ans1, ans2);
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
