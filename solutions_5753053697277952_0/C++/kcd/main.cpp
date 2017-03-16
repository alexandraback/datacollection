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
    vector<pair<int, char>> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i].first;
        f[i].second = 'A' + i;
    }
    sort(f.rbegin(), f.rend());
    while (f[0].first > f[1].first) {
        cout << f[0].second << ' ';
        --f[0].first;
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 0; j < f[i].first; ++j) {
            cout << f[i].second << ' ';
        }
    }
    for (int i = 0; i < f[0].first; ++i) {
        cout << f[0].second << f[1].second << ' ';
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        Solution();
//        cerr << "Case #" << i + 1 << ": Done!" << endl;
    }

    return 0;
}


