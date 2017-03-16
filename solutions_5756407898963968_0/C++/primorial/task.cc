#include <iostream>
#include <sstream> 
#include <cstdio>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdlib> 
#include <ctime>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
template<typename T> T ABS(const T& val) { return val < 0 ? -val : val; }


int main ()
{
    std::ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int test = 1; test <= T; ++test) {
        int row[2][4];
        int ans[2];

        for (int ind = 0; ind < 2; ++ind) {
            string s;
            cin >> ans[ind];
            getline(cin, s);
            --ans[ind];

            for (int i = 0; i < 4; ++i) {
                if (i == ans[ind]) {
                    for (int j = 0; j < 4; ++j) {
                        cin >> row[ind][j];
                    }
                    getline(cin, s);
                } else {
                    getline(cin, s);
                }
            }

            sort(row[ind], row[ind] + 4);
        }

        int res[4];
        int *it = set_intersection(row[0], row[0] + 4, row[1], row[1] + 4, res);

        cout << "Case #" << test << ": ";
        
        if (it - res == 0) {
            cout << "Volunteer cheated!\n";
        } else if (it - res > 1) {
            cout << "Bad magician!\n";
        } else {
            cout << *res << "\n";
        }
    }

    return 0;
}
