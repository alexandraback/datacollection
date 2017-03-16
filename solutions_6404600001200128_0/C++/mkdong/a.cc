#include <iostream>

using namespace std;

int m[20000];

int main()
{
    int T;
    cin >> T;
    for (int t=0; t<T; ++t) {
        int n;
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> m[i];
        }
        int ans1 = 0;
        int rate = 0;
        for (int i=1; i<n; ++i) {
            if (m[i] - m[i-1] < 0) {
                ans1 += m[i-1] - m[i];
                if (m[i-1] - m[i] > rate) {
                    rate = m[i-1] - m[i];
                }
            }
        }
        int ans2 = 0;
        for (int i=0; i<n-1; ++i) {
            if (m[i] >= rate) ans2 += rate;
            if (m[i] < rate) ans2 += m[i];
        }
        cout << "Case #" << 1+t << ": " << ans1 << ' ' << ans2<<endl;
    }
    return 0;
}
