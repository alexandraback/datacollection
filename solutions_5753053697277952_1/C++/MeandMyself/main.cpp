#include <iostream>

#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <cmath>
#include <algorithm>

#include <fstream>

using namespace std;



int main()
{
    ifstream cin ("/Users/Roman/ClionProjects/Calculations/input.txt");
    ofstream cout ("/Users/Roman/ClionProjects/Calculations/output.txt");

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout.setf(ios_base::fixed);
    cout.precision(28);

    int tt;
    cin >> tt;
    //cout << tt;
    for (int t = 0; t < tt; ++t) {
        int n;
        cin >> n;
        vector < int > x(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
            sum += x[i];
        }
        cout << "Case #" << t + 1 << ": ";
        while (sum != 0) {
            int mx = -1;
            int idx = -1;
            for (int i = 0; i < n; ++i) {
                if (mx < x[i]) {
                    mx = x[i];
                    idx = i;
                }
            }
            mx = -1;
            int idxs = -1;
            for (int i = 0; i < n; ++i) {
                if (mx < x[i] && i != idx) {
                    mx = x[i];
                    idxs = i;
                }
            }
            mx = -1;
            int idxt = -1;
            for (int i = 0; i < n; ++i) {
                if (mx < x[i] && i != idx && i != idxs) {
                    mx = x[i];
                    idxt = i;
                }
            }
            if (x[idx] == x[idxs]) {
                if (idxt == -1 || x[idx] != x[idxt]) {
                    sum -= 2;
                    x[idx]--;
                    x[idxs]--;
                    cout << char('A' + idx) << char('A' + idxs) << " ";
                } else {
                    cout << char('A' + idx) << " ";
                    x[idx]--;
                    sum--;
                }
            } else {
                if ((x[idx] - 1) == x[idxs]) {
                    cout << char('A' + idx) << " ";
                    x[idx]--;
                    sum--;
                } else {
                    cout << char('A' + idx) << char('A' + idx) << " ";
                    x[idx] -= 2;
                    sum -= 2;
                }
            }
        }
        //printf("%d\n", t);
        cout << endl;
    }
    return 0;
}