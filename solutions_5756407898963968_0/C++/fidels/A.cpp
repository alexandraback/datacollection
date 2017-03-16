#include <iostream>
using namespace std;

int main() {
    int T, t, i, j, k, c[2][4][4], C[2], RES;

    cin >> T;
    for (t=1; t<=T; t++) {
        for (k=0; k<2; k++) {
            cin >> C[k]; C[k]--;
            for (i=0; i<4; i++) for (j=0; j<4; j++) cin >> c[k][i][j];
        }

        RES = 0;
        for (i=0; i<4; i++) for (j=0; j<4; j++) if (c[0][C[0]][i] == c[1][C[1]][j]) RES++;
        cout << "Case #" << t << ": ";
        if (RES > 1) cout << "Bad magician!" << endl;
        else if (RES == 0) cout << "Volunteer cheated!" << endl;
        else for (i=0; i<4; i++) for (j=0; j<4; j++) if (c[0][C[0]][i] == c[1][C[1]][j]) cout << c[0][C[0]][i] << endl;
    }

    return 0;
}
