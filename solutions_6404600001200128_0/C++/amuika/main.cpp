#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<long long> vi;
typedef vector<vi> vvi;

int main(int argc, char** argv) {

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
    int n;
    cin >> n;
    
    vi v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    
    long long ans1 = 0, ans2 = 0;
    for (int i = 1; i < n; ++i) {
        ans1 += max(0LL, v[i-1]-v[i]);
        ans2 = max(ans2, v[i-1]-v[i]);
    }
    long long ans3 = 0;
    for (int i = 0; i < n-1; ++i) {
        ans3 += min(v[i], ans2);
    }
    cout << "Case #" << cases << ": " << ans1 << " " << ans3 << endl;
    }
    return 0;
}

