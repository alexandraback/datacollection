#include <iostream>
#include <set>
using namespace std;

int main()
{
    int first[4][4], second[4][4];
    int T, r1, r2;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> r1; r1 -= 1;
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                cin >> first[r][c];
            }
        }
        cin >> r2; r2 -= 1;
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                cin >> second[r][c];
            }
        }
        set<int> cards;
        for (int c = 0; c < 4; c++) {
            cards.insert(first[r1][c]);
        }
        int hits = 0, card;
        for (int c = 0; c < 4; c++) {
            if (cards.find(second[r2][c]) != cards.end()) {
                card = second[r2][c];
                hits++;
            }
        }
        cout << "Case #" << t << ": ";
        if (hits == 1) {
            cout << card << '\n';
        }
        else if (hits == 0) {
            cout << "Volunteer cheated!\n";
        }
        else {
            cout << "Bad magician!\n";
        }
    }
    cout << flush;
    return 0;
}