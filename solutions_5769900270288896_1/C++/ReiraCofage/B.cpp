#include <cstdio>
#include <cstring>
#include <vector>

#define min(a, b) (a < b ? a : b)

using namespace std;

vector<vector<bool> > M;
int r, c, n;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int best, T, C=1;

// ._._._
// _._._.
int opc1() {
    for (int i=0;i<(int)M.size();i++)
        M[i].clear();
    M.clear();
    M.resize(r);
    for (int i=0;i<r;i++) {
        M[i].resize(c);
        for (int j=0;j<c;j++)
            M[i][j] = false;
    }

    // chess
    int falta=n;
    for (int i=0;i<r;i++)
        for (int j=(i&1);j<c;j+=2)
            if (falta) {
                M[i][j]=true;
                falta--;
            }

    // bordas
    if (falta and M[0][0]==false) { M[0][0]=true; falta--; }
    if (falta and M[0][c-1]==false) { M[0][c-1]=true; falta--; }
    if (falta and M[r-1][0]==false) { M[r-1][0]=true; falta--; }
    if (falta and M[r-1][c-1]==false) { M[r-1][c-1]=true; falta--; }

    // primeira e ultima linha e coluna
    for (int j=0;j<c;j++) if (!M[0][j] and falta) { M[0][j]=true; falta--;}
    for (int j=0;j<c;j++) if (!M[r-1][j] and falta) { M[r-1][j]=true; falta--;}
    for (int i=0;i<r;i++) if (!M[i][0] and falta) { M[i][0]=true; falta--;}
    for (int i=0;i<r;i++) if (!M[i][c-1] and falta) { M[i][c-1]=true; falta--;}

    // resto
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            if (!M[i][j] and falta) {
                M[i][j] = true;
                falta--;
            }

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

    return total/2;
}


// _._._.
// ._._._
int opc2() {
    for (int i=0;i<(int)M.size();i++)
        M[i].clear();
    M.clear();
    M.resize(r);
    for (int i=0;i<r;i++) {
        M[i].resize(c);
        for (int j=0;j<c;j++)
            M[i][j] = false;
    }

    // chess
    int falta=n;
    for (int i=0;i<r;i++)
        for (int j=((i&1)?0:1);j<c;j+=2)
            if (falta) {
                M[i][j]=true;
                falta--;
            }

    // bordas
    if (falta and M[0][0]==false) { M[0][0]=true; falta--; }
    if (falta and M[0][c-1]==false) { M[0][c-1]=true; falta--; }
    if (falta and M[r-1][0]==false) { M[r-1][0]=true; falta--; }
    if (falta and M[r-1][c-1]==false) { M[r-1][c-1]=true; falta--; }

    // primeira e ultima linha e coluna
    for (int j=0;j<c;j++) if (!M[0][j] and falta) { M[0][j]=true; falta--;}
    for (int j=0;j<c;j++) if (!M[r-1][j] and falta) { M[r-1][j]=true; falta--;}
    for (int i=0;i<r;i++) if (!M[i][0] and falta) { M[i][0]=true; falta--;}
    for (int i=0;i<r;i++) if (!M[i][c-1] and falta) { M[i][c-1]=true; falta--;}

    // resto
    for (int i=0;i<r;i++)
        for (int j=0;j<c;j++)
            if (!M[i][j] and falta) {
                M[i][j] = true;
                falta--;
            }

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

    return total/2;
}

int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d %d %d",&r,&c,&n);
        int resp = min(opc1(), opc2());

        printf("%d\n",resp);
    }

    return 0;
}
