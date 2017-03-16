#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int x = 0;  x < t; ++x) {
        cout << "Case #" << x + 1 << ": ";
        int n;
        cin >> n;
        vector<int> m(n, 0);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
            sum += m[i];
        }
        for (int i = 0; i < n; ++i) {
            assert(m[i] * 2 <= sum);
        }
        while (m[0] != m[1]) {
            int a = 0;
            int x = m[0];
            for (int i = 1; i < n; ++i) {
                if (m[i] > x) {
                    x = m[i];
                    a = i;
                }
            }
            cout << char('A' + a) << ' ';
            --m[a];
        }
        while (n > 2) {
            int a = 2;
            int x = m[2];
            for (int i = 2; i < n; ++i) {
                if (m[i] > x) {
                    x = m[i];
                    a = i;
                }
            }
            if (m[a] == 0)
                break;
            cout << char('A' + a) << ' ';
            --m[a];
        }

        for (int i = 0; i < m[0]; ++i)
            cout << "AB ";
        cout << '\n';
    }
    return 0;
}
