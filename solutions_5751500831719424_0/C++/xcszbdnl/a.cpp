#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAX_NUMBER = 107;
int pointer[MAX_NUMBER];
char input[MAX_NUMBER][MAX_NUMBER];
int number[MAX_NUMBER];
int n;

int f(int a) {
    return a < 0 ? -a : a;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int test_case;
    scanf("%d", &test_case);
    for (int case_number = 1; case_number <= test_case; case_number++) {
        scanf("%d", &n);
        memset(pointer, 0, sizeof(pointer));
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%s", input[i]);
        }
        int ans = 0;
        while (pointer[1] < strlen(input[1])) {
            memset(number, 0, sizeof(number));
            int cnt_char = input[1][pointer[1]];
            while (input[1][pointer[1]] == cnt_char) {
                number[1]++;
                pointer[1]++;
            }
            for (int i = 2; i <= n; i++) {
                for (; input[i][pointer[i]] == cnt_char; pointer[i]++) {
                    number[i]++;
                }
            }
            sort(number + 1, number + 1 + n);
            if (number[1] == 0) {
                flag = 1;
                break;
            }
            int mid = number[(n + 1) / 2];
            for (int i = 1; i <= n; i++) {
                ans = ans + f(number[i] - mid);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (pointer[i] != strlen(input[i])) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            printf("Case #%d: Fegla Won\n", case_number);
        }
        else {
            printf("Case #%d: %d\n", case_number, ans);
        }
    }
    return 0;
}
