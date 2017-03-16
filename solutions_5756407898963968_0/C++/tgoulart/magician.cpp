#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int T;

    cin >> T;
    for (int t=1; t <= T; ++t) {
        int m[4][4];
        int a1;
        int a2;
        vector <int> candidates1;
        vector <int> candidates2;
        set <int> possibleSolutions;

        cin >> a1;
        for (int i=0; i < 4; ++i) {
            for (int j=0; j < 4; ++j) {
                cin >> m[i][j];
            }
        }
        for (int j=0; j < 4; ++j) {
            candidates1.push_back(m[a1-1][j]);
        }

        cin >> a2;
        for (int i=0; i < 4; ++i) {
            for (int j=0; j < 4; ++j) {
                cin >> m[i][j];
            }
        }
        for (int j=0; j < 4; ++j) {
            candidates2.push_back(m[a2-1][j]);
        }

        for (int i=0; i < candidates1.size(); ++i) {
            for (int j=0; j < candidates2.size(); ++j) {
                if (candidates1[i] == candidates2[j]) {
                    possibleSolutions.insert(candidates1[i]);
                }
            }
        }

        cout << "Case #" << t << ": ";
        if (possibleSolutions.size() == 0) {
            cout << "Volunteer cheated!" << endl;
        } else if (possibleSolutions.size() > 1) {
            cout << "Bad magician!" << endl;
        } else {
            cout << (*possibleSolutions.begin()) << endl;
        }
    }

    return 0;
}