#include <iostream>

using namespace std;

int main() {
    freopen("mush.in", "r", stdin);
    freopen("mush.out", "w", stdout);

    int T, t;
    cin >> T;
    for (t = 0; t < T; t++) {
        int N, ni[1005], i;
        cin >> N;
        for (i = 0; i < N; i++) {
            cin >> ni[i];
        }
        int sumA = 0, max = 0, sumB = 0;
        for (i = 1; i < N; i++) {
            int a = ni[i - 1] - ni[i];
            if (a > 0) sumA += a;
            if (max < a) max = a;
        }
        for (i = 0; i < N - 1; i++) {
            if (max > ni[i]) sumB += ni[i];
            else sumB += max;
        }

        cout << "Case #" << t + 1 << ": " << sumA << " " << sumB << endl;
    }

    return 0;
}