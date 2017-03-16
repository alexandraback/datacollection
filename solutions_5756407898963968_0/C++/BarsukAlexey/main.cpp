#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <clocale>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
using namespace std;

int test;

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    ios_base::sync_with_stdio(false);

    cin >> test;
    for (int i = 0; i < test; i++) {
        int rows[2] = {0, 0};
        int used[20]; memset(used, 0, sizeof(used));
        for (int j = 0; j < 2; j++) {
            cin >> rows[j];
            for (int a = 1; a <= 4; a++) {
                for (int b = 1; b <= 4; b++) {
                    int num; cin >> num;
                    if (a == rows[j]) used[num]++;
                }
            }
        }
        int possibility[20]; memset(possibility, 0, sizeof(possibility));
        for (int j = 1; j <= 16; j++) {
            if (used[j] > 1) {
                possibility[++possibility[0]] = j;
            }
        }
        if (possibility[0] < 1) {
            cout << "Case #" << i + 1 << ": Volunteer cheated!" << endl;
            cout.flush();
        }
        else if (possibility[0] == 1) {
            cout << "Case #" << i + 1 << ": " << possibility[1] << endl;
            cout.flush();
        }
        else {
            cout << "Case #" << i + 1 << ": Bad magician!" << endl;
            cout.flush();
        }
    }

    return 0;
}
