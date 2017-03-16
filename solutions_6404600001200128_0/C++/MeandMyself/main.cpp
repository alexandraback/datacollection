#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    fstream in;
    in.open ("//Users//Roman//Desktop//Contest//B.txt", std::fstream::in);
    fstream out;
    out.open ("//Users//Roman//Desktop//Contest//A.txt.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    int sum = 0;
    //cout << t;
    for (int tt = 0; tt < t; ++tt){
        int n;
        cin >> n;
        vector < int > x(n, 0);
        int mx = 0;
        int ans = 0;
        cin >> x[0];
        for (int i = 1; i < n; ++i) {
            cin >> x[i];
            if (x[i - 1] - x[i] > 0) {
                if (mx < x[i - 1] - x[i]) {
                    mx = x[i - 1] - x[i];
                }
                ans += x[i - 1] - x[i];
            }
        }
        int ans2 = 0;
        for (int i = 0; i < n - 1; ++i){
            //if (x[i] - x[i + 1] > 0) {}
            ans2 += std::min(mx, x[i]);
        }
        out << "Case #" << tt + 1 << ": "<< ans << " " << ans2 << endl;
    }
    return 0;
}