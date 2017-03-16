#include <bits/stdc++.h>

using namespace std;

int solve() {

    unsigned long long b, n;
    cin >> b >> n;

    vector<int> cap(b);

    for (unsigned long long i = 0; i < b; ++i) {
        cin >> cap[i];
    }


    vector<int> ordre;

    for (unsigned long long i=0;i<b;++i) {
        ordre.push_back((int)i);
    }

    for (unsigned long long j = 1; j <= 1000; j++) {
        for (unsigned long long i = 0; i < b; ++i) {
            if (j % cap[i] == 0) ordre.push_back((int)i);
        }
    }

    n--;
    unsigned long long res = n % (unsigned  long long) ordre.size();

    return (ordre[res] + 1);
}

int main() {

    freopen("B-small-attempt6.in", "r", stdin);
    freopen("B-small-practice.out", "w", stdout);
    //freopen("test.in", "r", stdin);

    int t;
    cin >> t;



    int res;
    for (int i = 0; i < t; ++i) {
        res = solve();
        cout << "Case #" << (i+1) << ": " << res << endl;
    }
    return 0;
}