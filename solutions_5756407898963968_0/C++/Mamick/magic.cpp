#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getRow(int j) {
    int tmp;
    j = j - 1;
    vector<int> result;
    for (int i = 0; i < j; i++) {
        cin >> tmp >> tmp >> tmp >> tmp;
    }
    for (int i = 0; i < 4; i++) {
        cin >> tmp; result.push_back(tmp);
    }
    for (int i = j + 1; i < 4; i++) {
        cin >> tmp >> tmp >> tmp >> tmp;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t1, t2;
        cin >> t1;
        vector<int> r1 = getRow(t1);
        cin >> t2;
        vector<int> r2 = getRow(t2);
        vector<int> final(20);
        sort(r1.begin(), r1.end()); sort(r2.begin(), r2.end());
        vector<int>::iterator it = set_intersection(r1.begin(), r1.end(), r2.begin(), r2.end(), final.begin());
        final.resize(it - final.begin());
        cout << "Case #" << i << ": ";
        if (final.size() > 1) {
            cout << "Bad magician!";
        } else if (final.size() == 0) {
            cout << "Volunteer cheated!";
        } else {
            cout << final[0];
        }
        cout << endl;
    }
}