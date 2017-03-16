#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
using namespace std;


size_t rev(size_t val) {
    size_t ans = 0;
    while (val) {
        ans = 10 * ans + val % 10;
        val /= 10;
    }
    return ans;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    out.sync_with_stdio(false);
    int t;
    in >> t;
    for (int qqqqqq = 0; qqqqqq < t; qqqqqq++) {
        int r, c, n;
        in >> r >> c >> n;
        int ans = 4 * c * r;
        for (int i = 0; i < (1 << (r * c)); i++) {
            vector<vector<int>> v(r + 2, vector<int>(c + 2));
            for (int j = 1; j <= r; j++)
                for (int k = 1; k <= c; k++)
                    v[j][k] = i & (1 << (c * (j - 1) + k - 1)) ? 1 : 0;
            int sm = 0, ss = 0;
            for (int j = 1; j <= r; j++)
                for (int k = 1; k <= c; k++)
                    sm += v[j][k] * (v[j - 1][k] + v[j + 1][k] + v[j][k - 1] + v[j][k + 1]), ss += v[j][k];
            if (ss == n)
                ans = min(ans, sm / 2);
        }
        out << "Case #" << qqqqqq + 1 << ": " << ans << '\n';
    }
    return 0;
}