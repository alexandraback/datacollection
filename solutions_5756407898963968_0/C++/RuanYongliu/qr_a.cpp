#include <iostream>
#include <set>
using namespace std;

int main() {
    int T, i = 1;
    for (cin >> T; T; --T, ++i) {
        int c;
        set<int> first, second;
        cin >> c;
        for (int i = 1; i <= 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                int number;
                cin >> number;
                if (i == c) {
                    first.insert(number);
                }
            }
        }
        cin >> c;
        for (int i = 1; i <= 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                int number;
                cin >> number;
                if (i == c && first.find(number) != first.end()) {
                    second.insert(number);
                }
            }
        }
        switch(second.size()) {
            case 0:
                cout << "Case #" << i << ": Volunteer cheated!" << endl;
                break;
            case 1:
                cout << "Case #" << i << ": " << *second.begin() << endl;
                break;
            default:
                cout << "Case #" << i << ": Bad magician!" << endl;
        }
    }
    return 0;
}
