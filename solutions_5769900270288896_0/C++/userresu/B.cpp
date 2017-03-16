#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int R,C,N;
int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int zz=1;zz<=T;++zz) {
        scanf("%d %d %d",&R,&C,&N);
        printf("Case #%d: ",zz);
        if (R==C && C==1) {
            printf("0\n");
        }
        else if (R==1 || C==1) {
            if (R==1) R=C;
            if (N<=(R+1)/2) printf("0\n");
            else {
            N = R - N;
            int bst = 0;
            for (int c=1;c>=0;--c) {
            int cnt = 0;
            int h[5];
            h[1] = h[2] = h[3] = h[4] = 0;
            for (int i=0;i<R;i+=2) if (i%2==c) {
                if (i==0) ++h[1];
                else if (i==R-1) ++h[1];
                else ++h[2];
            }
            if (h[2] <= N) cnt = 2 * N;
            else if (h[1] + h[2] <= N) cnt = 2 * h[2] + 1 * (N-h[2]);
            if (bst < cnt) bst = cnt;
            }
            printf("%d\n",R-1-bst);
            }
        }
        else {
            N = R * C - N;
            int bst = 0;
            int mxother = 0;
            for (int c=1;c>=0;--c) {
            int cnt = 0;
            int h[5];
            h[2] = h[3] = h[4] = 0;
            int other = 0;
            for (int i=0;i<R;i++) for (int j=0;j<C;j++) if ((i+j)%2==c) {
                if (i && j && i < R-1 && j < C-1) ++h[4];
                if (i>0 && i < R-1 && j == C-1) ++h[3];
                if (i>0 && i < R-1 && j == 0) ++h[3];
                if (j>0 && j < C-1 && i == 0) ++h[3];
                if (j>0 && j < C-1 && i == R-1) ++h[3];
                if ((i == R-1||i==0) && j == C-1) ++h[2];
                if ((i == R-1||i==0) && j == 0) ++h[2];
                ++other;
            }
            if (h[4] >= N) cnt = 4 * N;
            else if (h[3] + h[4] >= N) cnt = 4 * h[4] + 3 * (N-h[4]);
            else if (h[2] + h[3] + h[4] >=N) cnt = 4 * h[4] + 3 * h[3] + 2 * (N-h[4]-h[3]);
            if (bst < cnt) bst = cnt;
            mxother = max(other,mxother);
            }
            if (mxother >= R*C-N) printf("0\n");
            else printf("%d\n",2*R*C-R-C-bst);
        }
    }
    return 0;
}
