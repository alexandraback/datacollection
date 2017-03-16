#include <bits/stdc++.h>

using namespace std;

inline char getMax(vector<int>& a) {
    int ind = 0;
    for (int i = 1; i < a.size(); i++)
        if (a[i] > a[ind])
            ind = i;
    a[ind]--;
    return char('A' + ind);
}

void solve(int testNum) {
    printf("Case #%d: ", testNum + 1);

    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int& i : a)
        cin >> i;
    int s = accumulate(a.begin(), a.end(), 0);

    if (s % 2)
        cout << getMax(a) << ' ', s--;

    while (s > 0) {
        cout << getMax(a) << getMax(a) << ' ';
        s -= 2;
    }

    printf("\n");
}

int main() {
    //ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        solve(i);

    return 0;
}
