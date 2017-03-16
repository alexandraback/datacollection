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
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    int dmx = 0;
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        dmx = max(dmx, t[i-1] - t[i]);
        if (t[i] < t[i-1]) {
            sum += t[i-1] - t[i];
        }
    }
    int cur = 0;
    for (int i = 0; i + 1 < n; ++i) {
        cur += min(dmx, t[i]);
    }
    cout << sum << " " << cur << endl;
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


