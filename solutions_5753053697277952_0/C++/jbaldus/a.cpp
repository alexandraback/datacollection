#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve(int)
{
    map<char, int> cnt;
    int n, sum = 0;
    cin >> n;
    for (char i = 'A'; i < 'A' + n; ++i) {
        cin >> cnt[i];
        sum += cnt[i];
    }

    int first = true;
    while (sum) {
        char max = 'A';
        for (char i = 'A'; i < 'A' + n; ++i) if (cnt[i] > cnt[max]) max = i;
        if (first || sum == 2) {
            cout << " ";
            first = false;
        } else first = true;
        cout << max;
        --cnt[max];
        --sum;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ":";
        solve(i);
    }
}
