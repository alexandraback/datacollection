#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <ctime>
#include <fstream>
#include <cmath>

using namespace std;

#define y1 ym37s62rw
#define x1 xm2ash4ad
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int INF = 1000000007;
const long long INFll = 1000000007000000007ll;
const int MOD = 1000000007;

int n, k;
int m[30];

int main() {

    ios_base::sync_with_stdio(0);

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> n;
        int s = 0;
        int p = 0;
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
            s += m[i];
            if (m[i] > 0)
                p++;
        }
        cout << "Case #" << i + 1 << ":";
        while (s > 0) {
            if (s > 2) {
                int mx = 0;
                for (int i = 1; i < n; ++i) {
                    if (m[i] > m[mx])
                        mx = i;
                }
                if (s > 3) {
                    int k = 0;
                    cout << " ";
                    mx = m[mx];
                    for (int i = 0; i < n; ++i)
                    if (m[i] == mx && k < 2) {
                        k++;
                        s--;
                        m[i]--;
                        cout << (char)('A' + i);
                    }
                }
                else {
                    s--;
                    m[mx]--;
                    cout << " " << (char)('A' + mx);
                }
            }
            else {
                if (s == 0)
                    break;
                cout << " ";
                for (int i = 0; i < n; ++i) {
                    if (m[i] > 0) {
                        cout << (char)('A' + i);
                        m[i]--;
                    }
                }
                s = 0;
            }
            int mx = 0;
            for (int i = 0; i < n; ++i) {
                if (m[i] > mx)
                    mx = m[i];
            }
            if (mx * 2 > s) {
                cerr << "WA" << i << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
