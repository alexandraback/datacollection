#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void syntax(char** argv) {
    printf("Syntax: %s <filename>\n", argv[0]);
}

string get_result(int* row1, int* row2) {
    int number = 0;
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; j++) {
            if (row1[i] == row2[j]) {
                if (number) {
                    return "Bad magician!";
                }
                number = row1[i];
            }
        }
    }
    if (number) {
        ostringstream ss;
        ss << number;
        return ss.str();
    } else {
        return "Volunteer cheated!";
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        syntax(argv);
        return 1;
    }
    ifstream in;
    in.open(argv[1], ios::in);
    if (!in) {
        cerr << "Could not open file " << argv[1] << endl;
        return 1;
    }
    int numTestCases;
    in >> numTestCases;
    for (int i=0; i<numTestCases; ++i) {
        int row_chosen[2] = {0,0};
        int table[2][4][4];
        for (int j=0; j<2; ++j) {
           in >> row_chosen[j];
           for (int p=0; p<4; ++p) {
               for (int q=0; q<4; ++q) {
                   in >> table[j][p][q];
               }
           }
        }
        cout << "Case #" << i+1 << ": " << get_result(table[0][row_chosen[0]-1], table[1][row_chosen[1]-1]) << endl;
    }
    in.close();
    return 0;
}
