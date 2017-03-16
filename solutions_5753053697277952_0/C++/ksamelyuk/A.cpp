#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <iomanip>
#include <queue>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, char> pci;

int main() {
    std::ios_base::sync_with_stdio(false);
    int tests_count;
    cin >> tests_count;
    for (int test_index = 0; test_index < tests_count; ++test_index) {
        int n;
        cin >> n;
        vector<pci> a(n);
        char cc = 'A';
        int sum = 0;
        for (pci& x : a) {
            cin >> x.first;
            x.second = cc++;
            sum += x.first;
        }
        sort(a.rbegin(), a.rend());
        cout << "Case #" << test_index + 1 << ": ";
        if (sum & 1) {
            cout << a[0].second << ' ';
            --a[0].first;
            sort(a.rbegin(), a.rend());
            --sum;
        }
        while (sum) {
            cout << a[0].second;
            --a[0].first;
            sort(a.rbegin(), a.rend());
            cout << a[0].second << ' ';
            --a[0].first;
            sort(a.rbegin(), a.rend());
            sum -= 2;
        }
        cout << "\n";
    }
    return 0;
}
