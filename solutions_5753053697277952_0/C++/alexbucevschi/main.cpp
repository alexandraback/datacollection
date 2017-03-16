#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pii pair<int,int>
#define tii tuple <int,int,int>
#define N 200005
#define mod 1000000005
#define X first
#define Y second
#define eps 0.0000000001
#define all(x) x.begin(),x.end()
#define tot(x) x+1,x+n+1
using namespace std;

int T, t, n, i, x, y, py, p, ok, sum;
priority_queue<pii, vector<pii>>q, qq;

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &T);

    for(t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%d", &n);
        ok = 1;

        while(q.size())
            q.pop();

        for(i = 0; i < n; i++) {
            scanf("%d", &x);
            q.push(mp(x, i));
        }

        while(q.size()) {
            if(q.size() == 3 && q.top().X == 1) {
                x = q.top().X;
                p = q.top().Y;
                q.pop();
                printf("%c ", 'A' + p);
                continue;
            }

            x = q.top().X;
            p = q.top().Y;
            q.pop();

            if(x == 1) {
                if(q.size()) {
                    y = q.top().X;
                    py = q.top().Y;
                    q.pop();
                }
                else {
                    y = mod;
                    ok = 0;
                }

                if(ok)
                    printf("%c%c ", 'A' + p, 'A' + py);
                else
                    printf("%c ", 'A' + p);

                if(y != 1 && y != mod)
                    q.push(mp(y - 1, py));
            }
            else {
                if(q.size()) {
                    y = q.top().X;
                    py = q.top().Y;
                    q.pop();
                }
                else {
                    y = mod;
                    ok = 0;
                }

                if(x == y) {
                    printf("%c%c ", 'A' + p, 'A' + py);

                    if(y != 1)
                        q.push(mp(y - 1, py));

                    if(x != 1)
                        q.push(mp(x - 1, p));

                    continue;
                }

                if(y != mod)
                    q.push(mp(y, py));

                if(x > 2)
                    q.push(mp(x - 2, p));

                printf("%c%c ", 'A' + p, 'A' + p);
            }
        }



        printf("\n");
    }

    return 0;
}

