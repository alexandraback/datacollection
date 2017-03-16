#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

vector<int> ds[N];

int main() {
    int ct;
    cin >> ct;
    for (int nt = 1; nt <= ct; nt++) {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            sum += a;
            ds[a].push_back(i);
        }
        cout << "Case #" << nt << ": ";
        int i = 1000;
        n = sum;
        while (n) {
            while (ds[i].empty()) i--;
            cout << (char)(ds[i].back()+'A');
            if (i > 1) ds[i-1].push_back(ds[i].back());
            ds[i].pop_back();
            n--;
            if (ds[i].size() == 1) {
                cout << (char)(ds[i].back()+'A') << ' ';
                if (i > 1) ds[i-1].push_back(ds[i].back());
                ds[i].pop_back();
                n--;
            }
            else cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
