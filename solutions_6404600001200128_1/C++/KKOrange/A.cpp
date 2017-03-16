#include <iostream>

using namespace std;

int a[100005];
int T, N;


int main() {
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N;
        for(int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        int ans1 = 0;
        int maxrate = 0;
        for(int i = 1; i <= N-1; i++) {
            int diff = a[i+1]-a[i];
            if(diff < 0) {
                ans1 -= diff;
                maxrate = max(maxrate, -diff);
            }
        }
        int ans2 = 0;
        for(int i = 1; i <= N-1; i++) {
            int diff = a[i+1]-a[i];
            if(diff < 0) {
                diff *= -1;
                ans2 += min(a[i], maxrate);
            } else {
                ans2 += min(a[i], maxrate);
            }
        }
        
        cout << "Case #" << t << ": " << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
