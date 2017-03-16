#include <iostream>

using namespace std;

int main() {
    int t; // number of test cases
    int curCase = 1;
    int board1[4][4], board2[4][4];
    int firstAns, secondAns;

    cin >> t;
    while (t--) {
        cin >> firstAns;
        firstAns--;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
               cin >> board1[i][j];
            }
        }
        cin >> secondAns;
        secondAns--;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
               cin >> board2[i][j];
            }
        }

        int count = 0;
        int guess = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (board1[firstAns][i] == board2[secondAns][j]) {
                    count++;
                    guess = board1[firstAns][i];
                }
            }
        }

        if (count == 1) {
            cout << "Case #" << curCase << ": " << guess << endl;
        } else if (count == 0) {
            cout << "Case #" << curCase << ": " << "Volunteer cheated!" << endl;
        } else if (count > 1) {
            cout << "Case #" << curCase << ": " << "Bad magician!" << endl;
        }
        
        curCase++;
    }
    
    return 0;
}

