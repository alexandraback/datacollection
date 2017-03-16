#include <bits/stdc++.h>
using namespace std;

#define debug(args...) fprintf(stderr,args)

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

const int INF = 0x3f3f3f3f;
const lint LINF = 0x3f3f3f3f3f3f3f3fll;

bool cards[2][20];

int main() {
    int t=1,T;
    for(scanf("%d",&T);t<=T;++t) {
        memset(cards,0,sizeof(cards));        
        for(int a=0;a<2;++a) {
            int r;
            scanf("%d",&r);
            for(int b=1;b<=4;++b) {
                for(int c=0;c<4;++c) {
                    int x;
                    scanf("%d",&x);
                    if(b == r) cards[a][x] = 1;
                }
            }
        }
        int ans, cnt=0;
        for(int a=1;a<=16;++a) {
            if(cards[0][a] && cards[1][a]) {
                cnt++;
                ans = a;
            }
        }
        printf("Case #%d: ",t);
        if(cnt == 0) printf("Volunteer cheated!\n");
        else if(cnt > 1) printf("Bad magician!\n");
        else printf("%d\n",ans);
    }        
    return 0;
}
