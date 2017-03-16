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

    fstream in;
    in.open ("//Users//Roman//Desktop//Contest//B_large.in.txt", std::fstream::in);
    fstream out;
    out.open ("//Users//Roman//Desktop//Contest//B_large.txt", std::fstream::in | std::fstream::out | std::fstream::app);

    in >> t;
    //cout << t;
    for (int tt = 0; tt < t; ++tt){
        long long n, m;
        in >> m >> n;
        vector < long long > x(m, 0);

        for (int i = 0; i < m; ++i) {
            in >> x[i];
        }

        long long beg = -1;
        long long end = 1000000000000000;
        while (end - beg > 1) {
            long long mid = (end + beg)/2;
            long long sum = 0;
            for (int i = 0; i < m; ++i) {
                sum += (mid + x[i] - 1) / x[i];
            }
            if (sum >= n) {
                end = mid;
            }
            else {
                beg = mid;
            }
            // cout << mid << " ";
            // cout << "pr\n";
        }
        // cout << endl;
        long long ans = -1, b = 100000;
        long long t = end - 1;
        for (int i = 0; i < m; ++i){
            n = n - ((t + x[i] - 1) / x[i]);
        }
        // cout << n << endl;
        for (int i = 0; i < m; ++i){
            if ((end + x[i] - 1) % x[i] == 0) {
                if (n == 1) {
                    ans = i + 1;
                    break;
                }
                else{
                    n--;
                }
            }

        }
        out << "Case #" << tt + 1 << ": "<< ans << endl;
        // cout << end << endl;
    }
    return 0;
}