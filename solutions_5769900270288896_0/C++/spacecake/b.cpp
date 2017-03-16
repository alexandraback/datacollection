#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

void test() {
    std::random_device rd;
    std::mt19937 mt(time(0));
    std::uniform_int_distribution<int> dist(1, 10000);
    int t = 1000;
    for (int i = 1; i <= t; i++) {
        int l = dist(mt) % 8;
        cout << l << "\n";
    }
}

int ans[17][17][17];

int getUh(vector< vector<bool> >& a) {
    int ans = 0;
    vector< vector<int> > b(a.size(), vector<int>(a[0].size()));
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)a[0].size(); j++) {
            if (a[i][j]) {
                if (i + 1 < (int)a.size() && a[i + 1][j]) ans++;
                if (j + 1 < (int)a[0].size() && a[i][j + 1]) ans++;
            } 
        }
    }
    return ans;
}

void solve() {
    for (int i = 0; i <= 16; i++) {
        for (int j = 0; j <= 16; j++) {
            for (int k = 0;  k <= 16; k++) {
                    ans[i][j][k] = 1000;
            }
        }
    }
    for (int r = 1; r <= 16; r++) {
        for (int c = 1; c <= 16 && r * c <= 16 && c <= r; c++) {
            int n = r * c;
            vector< vector<bool> > a(r, vector<bool>(c));
            for (int i = 0; i < (1 << n); i++) {
                int t = 0;
                for (int j = 0; j < n; j++) {
                    t += (a[j / c][j % c] = (((i >> j) & 1) == 1));  
                }
                ans[t][r][c] = min(ans[t][r][c], getUh(a));
                ans[t][c][r] = ans[t][r][c];
            }
        }
    }
}

int main() {
    ifstream cin("test.in");
    ofstream cout("test.out"); 
    int testCount;
    cin >> testCount;
    solve();
    for (int testCase = 1; testCase <= testCount; testCase++) {
        int R, C, N;
        cin >> R >> C >> N;
        cout << "Case #" << testCase << ": " << ans[N][R][C] << "\n";
    }
    return 0;
}
