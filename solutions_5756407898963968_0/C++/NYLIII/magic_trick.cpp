#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;


int main() {
    //ifstream ifs("/Users/Raffaele/Desktop/CodeJam/2014/magic_trick/A-small-attempt0.in");
    //ofstream ofs("/Users/Raffaele/Desktop/CodeJam/2014/magic_trick/A-small-attempt0.out");
    
    int T;
    cin >> T;
    int g1[4][4];
    int g2[4][4];
    for (int test = 1; test <= T; test++) {
        int row1, row2;
        cin >> row1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> g1[i][j];
            }
        }
        cin >> row2;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> g2[i][j];
            }
        }
        unordered_set<int> nums;
        for (int i = 0; i < 4; i++) {
            nums.insert(g1[row1 - 1][i]);
        }
        int cnt = 0, last = 0;
        for (int i = 0; i < 4; i++) {
            if (nums.count(g2[row2 - 1][i])) {
                cnt++;
                last = g2[row2 - 1][i];
            }
        }
        cout << "Case #" << test << ": ";
        if (cnt == 1) {
            cout << last << endl;
        } else if (cnt == 0) {
            cout << "Volunteer cheated!" << endl;
        } else {
            cout << "Bad magician!" << endl;
        }
    }
    return 0;
}



