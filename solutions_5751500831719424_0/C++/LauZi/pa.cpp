#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

int cost(int arr[101]) {
    int ans = 0;

    int l = 0;
    for (; arr[l] != 0; ++l) ;

    std::sort(arr, arr + l);

    int pvt = arr[l/2];

    for (int i = 0; i < l; ++i)
        ans += std::abs(arr[i] - pvt);

    return ans;
}

int jizz() {
    static char arr[101][101];

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%s", arr[i]);

    char chrs[101] = {0};
    int a = 0;
    for (int i = 0; arr[0][i] != '\0'; ) {
        chrs[a++] = arr[0][i];
        for (i += 1; arr[0][i] == arr[0][i-1]; i += 1);
    }

    int dp[101][101] = {0};
    for (int i = 0; i < n; ++i) {
        int j = 0;
        for (int k = 0; k < a; ++k) {
            while (arr[i][j] == chrs[k]) dp[k][i] += 1, j += 1;
            if (dp[k][i] == 0) return -1;
        }
        if (arr[i][j] != '\0') return -1;
    }

    int ans = 0;

    for (int i = 0; dp[i][0] != 0; ++i)
        ans += cost(dp[i]);

    return ans;
}

int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        int ans = jizz();

        if (ans == -1) {
            puts("Fegla Won");
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}
