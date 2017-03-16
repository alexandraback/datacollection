#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";

        int n;
        cin >> n;
        vector<int> num(n);
        int total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
            total += num[i];
        }

        while (total > 0) {
            int maxId = 0;
            for (int i = 1; i < n; ++i) {
                if (num[i] > num[maxId]) maxId = i;
            }

            int other = -1;
            for (int i = 0; i < n; ++i) {
                if (num[i] == num[maxId] && i != maxId) {
                    other = i;
                    break;
                }
            }

            if (num[other] * 2 <= (total-1)) other = -1;

            printf("%c", 'A' + maxId);
            total--;
            num[maxId]--;
            if (other >= 0) {
                printf("%c", 'A' + other);
                 total--;
                 num[other]--;
            }
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
