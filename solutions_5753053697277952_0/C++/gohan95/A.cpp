//Done by: K Ashwin

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TR(c, it) \
for (auto it = (c).begin(); it != (c).end(); it++)

#define s(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define set0(a) memset(a, 0, sizeof(a))
#define setdp(a) memset(a, -1, sizeof(a))
#define INF 2000000000
#define MOD 1000000007

vector <pii> ans;
priority_queue <pii> pq;
pii cur, cur2;

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("op.txt", "w", stdout);

    int t, tt, n, x, sum;

    cin >> t;

    tt = 0;
    while (t--) {
        tt++;
        cin >> n;

        while (!pq.empty())
            pq.pop();

        ans.clear();

        sum = 0;
        REP (i, 1, n) {
            cin >> x;
            sum += x;

            pq.push(mp(x, i - 1));
        }

        while (!pq.empty()) {
            cur = pq.top();
            pq.pop();

            if (sum % 2) {
                ans.pb(mp(cur.se, -1));

                if (cur.fi - 1 != 0)
                    pq.push(mp(cur.fi - 1, cur.se));

                sum -= 1;

                continue ;
            }

            cur2 = pq.top();
            pq.pop();

            ans.pb(mp(cur.se, cur2.se));
            sum -= 2;

            if (cur.fi - 1 != 0)
                pq.push(mp(cur.fi - 1, cur.se));

            if (cur2.fi - 1 != 0)
                pq.push(mp(cur2.fi - 1, cur2.se));
        }

        cout << "Case #" << tt << ": ";
        TR (ans, it) {
            if (it->fi != -1)
                cout << (char)(it->fi + 'A');

            if (it->se != -1)
                cout << (char)(it->se + 'A');

            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
