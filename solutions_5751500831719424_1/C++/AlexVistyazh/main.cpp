#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const int INF = int(1e9 + 5);

int nextInt() {
    int x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c<=32);
    if (c=='-') {
        p = -1;
        c = getchar();
    }
    while (c>='0' && c<='9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

string s[111], z[111];
vector<int> v[111];

vector<int> pr(string a, string & b) {
    vector<int> v;
    char prv = a[0];
    int kol = 0;
    for (size_t i = 0; i < a.size();i++) {
        if (a[i]!=prv) {
            v.push_back(kol);
            prv = a[i];
            kol = 0;
        }
        if (a[i]==prv) kol++;
    }
    v.push_back(kol);
    b = a;
    b.erase(unique(b.begin(),b.end()),b.end());
    return v;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        v[i] = pr(s[i], z[i]);
    }
    for (int i = 2; i <= n; i++)
        if (z[i]!=z[1]) {
            cout << "Fegla Won\n";
            return;
        }
    int ans = 0;
    for (size_t i=0;i<v[1].size();i++) {
        int mi = int(1e9);
        for (int k = 0; k <= 100; k++) {
            int now = 0;
            for (int j = 1; j <= n; j++)
                now += abs(k-v[j][i]);
            mi = min(mi, now);
        }
        ans += mi;
    }
    cout << ans << '\n';
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    int c = 0;
    while (t--) {
        ++c;
        cout << "Case #" << c << ": ";
        solve();
    }
    return 0;
}
