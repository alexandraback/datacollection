#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 111;

char str[N][N];
char shorted[N][N];
int len[N];
int cnt[N][N];
int n;

void get_shorted(int i) {
    memset(cnt[i], 0, sizeof(cnt[i]));
    int sz = strlen(str[i]);
    len[i] = 0;
    shorted[i][len[i]++] = str[i][0];
    cnt[i][0] = 1;
    for (int j = 1; j < sz; j++) {
        if (str[i][j] != shorted[i][len[i] - 1]) {
            cnt[i][len[i]] = 1;
            shorted[i][len[i]++] = str[i][j];
        } else {
            cnt[i][len[i] - 1]++;
        }
    }
}

bool solve() {
    for (int i = 0; i < n; i++) { get_shorted(i); }
    for (int i = 1; i < n; i++) {
        if (len[i] != len[0]) return false;
        for (int j = 0; j < len[0]; j++) {
            if (shorted[0][j] != shorted[i][j]) return false;
        }
    }
    int ans = 0;
    for (int i = 0; i < len[0]; i++) {
        int mi = 1 << 20;
        for (int j = 1; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += abs(j - cnt[k][i]);
            }
            mi = min(sum, mi);
        }
        ans += mi;
    }
    cout << ans << endl;
    return true;
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> str[i];
        }
        cout << "Case #" << Case++ << ": ";
        if (!solve()) {
            cout << "Fegla Won" << endl;
        }
    }
    return 0;
}
