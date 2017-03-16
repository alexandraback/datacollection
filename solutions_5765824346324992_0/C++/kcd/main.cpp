#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>

using namespace std;

typedef long long LL;
template<class T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<class T> inline T Sqr(const T& x) { return x * x; }




void Solution() {
    int B;
    LL n;
    cin >> B >> n;
    vector<LL> b(B);
    for (int i = 0; i < B; ++i) {
        cin >> b[i];
    }
    if (n <= B) {
        cout << n << endl;
        return;
    }
    LL l = 0, r = 1000 * 1000LL * 1000LL * 1000LL * 1000LL;
    while (r - l > 1) {
        LL x = (l + r) / 2;
        LL cur = 0;
        for (int i = 0; i < B; ++i) {
            cur += x / b[i] + 1;
        }
        if (cur < n) {
            l = x;
        } else {
            r = x;
        }
    }
    LL got = 0;
    for (int i = 0; i < B; ++i) {
        got += (r + b[i] - 1) / b[i];
    }
    LL remain = n - got;
    for (int i = 0; i < B; ++i) {
        if (r % b[i] == 0) {
            --remain;
            if (remain == 0) {
                cout << i + 1 << endl;
                return;
            }
        }
    }
    cout << "FUCK" << endl;
    exit(1);
}


int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        float startTime = clock() / CLOCKS_PER_SEC;
        cout << "Case #" << i + 1 << ": ";
        Solution();
        float endTime = clock() / CLOCKS_PER_SEC;
        cerr << "Test #" << i + 1 << ": elapsed time is " << endTime - startTime;
        cerr << endl;
    }

    return 0;
}


