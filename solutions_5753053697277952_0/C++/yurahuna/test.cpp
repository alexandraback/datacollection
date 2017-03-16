#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rrep2(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef pair<int, int> P;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T;
    cin >> T;
    rep(t, T) {
        int N;
        cin >> N;
        vector<pair<int, char>> p;
        int sm = 0;
        rep(i, N) {
            int x;
            cin >> x;
            sm += x;
            p.emplace_back(make_pair(x, 'A' + i));
        }


        vector<string> ans;
        while (sm > 0) {
            sort(all(p));
            reverse(all(p));
            // for (auto x : p) {
            //     cout << x.first << " " << x.second << endl;
            // }
            // cout << endl;
            string s;
            s += p[0].second;
            p[0].first--;
            sm--;
            if (p[1].first * 2 > sm) {
                s += p[1].second;
                p[1].first--;
                sm--;
            }
            ans.emplace_back(s);
        }

        cout << "Case #" << t + 1 << ":";
        for (auto s : ans) {
            cout << " " << s;
        }
        cout << endl;
    }

}
