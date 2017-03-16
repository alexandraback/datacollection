#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, N, m[1010];
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> m[i];
        
        long long method1 = 0;
        for (int i = 1; i < N; i++) {
            method1 += max(m[i-1]-m[i], 0);
        }
        
        long long method2 = 0;
        int maxdiff = 0;
        for (int i = 1; i < N; i++) {
            maxdiff = max(maxdiff, max(m[i-1]-m[i], 0));
        }
        for (int i = 1; i < N; i++) {
            
            method2 += min(m[i-1], maxdiff);//max(m[i-1], m[i-1]-m[i]);
        }
        
        cout << "Case #" << tc << ": " << method1 << " " << method2 << endl;
    }

    return 0;
}

