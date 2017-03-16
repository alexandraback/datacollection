#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main(int,char**) {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        cout << "Case #" << t << ":";
        int P[N];
        int m = 0;
        int n = 10000;
        for (int i = 0; i < N; ++i) {
            cin >> P[i];
            m = max(m,P[i]);
            n = min(n,P[i]);
        }
        
        stringstream ss;
        for (int i = m; i > 1 && (i > n || N > 2); --i) {
            for (int j = 0; j < N; ++j) {
                if (P[j] == i) ss << ' ' << (char)('A' + j);
            }
            cout << ss.str();
        }

        for (int i = 0; i < N-2; ++i) {
            cout << ' ' << (char)('A' + i);
        }
        

        if (N == 2)
            for (int i = 1; i < n; ++i) cout << " AB"; 
        cout << ' ' << (char)('A' + N-2) << (char)('A' + N-1) << endl;
    }

}
