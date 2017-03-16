#include <iostream>

using namespace std;

int t, n, v[26];

bool two() {
    int c = 0;
    for (int i = 0; i < n; ++i) c += !!v[i];
    return c == 2;
}

int main() {
    cin >> t;
    for (int C = 0; C ++< t;) {
        cin >> n;
        int t = 0;
        for (int i = 0; i < n; ++i) cin >> v[i], t += v[i];
        cout << "Case #" << C << ": ";
        while (1) {
            int m = 0, mi;
            for (int i = 0; i < n; ++i) if (v[i] > m) m = v[i], mi = i;
            if (m == 1) {
                if (t % 2) --v[mi], --t, cout << (char)('A' + mi) << ' ';
                for (int i = mi; i < n; ++i) if (v[i]) --v[i], cout << (char)('A' + i) << (t-- % 2 ? " " : "");
                break;
            }
            else if (m * 2 == t && two()) {
                for (int i = 0; i < n; ++i) if (v[i]) --v[i], --t, cout << (char)('A' + i);
                cout << ' ';
            }
            else {
                --v[mi], --t;
                cout << (char)('A' + mi) << ' ';
            }
        }
        cout << '\n';
    }
}

