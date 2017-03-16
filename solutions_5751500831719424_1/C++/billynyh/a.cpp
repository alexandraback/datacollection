#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

int DEBUG = 0;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

char s[200][200];

int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        int n; scanf("%d", &n);
        int p[n], len[n]; 
        for (int i=0;i<n;i++) {
            scanf("%s", s[i]);
            p[i] = 0;
            len[i] = strlen(s[i]);
        }

        int ans = 0;

        bool ok = true;

        while (true) {
            char c = s[0][p[0]];
            int cnt[n];

            for (int i=0;i<n;i++) {
                cnt[i]=0;
                for (int j=p[i]; j<len[i] && s[i][j]==c; j++) {
                    cnt[i]++;
                }
                p[i] += cnt[i];

                if (cnt[i]==0) ok = false;
            }
            sort(cnt, cnt+n);

            if (DEBUG) {
            printf("- %c %d\n", c, cnt[n/2]);

            printf("p   - ");
            for (int i=0;i<n;i++) printf("%d ", p[i]); puts("");

            printf("cnt - ");
            for (int i=0;i<n;i++) printf("%d ", cnt[i]); puts("");
            }
            
            for (int i=0;i<n;i++) {
                ans += abs(cnt[i] - cnt[n/2]);
            }

            bool done = true;
            for (int i=0;i<n;i++) {
                if (p[i] < len[i]) done = false;
            }
            if (done) break;
            if (!ok) break;
        }

        if (ok) {
            printf("Case #%d: %d\n",ti,ans);
        } else {
            printf("Case #%d: Fegla Won\n",ti);
        
        }
    }
    return 0;
}
