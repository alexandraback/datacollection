#include <iostream>
#include <unordered_set>
using namespace std;

void printOutput(int idx, string text) {
    cout << "Case #" << idx << ": " << text << endl;
}

void handleCase(int idx) {
    int first_choose, second_choose;
    cin >> first_choose;
    int a, b, c, d;
    int x, y, z, l;
    unordered_set<int> nums;
    for (int i = 1; i <= 4; ++i) {
        cin >> a >> b >> c >> d;
        if (i == first_choose) {
            nums.insert(a);
            nums.insert(b);
            nums.insert(c);
            nums.insert(d);
        }
    }
    cin >> second_choose;
    int count = 0;
    int answer;
    for (int i = 1; i <= 4; ++i) {
        cin >> a >> b >> c >> d;
        if (i == second_choose) {
            if (nums.find(a) != nums.end()) {
                ++count;
                answer = a;
            }
            if (nums.find(b) != nums.end()) {
                ++count;
                answer = b;
            }
            if (nums.find(c) != nums.end()) {
                ++count;
                answer = c;
            }
            if (nums.find(d) != nums.end()) {
                ++count;
                answer = d;
            }
        }
    }
    if (count == 1) {
        cout << "Case #" << idx << ": " << answer << endl;
    } else if (count == 0) {
        cout << "Case #" << idx << ": Volunteer cheated!" << endl;
    } else {
        cout << "Case #" << idx << ": Bad magician!" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        handleCase(i);
    }
}
