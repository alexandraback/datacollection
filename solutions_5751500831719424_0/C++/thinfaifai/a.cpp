#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL long long

int n,tot;
int ch[105][105],app[105];
char s[105];

int main() {
    int tc;
    scanf("%d",&tc);
    for (int t=1; t<=tc; t++) {
        scanf("%d",&n);
        int ok = 1;
        for (int i=0; i<n; i++) {
            scanf("%s",s);
            int len = strlen(s);
            if (i == 0) {
                app[0] = s[0]-'a';
            }
            else {
                if (app[0] != s[0]-'a') ok = 0;
            }
            ch[0][i] = 1;
            int at = 0;
            for (int j=1; j<len; j++)
                if (s[j] != s[j-1]) {
                    if (i == 0) app[++at] = s[j]-'a';
                    else {
                        at++;
                        if (app[at] != s[j]-'a') ok = 0;
                    }
                    ch[at][i] = 1;
                }
                else ch[at][i]++;
            if (i == 0) tot = at;
            else if (at != tot) ok = 0;
            //printf("%d: %d %d\n",i,at,tot);
        }
        if (!ok) {
            printf("Case #%d: Fegla Won\n",t);
            continue;
        }
        tot++;
        int ans = 0;
        for (int i=0; i<tot; i++) {
            int mi = 1000000;
            for (int k=1; k<=100; k++) {
                int cur = 0;
                for (int j=0; j<n; j++) {
                    cur += abs(ch[i][j]-k);
                }
                mi = min(cur,mi);
            }
            ans += mi;
        }
        printf("Case #%d: %d\n",t,ans);
    }
	return 0;
}
