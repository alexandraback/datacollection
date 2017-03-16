#include <iostream>

using namespace std;

int main() {
    int T, P1, P2, map[4][4], map2[4][4];

    cin >> T;

    for (int i = 1; i <= T; i++) {
        int code = 2, number = -1;

        cin >> P1; P1--;

        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                cin >> map[j][k];

        cin >> P2; P2--;

        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                cin >> map2[j][k];

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (map[P1][j] == map2[P2][k]) {
                    if (number == -1) {
                        code = 0;
                        number = map[P1][j];
                    } else {
                        code = 1;
                        break;
                    }
                }
            }
        }

        cout << "Case #" << i << ": ";
        if (code == 0) cout << number;
        if (code == 1) cout << "Bad magician!";
        if (code == 2) cout << "Volunteer cheated!";
        cout << endl;
    }

    return 0;
}
/** Created by freedomofkeima */
