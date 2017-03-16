#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define each(it,n) for(__typeof((n).begin()) it=(n).begin();it!=(n).end();++it)

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) {
        cin >> a[i];
    }

    int maxdif = 0;
    rep(i, N - 1) {
        maxdif = max(maxdif, a[i] - a[i + 1]);
    }

    int ans1 = 0, ans2 = 0;
    rep(i, N - 1) {
        ans1 += max(0, a[i] - a[i + 1]);
        ans2 += min(a[i], maxdif);
    }
    cout << ans1 << " " << ans2 << endl;
}

int main() {
    int T;
    cin >> T;
    rep(i, T) {
        cout << "Case #" << i + 1 << ": "; 
        solve();
    }
    return 0;
}
