#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int>> pq;
int tot;

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t; cin>>t;
    for (int i=1; i<=t; ++i) {
        int n; cin>>n;
        for (int i=1; i<=n; ++i) {
            int a; cin>>a;
            tot += a;
            pq.push(make_pair(a, i));
        }
        printf("Case #%d: ", i);
        while(!pq.empty()) {
            auto a = pq.top();
            pq.pop();
            printf("%c", a.second+'A'-1);
            bool left = !pq.empty();
            int val = a.first;
            tot--;
            if (left) {
                val = pq.top().first;
            }
            if (a.first > 1) {
                pq.push(make_pair(a.first-1, a.second));
            }
            if (pq.size() >= 2 && tot % 2 == 1) {
                auto p = pq.top();
                pq.pop();
                auto p1 = pq.top();
                pq.pop();
                if ((p.first)-1 <= p1.first/2) {
                    printf("%c", p1.second+'A'-1);
                    pq.push(p);
                    if (p1.first > 1) {
                        pq.push(make_pair(p1.first-1, p1.second));
                    }
                } else {
                    pq.push(p1);
                    printf("%c", p.second+'A'-1);
                    if (p.first > 1) {
                        pq.push(make_pair(p.first-1, p.second));
                    }
                }
                tot--;
            } else if (pq.size() == 1 && tot % 2 == 1) {
                auto p = pq.top();
                pq.pop();
                printf("%c", p.second+'A'-1);
                if (p.first > 1) {
                    pq.push(make_pair(p.first-1, p.second));
                }
                tot--;
            }
            printf(" ");
        }
        printf("\n");
    }
}
