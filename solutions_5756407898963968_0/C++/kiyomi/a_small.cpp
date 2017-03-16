#include <iostream>
#include <cstdio>

using namespace std;

int t, ans[10], m[10][10][10];

int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    ios::sync_with_stdio(false);

    cin >> t;

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> ans[j];
            for (int k = 0; k < 4; k++)
                for (int l = 0; l < 4; l++)
                    cin >> m[j][k][l];
            --ans[j];
        }
        int cnt = 0;
        int num = 0;
        for (int j = 0; j < 4; j++) {
            int a = m[0][ans[0]][j];
            for (int k = 0; k < 4; k++) {
                int b = m[1][ans[1]][k];
                if (a == b) {
                    cnt++;
                    num = a;
                }
            }
        }
        cout << "Case #" << i << ": ";
        if (cnt == 1)
            cout << num;
        else if (cnt == 0)
            cout << "Volunteer cheated!";
        else
            cout << "Bad magician!";
        cout << "\n";
    }

    return 0;

}
