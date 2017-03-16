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

// A. Mushroom Monster

int main()
{
    string line;

    int cases;
    cin >> cases;

    for (int caseno = 1; caseno <= cases; caseno++) {
        int N;
        cin >> N;

        vector <int> m(N);
        int method1 = 0;
        int method2 = 0;
        int rate = 0;
        cin >> m[0];
        for (int i = 1; i < N; i++) {
            cin >> m[i];
            method1 += max(0, m[i - 1] - m[i]);
            rate = max(rate, m[i - 1] - m[i]);
        }
        for (int i = 1; i < N; i++) {
            method2 += min(rate, m[i - 1]);
        }
        cout << "Case #" << caseno << ": " << method1 << " " << method2 << endl;
    }

    return 0;
}
