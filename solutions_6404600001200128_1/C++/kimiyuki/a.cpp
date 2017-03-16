#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "utility/type/ll.hpp"
#include "utility/stream/vector.hpp"
#include "utility/range.hpp"
using namespace std;
ll method_1(vector<int> const & m) {
    ll result = 0;
    for (int i : range(1,m.size())) {
        if (m[i-1] > m[i]) {
            result += m[i-1] - m[i];
        }
    }
    return result;
}
ll method_2(vector<int> const & m) {
    ll result = (1ll<<60);
    for (int r : range(0,10000+1)) {
        ll eaten = 0;
        for (int i : range(0,m.size())) {
            if (result <= eaten) {
                eaten = -1;
                break;
            }
            if (m[i-1] - r > m[i]) {
                eaten = -1;
                break;
            }
            eaten += min(r, m[i-1]);
        }
        if (eaten != -1) {
            result = min(result, eaten);
        }
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    for (int testcase : range(cin)) {
        int n; cin >> n;
        vector<int> m(n); cin >> m;
        cout << "Case #" << testcase+1 << ": " << method_1(m) << " " << method_2(m) << endl;
    }
    return 0;
}
