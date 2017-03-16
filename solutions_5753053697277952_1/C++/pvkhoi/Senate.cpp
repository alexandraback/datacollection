#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int n, P[30];

void solve() {
    while (true) {
        int cnt = 0, idx, mx = -1;
        for (int i = 1; i <= n; ++i) {
            if (P[i] && mx < P[i]) {
                idx = i;
                mx = P[i];
            }
            cnt += (P[i]>0);
        }
        if (cnt==0) break;
        if (cnt==2) {
            for (int i = 1; i <= n; ++i)
            if (P[i]>0) {
                printf("%c",'A'+i-1);
                P[i]--;
            }
            printf(" ");
        }
        else {
            P[idx]--;
            printf("%c ",'A'+idx-1);
        }
    }
    printf("\n");
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
        scanf("%d",&n);
        for (int i = 1; i <= n; ++i)
            scanf("%d",&P[i]);
        printf("Case #%d: ", t);
        solve();
	}
	return 0;
}
