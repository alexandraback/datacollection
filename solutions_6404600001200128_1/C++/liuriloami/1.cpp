#include <bits/stdc++.h>
using namespace std;

int main (int argc, char** argv) {
    int nTests;
    cin >> nTests;
    for (int test = 1; test <= nTests; test++) {
        int res1 = 0, res2 = 0, maxRate = 0;
        int n;
        vector<int> vet;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            vet.push_back(tmp);
            if (i != 0)
                maxRate = max(maxRate, vet[i-1]-tmp);
        }
        for (int i = 0; i < n; i++) {
            int diff;
            if (i > 0) {
                diff = vet[i] - vet[i-1];
                if (diff < 0) res1 -= diff;
            }
            if (i != n-1)
                res2 += min(vet[i], maxRate);
        }
        cout << "Case #"  << test << ": " << res1 << " " << res2 << endl;
    }
    return 0;
}