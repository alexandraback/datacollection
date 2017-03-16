#include <cstdio>
#include <iostream>

using namespace std;

const int MAX_N = 1007;

int T;
int a[MAX_N];
int n;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("a.out", "w", stdout);
    
    cin >> T;
    for (int cs = 1; cs <= T; ++cs) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int ans1 = 0, spd2 = 0, ans2 = 0;
        for (int i = 1; i < n; ++i) {
            ans1 += max(a[i - 1] - a[i], 0);
            spd2 = max(spd2, a[i - 1] - a[i]);
        }
        for (int i = 0; i < n - 1; ++i) {
            ans2 += min(spd2, a[i]);
        }

        cout << "Case #" << cs << ": " << ans1 << " " << ans2 << endl;
    }

    return 0;
}
