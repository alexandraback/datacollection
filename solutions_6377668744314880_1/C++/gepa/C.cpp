#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector <int> doit() {
    int N;
    cin >> N;
    vector <long long> x(N, 0);
    vector <long long> y(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    vector <int> res(N, N);
    if (N == 1) {
        res[0] = 0;
        return res;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int a = 0;
            int b = 0;
            long long d0 = x[i] * y[j] - x[j] * y[i];
            long long dx = x[i] - x[j];
            long long dy = y[i] - y[j];
            for (int k = 0; k < N; k++) {
                long long d = d0 + x[k] * dy - y[k] * dx;
                if (d < 0) a++;
                if (d > 0) b++;
            }
            res[i] = min(res[i], a);
            res[i] = min(res[i], b);
            res[j] = min(res[j], a);
            res[j] = min(res[j], b);
        }
    }
    return res;
}

int main(int argc, char *argv[]) {
    int C;
    cin >> C;
    for (int i = 1; i <= C; i++) {
        vector <int> res = doit();
        cout << "Case #" << i << ":" << endl;
        for (int j = 0; j < res.size(); j++) {
            cout << res[j] << endl;
        }
    }
    return 0;
}
