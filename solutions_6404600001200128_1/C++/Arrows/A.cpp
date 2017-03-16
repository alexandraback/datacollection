#include <bits/stdc++.h>

using namespace std;

int a[1005];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int t;
    cin >> t;
    
    for(int cas = 1 ; cas <= t ; cas ++){
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; i++) {
            cin >> a[i];
        }
        int y = 0;
        for(int i = 0 ; i < n-1 ; i++) {
            if(a[i] - a[i+1] > 0) {
                y += a[i] - a[i+1];
            }
        }
        int z = 0;
        int m = -1;
        for(int i = 0 ; i < n-1 ; i++) {
            m = max(m, a[i] - a[i+1]);
        }
        for(int i = 0 ; i < n-1 ; i++) {
            z += a[i] > m ? m : a[i];
        }
        cout << "Case #" << cas << ": " << y << " " << z << endl;
    } 
    return 0;
}
