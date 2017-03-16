#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long int64;

const int oo = 0x3f3f3f3f;

inline int GetBit(const int mask, const int bit) {
    return (mask >> bit) & 1;
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int testCount;
    cin >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        int rows, columns, n;
        cin >> rows >> columns >> n;
        int minCost = oo;
        for (int mask = 0; mask < (1 << (rows * columns)); ++mask) {
            int count = 0, cost = 0;
            for (int x = 0; x < rows; ++x) {
                for (int y = 0; y < columns; ++y) {
                    if (GetBit(mask, x * columns + y)) {
                        ++count;
                        if (x > 0 && GetBit(mask, (x - 1) * columns + y))
                            ++cost;
                        if (y > 0 && GetBit(mask, x * columns + y - 1))
                            ++cost;
                    }
                }
            }
            if (count == n)
                minCost = min(minCost, cost);
        }
        cout << "Case #" << t << ": " << minCost << "\n";
    }
    cin.close();
    cout.close();
    return 0;
}
