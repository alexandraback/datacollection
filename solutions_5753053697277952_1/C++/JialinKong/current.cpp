#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;
    
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        int people = 0;
        vector<int> p(n, 0);
        int first = INT_MIN, first_index = -1;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            people += p[i];
            if (p[i] > first) {
                first = p[i];
                first_index = i;
            }
        }
        cout << "Case #" << t << ": ";
        while (first > 1) {
            int second = INT_MIN, second_index = -1;
            for (int i = 0; i < n; ++i) {
                if (i != first_index && p[i] > second) {
                    second = p[i];
                    second_index = i;
                }
            }
            if (first - second >= 2) {
                p[first_index] -= 2;
                cout << (char)('A' + first_index) << (char)('A' + first_index) << " ";
            } else {
                --p[first_index];
                --p[second_index];
                cout << (char)('A' + first_index) << (char)('A' + second_index) << " ";
            }
            people -= 2;
            first = p[0];
            first_index = 0;
            for (int i = 1; i < n; ++i) {
                if (p[i] > first) {
                    first = p[i];
                    first_index = i;
                }
            }
        }
        if ((people & 1) == 1) {
            for (int i = 0; i < n; ++i) {
                if (p[i] == 1) {
                    --p[i];
                    cout << (char)('A' + i) << " ";
                    break;
                }
            }
        }
        int i = 0;
        while (i < n) {
            while (i < n && p[i] == 0) ++i;
            cout << (char)('A' + i);
            int j = i + 1;
            while (j < n && p[j] == 0) ++j;
            cout << (char)('A' + j) << " ";
            i = j + 1;
        }
        cout << endl;
    }
    return 0;
}
