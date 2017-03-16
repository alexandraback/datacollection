#include <iostream>
#include <cstdio>
#include <string>
#include <set>

using namespace std;

const int N = 4;

int a[N][N], b[N][N], used[N * N + 1];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y;
        for (int j = 1; j <= N * N; j++)
            used[j] = 0;
        cin >> x;
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                cin >> a[j][k];
        for (int j = 0; j < N; j++)
            used[a[x - 1][j]] = 1;
        cin >> y;
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                cin >> b[j][k];
        int k = 0, last = -1;
        for (int j = 0; j < N; j++) {
            if (used[b[y - 1][j]]) {
                k++;
                last = b[y - 1][j];
            }
        }
        cout << "Case #" << i + 1 << ": ";
        if (k == 0)
            cout << "Volunteer cheated!" << endl;
        else if (k == 1)
            cout << last << endl;
        else
            cout << "Bad magician!" << endl;
    }
    return 0;
}
