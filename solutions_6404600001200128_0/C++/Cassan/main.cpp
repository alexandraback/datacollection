#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<int> champ(n);

    for (int i = 0; i < n; ++i) {
        cin >> champ[i];
    }

    int res, total = 0, max = 0;

    for (int i = 0; i < (n-1); ++i) {
        res = champ[i] - champ[i+1];
        if (res > 0) {
            total += res;
            if (res > max) max = res;
        }


    }

    cout << total << " ";
    total = 0;

    for (int i = 0; i < (n-1); ++i) {
        if (champ[i] <= max) total += champ[i];
        else total += max;
    }

    cout << total;

}

int main() {

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-practice.out", "w", stdout);
    //freopen("test.in", "r", stdin);

    int t;
    cin >> t;



    int res;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << (i+1) << ": ";
        solve();
        cout << endl;
    }
    return 0;
}