#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int cases; cin >> cases;
    for (int cas = 0; cas < cases; ++cas) {
        int n;
        cin >> n;
        --n;
        int grid[4][4];
        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                cin >> grid[row][col];
            }
        }
        int k;
        cin >> k;
        --k;
        int grid2[4][4];
        for (int row = 0; row < 4; ++row) {
            for (int col = 0; col < 4; ++col) {
                cin >> grid2[row][col];
            }
        }
        set<int> stuff(grid[n], grid[n] + 4);
        set<int> stuff2(grid2[k], grid2[k] + 4);
        std::vector<int> v(4);
        auto it = set_intersection(stuff.begin(), stuff.end(), stuff2.begin(), stuff2.end(), v.begin());
        if (it - v.begin() == 0) {
            cout << "Case #" << cas + 1 << ": Volunteer cheated!";
        } else if (it - v.begin() > 1) {
            cout << "Case #" << cas + 1 << ": Bad magician!";
        } else {
            cout << "Case #" << cas + 1 << ": " << v.front();
        }
        cout << "\n";
    }
}
