#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define N 2000100
typedef long long ll;
typedef long double ld;
using namespace std;
int nt;
int p[55];
vector <pp> c;
int f[1234];
int mark[1234];
int cnt[55];
int n;

bool isValid() {
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += cnt[i];
    for (int i = 1; i <= n; i++)
        if (cnt[i] > sum / 2) return false;
    return true;
}

bool isExit() {
    for (int i = 1; i <= n; i++)
        if (cnt[i] > 0) return false;
    return true;
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.ou", "w", stdout);
    cin >> nt;
    for (int kk = 1; kk <= nt; kk++) {
        memset(mark, false, sizeof(mark));
        memset(cnt, 0, sizeof(cnt));

        c.clear();
        cin >> n;
        int m = 0;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            for (int j = 1; j <= p[i]; j++) {
                m++;
                f[m] = i;
            }
            cnt[i] += p[i];
        }

        while (true) {
            if (isExit()) break;
            bool ok = false;
            for (int i = 1; i < m; i++)
            for (int j = i + 1; j <= m; j++)
            if (!mark[i] && !mark[j] && ok == false) {
                cnt[f[i]]--;
                cnt[f[j]]--;
                if (isValid()) {
                    ok = true;
                    c.pb(mp(f[i], f[j]));
                    mark[i] = true;
                    mark[j] = true;
                }
                else {
                    cnt[f[i]]++;
                    cnt[f[j]]++;
                }
            }
            if (ok) continue;

            for (int i = 1; i <= m; i++)
            if (mark[i] == false) {
                cnt[f[i]]--;
                if (isValid()) {
                    c.pb(mp(f[i], -1));
                    mark[i] = true;
                }
                else {
                    cnt[f[i]]++;
                }
            }
        }

        cout << "Case #" << kk << ": ";
        for (int i = 0; i < c.size(); i++) {
            if (c[i].se == -1) {
                cout << char(c[i].fi - 1 + 'A') << " ";
            }
            else
                cout << char(c[i].fi - 1 + 'A') << char(c[i].se - 1 + 'A') << " ";
        }
        cout << "\n";
    }

    /**/return 0;
}

