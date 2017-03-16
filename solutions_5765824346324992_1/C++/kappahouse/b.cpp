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

// B. Haircut

int doit(long long N, vector <long long> m)
{
    long long lo = -1;
    long long hi = 1LL << 50;
    while (hi > lo + 1) {
        long long count = 0;
        long long mid = (lo + hi) / 2;
        vector <int> open;
        for (int i = 0; i < m.size(); i++) {
            count += (mid + m[i] - 1) / m[i];
            if (mid % m[i] == 0) {
                open.push_back(i + 1);
            }
        }
        if (N - count <= 0) {
            hi = mid;
        } else if (N - count > open.size()) {
            lo = mid;
        } else {
            return open[N - 1 - count];
        }
    }
    return -1;
}

int main()
{
    string line;

    int cases;
    cin >> cases;

    for (int caseno = 1; caseno <= cases; caseno++) {
        long long B, N;
        cin >> B >> N;
        vector <long long> m(B);
        for (int i = 0; i < B; i++) {
            cin >> m[i];
        }
        cout << "Case #" << caseno << ": " << doit(N, m) << endl;
    }

    return 0;
}
