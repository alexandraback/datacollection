/* This program should be run with its input piped from the input file and its output piped to the output file. */

#include <iostream>

using namespace std;

int main() {
    int iNumTests;
    int iRow1, iRow2;
    int piCards1[4][4], piCards2[4][4];
    
    cin >> iNumTests;
    
    for (int test = 1; test <= iNumTests; ++test) {
        cin >> iRow1;
        --iRow1;
        
        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                cin >> piCards1[row][col];
            }
        }
        
        cin >> iRow2;
        --iRow2;
        
        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                cin >> piCards2[row][col];
            }
        }
        
        int iCard = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (piCards1[iRow1][i] == piCards2[iRow2][j]) {
                    if (iCard != 0) {
                        cout << "Case #" << test << ": Bad magician!" << endl;
                        goto next_test;
                    }
                    iCard = piCards1[iRow1][i];
                    break;
                }
            }
        }
        
        if (iCard == 0) {
            cout << "Case #" << test << ": Volunteer cheated!" << endl;
        } else {
            cout << "Case #" << test << ": " << iCard << endl;
        }
        
        next_test:;
    }
    
    return 0;
}
