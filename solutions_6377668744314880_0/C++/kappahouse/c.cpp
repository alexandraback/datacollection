#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

// C. Logging

int doit(int p, int q, vector <int> &X, vector <int> &Y)
{
    long long a = Y[q] - Y[p];
    long long b = X[p] - X[q];
    long long c = (long long)X[q] * Y[p] - (long long)X[p] * Y[q];
    int plus = 0;
    int minus = 0;
    for (int i = 0; i < X.size(); i++) {
        if (a * X[i] + b * Y[i] + c > 0) {
            plus++;
        }
        if (a * X[i] + b * Y[i] + c < 0) {
            minus++;
        }
    }
    return min(plus, minus);
}

int main()
{
    int cases;
    cin >> cases;
    for (int caseno = 1; caseno <= cases; caseno++) {
        int N;
        cin >> N;
        vector <int> X(N), Y(N);
        for (int i = 0; i < N; i++) {
            cin >> X[i] >> Y[i];
        }
        cout << "Case #" << caseno << ":" << endl;
        for (int i = 0; i < N; i++) {
            int ret = N - 1;
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    ret = min(ret, doit(i, j, X, Y));
                }
            }
            cout << ret << endl;
        }
    }

    return 0;
}
