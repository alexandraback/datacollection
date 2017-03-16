#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (int)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

int p[30];
set<pair<int, int>> s;

int main() {
inp("input.txt");
out("output.txt");
    int t;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt++) {
        int n, i;
        scanf("%d", &n);
        for(i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            s.insert({-p[i], i});
        }
        printf("Case #%d: ", tt);
        while(s.size() > 2) {
            auto x = *s.begin();
            s.erase(s.begin());
            x.fi++;
            printf("%c ", char(x.se + 'A' - 1));
            if(x.fi != 0)
                s.insert(x);
        }
        auto x = *s.begin();
        s.erase(s.begin());
        auto y = *s.begin();
        s.erase(s.begin());
        while(x.fi) {
            x.fi++;
            printf("%c%c ", char(x.se + 'A' - 1), char(y.se + 'A' - 1));
        }
        printf("\n");
    }
    return 0;
}
