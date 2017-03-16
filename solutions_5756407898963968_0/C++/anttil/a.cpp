#include <iostream>

using namespace std;

int t;

int main() {
    cin >> t;
    for (int x = 1; x <= t; x++) {
        int c[16+1] = {0};
        for (int q = 0; q < 2; q++) {
            int r;
            cin >> r;
            r--;
            int n[4][4];
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    cin >> n[i][j];
                }
            }
            for (int i = 0; i < 4; i++) c[n[r][i]]++;
        }
        int z = 0, v;
        for (int i = 1; i <= 16; i++) {
            if (c[i] == 2) {z++; v = i;}
        }
        cout << "Case #" << x << ": ";
        if (z == 0) {
            cout << "Volunteer cheated!\n";
        } else if (z > 1) {
            cout << "Bad magician!\n";
        } else {
            cout << v << "\n";
        }
    }
}
