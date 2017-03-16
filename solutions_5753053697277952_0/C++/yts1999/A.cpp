#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<pair<int,int> > q;

int main() {
    int T;
    scanf("%d",&T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d:",t);
        int n;
        scanf("%d",&n);
        int sum = 0,sz = n;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d",&x);
            sum += x;
            q.push(make_pair(x,i));
        }
        for (; ! q.empty();) {
            pair<int,int> x = q.top();
            q.pop();
            int nsum,nsz,mx;
            if (x.first >= 2) {
                nsum = sum - 2,nsz = sz;
                if (x.first == 2)
                    nsz--;
                mx = 0;
                if (q.empty())
                    mx = 0;
                else
                    mx = q.top().first;
                mx = max(mx,x.first - 2);
                if (mx == 0 || mx * 2 <= nsum) {
                    printf(" %c%c",x.second + 'A',x.second + 'A');
                    sum = nsum;
                    sz = nsz;
                    if (x.first != 2)
                        q.push(make_pair(x.first - 2,x.second));
                    continue;
                }
            }
            pair<int,int> y;
            if (! q.empty()) {
                y = q.top();
                q.pop();
            }
            else
                break;
            nsum = sum - 2,nsz = sz;
            if (x.first == 1)
                nsz--;
            if (y.first == 1)
                nsz--;
            if (q.empty())
                mx = 0;
            else
                mx = q.top().first;
            mx = max(mx,max(x.first - 1,y.first - 1));
            if (mx == 0 || mx * 2 <= nsum) {
                printf(" %c%c",x.second + 'A',y.second + 'A');
                sum = nsum;
                sz = nsz;
                if (x.first != 1)
                    q.push(make_pair(x.first - 1,x.second));
                if (y.first != 1)
                    q.push(make_pair(y.first - 1,y.second));
                continue;
            }
            q.push(y);
            nsum = sum - 1,nsz = sz;
            if (x.first == 1)
                nsz--;
            mx = 0;
            if (q.empty())
                mx = 0;
            else
                mx = q.top().first;
            mx = max(mx,x.first - 1);
            if (mx == 0 || mx * 2 <= nsum) {
                printf(" %c",x.second + 'A');
                sum = nsum;
                sz = nsz;
                if (x.first != 1)
                    q.push(make_pair(x.first - 1,x.second));
                continue;
            }
        }
        printf("\n");
    }
    return 0;
}
