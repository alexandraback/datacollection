#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
int main() {
    int t;
    scanf("%d", &t);
    rep(k, t) {
        int m, tmp, ans, cnt = 0;
        set<int> s;
        scanf("%d", &m);
        rep(i, 4) {
            rep(j, 4) {
                scanf("%d", &tmp);
                if (i==m-1) {
                    s.insert(tmp);
                }
            }
        }
        scanf("%d", &m);
        rep(i, 4) {
            rep(j, 4) {
                scanf("%d", &tmp);
                if (i==m-1) {
                    if (s.find(tmp)!=s.end()) {
                        ans = tmp;
                        cnt++;
                    }
                }
            }
        }
        printf("Case #%d: ", k+1);
        if (!cnt) printf("Volunteer cheated!\n");
        else if (cnt>1) printf("Bad magician!\n");
        else printf("%d\n", ans);
    }
    return 0;
}
