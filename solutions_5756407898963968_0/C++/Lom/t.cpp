#include <algorithm>

#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include <iostream>


using namespace std;

int main(int argc, char* argv[]) {
    int numTests = 0;
    cin >> numTests;
    for (int test = 1; test <= numTests; ++test) {
        int ans1 = 0, ans2 = 0;
        int matches = 0, match = 0;
        set<int> r1;

        cin >> ans1;
        --ans1;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                int v = 0;
                cin >> v;

                if (i == ans1) {
                    r1.insert(v);
                }
            }
        }

        cin >> ans2;
        --ans2;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                int v = 0;
                cin >> v;

                if (i == ans2 && r1.find(v) != r1.end()) {
                    ++matches;
                    match = v;
                }
            }
        }

        cout << "Case #" << test << ": ";
        switch (matches) {
        case 0: {
            cout << "Volunteer cheated!" << endl;
            break;
        }

        case 1: {
            cout << match << endl;
            break;
        }

        default: {
            cout << "Bad magician!" << endl;
            break;
        }
        }
    }

    return 0;
}
