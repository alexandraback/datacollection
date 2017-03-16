#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cassert>
#include <limits>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int grid1[4][4];
int grid2[4][4];

int main() {
    // ifstream in("sample.in");
    istream& in = cin;

    int T;
    in >> T;
    for (int t = 0; t != T; ++t) {
        int answer1;
        in >> answer1;
        bool cards1[17] = { 0 };
        
        for (int r = 0; r != 4; ++r) {
            for (int c = 0; c != 4; ++c) {
                int x;
                in >> x;
                if (r+1 == answer1) {
                    cards1[x] = true;
                }
            }
        }

        int answer2;
        in >> answer2;
        bool cards2[17] = { 0 };
        
        for (int r = 0; r != 4; ++r) {
            for (int c = 0; c != 4; ++c) {
                int x;
                in >> x;
                if (r+1 == answer2) {
                    cards2[x] = true;
                }
            }
        }

        vector<int> answers;
        for (int x = 1; x <= 16; ++x) {
            if (cards1[x] && cards2[x]) {
                answers.push_back(x);
            }
        }

        if (answers.empty()) {
            cout << "Case #" << (t+1) << ": Volunteer cheated!" << endl;
        } else if (answers.size() == 1) {
            cout << "Case #" << (t+1) << ": " << answers[0] << endl;
        } else {
            cout << "Case #" << (t+1) << ": Bad magician!" << endl;
        }
    }
    return 0;
}
