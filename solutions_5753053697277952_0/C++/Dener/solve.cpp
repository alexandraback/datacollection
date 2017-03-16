#include <bits/stdc++.h>

using namespace std;

void solve(int testnum)
{
    int k;
    cin >> k;
    int total = 0;

    vector<pair<int, int>> S;
    cout << "Case #" << testnum + 1 << ": ";

    for (int i = 0; i < k; i++) {
        int count;
        cin >> count;
        S.push_back(make_pair(count, i));
        total += count;
    }

    sort(S.rbegin(), S.rend());
    int to_del = total - 2 * S[0].first;

    for (int i = 1; i < S.size(); i++) {
        while (to_del and S[i].first) {
            cout << char('A' + S[i].second) << ' ';
            S[i].first--;
            to_del--;
        }
    }
    assert(to_del == 0);

    for (int i = 1; i < S.size(); i++) {
        while (S[i].first) {
            cout << char('A' + S[i].second) << char('A' + S[0].second) << ' ';
            S[i].first--;
        }
    }

    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        solve(i);
    }
}
