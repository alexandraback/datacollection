#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

#define mp(a, b) make_pair(a, b)
#define all(a) a.begin(), a.end()

typedef unsigned long long int int64;

bool cmp(const pair<int, char> a, const pair<int, char> b) {
    return a.first > b.first;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, sum = 0;
        vector < pair<int, char> > a;
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
            sum += a[i].first;
        }

        cout << "Case #" << t << ":";
        while (sum > 0) {
            sort(all(a), cmp);
            if (sum != 2) {
                if ((a[0].first != 1) && (a[0].first == a[1].first)) {
                    cout << " " << (char)('A' + a[0].second)
                            << (char)('A' + a[1].second);
                    a[0].first--;
                    a[1].first--;
                    sum -= 2;
                    if (a[1].first == 0) {
                        return -1;
                    }
                } else {
                    cout << " " << (char)('A' + a[0].second);
                    --sum;
                    --a[0].first;
                }
            } else {
                cout << " " << (char)('A' + a[0].second)
                        << (char)('A' + a[1].second);
                sum -= 2;
                if (a[1].first == 0) {
                    return -1;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
