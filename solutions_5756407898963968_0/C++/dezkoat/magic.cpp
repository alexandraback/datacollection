#include <iostream>
#include <string.h>

using namespace std;

bool set[20];
int table[5][5];

int main()
{
    int TC;
    cin >> TC;

    for (int i = 1; i <= TC; i++) {
        int row;

        memset(set, 0, sizeof(set));

        cin >> row;
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                cin >> table[j][k];

        for (int j = 0; j < 4; j++)
            set[table[row-1][j]] = 1;

        cin >> row;
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                cin >> table[j][k];

        int card = 0;
        int total = 0;
        for (int j = 0; j < 4; j++) {
            if (set[table[row-1][j]] == 1) {
                total++;
                card = table[row-1][j];
            }
        }

        if (total == 0) {
            cout << "Case #" << i << ": Volunteer cheated!" << endl;
        } else if (total == 1) {
            cout << "Case #" << i << ": " << card << endl;
        } else {
            cout << "Case #" << i << ": Bad magician!" << endl;
        }
    }

    return 0;
}
