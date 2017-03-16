#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int N;
        cin >> N;
        vector<int> m;
        int maxDiff = 0;
        for (int j = 0; j < N; ++j) {
            int mm;
            cin >> mm;
            m.push_back(mm);
            if (j > 0) {
                int diff = m[j - 1] - m[j];
                if (maxDiff < diff) {
                    maxDiff = diff;
                }
            }
        }

        int totalY = 0, totalZ = 0;
        for (int j = 1; j < N; ++j) {
            if (m[j - 1] > m[j]) {
                totalY += m[j - 1] - m[j];
            }
        }

        for (int j = 0; j < N - 1; ++j) {
            if (m[j] < maxDiff) {
                totalZ += m[j];
            } else {
                totalZ += maxDiff;
            }
        }
        cout << "Case #" << i + 1 << ": " << totalY << " " << totalZ << endl;
    }
    return 0;
}
