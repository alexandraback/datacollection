#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": ";
        int N;
        cin >> N;
        vector<int> m(N);
        for (int j = 0; j < N; ++j) {
            cin >> m[j];
        }

        int eaten1 = 0;
        int maxdrop = 0;
        for (int j = 1; j < N; ++j) {
            if (m[j] < m[j-1]) {
                eaten1 += m[j-1] - m[j];
                maxdrop = max(m[j-1]-m[j], maxdrop);
            }
        }
        cout << eaten1 << " ";

        int eaten2 = 0;
        for (int j = 0; j < N-1; ++j) {
            eaten2 += (m[j] >= maxdrop) ? maxdrop : m[j];
        }
        cout << eaten2 << endl;
    }
    return 0;
}
