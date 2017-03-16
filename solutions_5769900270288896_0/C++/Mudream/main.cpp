#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    int T; scanf("%d", &T);
    for(int lt = 1;lt <= T;lt++){
        int r, c, k; scanf("%d %d %d", &r, &c, &k);
        int ans = 1000000;
        for(int sts = 0; sts < (1<<(r*c));sts++){
            int cntk = 0;
            int tab[16][16] = {0};
            for(int lx = 0;lx < r*c;lx++){
                if(sts&(1<<lx)){
                    cntk++;
                    tab[lx/r][lx%r] = 1;
                }
            }
            if(cntk != k) continue;
            int test = 0;
            for(int lx = 0;lx < c;lx++){
                for(int ly = 0;ly < r;ly++){
                    if(lx+1 < c) test += tab[lx][ly]&tab[lx+1][ly];
                    if(ly+1 < r) test += tab[lx][ly+1]&tab[lx][ly];
                }
            }
            ans = min(ans, test);
        } 
        printf("Case #%d: %d\n", lt, ans);
    }
    return 0;
}
