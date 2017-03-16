#include <cstdio>
#include <cstring>

#define min(a, b) (a < b ? a : b)

using namespace std;

bool M[32][32];
int r, c, n;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int best, T, C=1;

void vai(int i, int j, int n) {
    if (n==0) {
        int total=0;
        for (int x=0;x<r;x++)
            for (int y=0;y<c;y++) if (M[x][y])
                for (int k=0;k<4;k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (!(0 <= nx and nx < r and 0 <= ny and ny < c)) continue;
                    if (M[nx][ny])
                        total++;
                }
        best = min(best,total);
        return;
    }

    if (i==r) return; // fail
    if (j==c) {
        vai(i+1,0,n);
        return;
    }

    // com
    M[i][j] = true;
    vai(i,j+1,n-1);

    // sem
    M[i][j] = false;
    vai(i,j+1,n);

}

int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d %d %d",&r,&c,&n);
        memset(M,false,sizeof(M));
        best = 0x3f3f3f3f;
        vai(0,0,n);
        printf("%d\n",best/2);
    }

    return 0;
}
