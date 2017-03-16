#include <cstring>
#include <iostream>
using namespace std;

int x[4][4], y[4][4], z[17];

int main() {
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        int A, B;
        cin >> A; --A;
        for (int i = 0; i < 4; ++i)
         for (int j = 0; j < 4; ++j) cin >> x[i][j];
        cin >> B; --B;
        for (int i = 0; i < 4; ++i)
         for (int j = 0; j < 4; ++j) cin >> y[i][j];
        memset(z, 0, sizeof(z));
        for (int j = 0; j < 4; ++j) {
            ++z[x[A][j]];
            ++z[y[B][j]];
        }
        int ans = 0;
        for (int i = 1; i <= 16; ++i) ans += (z[i] == 2);
        cout << "Case #" << times << ": ";
        if (ans == 0) {
            cout << "Volunteer cheated!" << endl;
            continue;
        }
        if (ans > 1) {
            cout << "Bad magician!" << endl;
            continue;
        }
        for (int i = 1; i <= 16; ++i) 
         if (z[i] == 2) cout << i << endl;
    }
    return 0;
}
