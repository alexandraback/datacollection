#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int main() {
    freopen("/Users/linsina/Downloads/A-small.in", "r", stdin);
    freopen("/Users/linsina/Downloads/A.out", "w", stdout);
    
    int n;
    cin >> n;
    for (int k = 0; k < n; k++) {
        int r1 = 0, r2 = 0;
        int m;
        int ma = 0;
        cin  >> m;
        vector<int> mu(m);
        for (int i = 0; i < m ; i++) {
            cin >> mu[i];
        }
        for (int i = 1; i < m; i++) {
            r1 += max(0, mu[i - 1] - mu[i]);
            ma = max(ma, mu[i - 1] - mu[i]);
        }
        for (int i = 0; i < m - 1; i++) {
            r2 += min(ma, mu[i]);
        }
        
        cout << "Case #" << k + 1 << ": " << r1 << " " << r2 << endl;
    }
    
    return 0;
}


