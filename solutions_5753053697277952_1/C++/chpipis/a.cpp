#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define iter(v, i) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const double eps = 1e-9;
const double pi = 3.141592653589793238462;

int p[30], cur[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("A-large.in", "rt", stdin);
    freopen("A-large.out", "wt", stdout);

    int t, tc = 1;

    scanf("%d", &t);

    while (t--) {
        int n, sum = 0;
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
            scanf("%d", &p[i]);

        printf("Case #%d:", tc++);

        stack<string> ans;
        priority_queue<ii, vii, greater<ii> > pq;

        memset(cur, 0, sizeof cur);

        for (int i = 0; i < n; i++)
            pq.push(ii(0, i));

        while (!pq.empty()) {
            int now = pq.top().se;
            pq.pop();

            if (cur[now] == p[now])
                continue;

            if (cur[now] + 1 > (sum + 1) / 2) {
                while (cur[pq.top().se] == p[pq.top().se])
                    pq.pop();
                int now2 = pq.top().se;
                pq.pop();

                cur[now]++;
                cur[now2]++;
                sum += 2;

                pq.push(ii(cur[now], now));
                pq.push(ii(cur[now2], now2));

                char next[3] = {now + 'A', now2 + 'A', '\0'};
                ans.push((string)next);
            } else {
                cur[now]++;
                sum++;

                pq.push(ii(cur[now], now));

                char next[2] = {now + 'A', '\0'};
                ans.push((string)next);
            }
        }

        while (!ans.empty()) {
            printf(" %s", ans.top().c_str());
            ans.pop();
        }
        putchar('\n');
    }

    return 0;
}
