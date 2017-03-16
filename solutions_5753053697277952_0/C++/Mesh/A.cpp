#include <iostream>
#include <cassert>

using namespace std;

int main() {
    
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":";
        
        int n;
        cin >> n;
        
        int P[26], count = 0;
        fill(P, P+26, 0);
        for (int i = 0; i < n; i++) {
            cin >> P[i];
            count += P[i];
        }
        
        while (count > 0) {
            string ans = "";
            int m = 0;
            for (int i = 1; i < n; i++) {
                if (P[m] < P[i]) m = i;
            }
            ans += ('A'+m);
            P[m]--;
            count--;
            
            if (count != 2) {
                m = 0;
                for (int i = 1; i < n; i++) {
                    if (P[m] < P[i]) m = i;
                }
                ans += ('A'+m);
                P[m]--;
                count--;
            }
            
            for (int i = 1; i < n; i++) {
                assert(P[i]*2 <= count);
            }
            
            cout << " " << ans;
        }
        cout << endl;
    }
    
}