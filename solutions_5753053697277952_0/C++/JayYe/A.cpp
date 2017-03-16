#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000+5;

int n, a[233];
priority_queue<pair<int,int> > qu;

void solve() {
    while(!qu.empty()) {
        qu.pop();
    }
    for(int i = 0;i < n; i++)
        qu.push({a[i], i});
    while(!qu.empty()) {
        if(qu.size() == 2) {
            int x = qu.top().second; qu.pop();
            int y = qu.top().second; qu.pop();
            for(int i = 0;i < a[x]; i++) {
                printf(" %c%c", x+'A',y+'A');
            }
            puts("");
            break;
        } else {
            int x = qu.top().second; qu.pop();
            a[x]--;
            printf(" %c", x+'A');
            if(a[x] > 0) qu.push({a[x],x});
        }
    }
}

int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int t, cas = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0;i < n; i++) scanf("%d", &a[i]);
        printf("Case #%d:", ++cas);
        solve();
    }
    return 0;
} 
