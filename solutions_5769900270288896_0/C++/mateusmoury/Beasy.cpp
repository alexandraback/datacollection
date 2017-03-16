#include <bits/stdc++.h>
#define fr(i,a,b) for(int i =(a); i < (b); ++i)
#define cl(a,b) memset(a, b, sizeof a)

using namespace std;

const int INF = 1000000000;

int R, C, N;

int ans;

int mark[20][20];

void bt(int r, int c, int qtd) {
    //cout << r << " " << c << " " << qtd << endl;
    if(r==R) {
        if(qtd==N) {
            int tmp = 0;
            fr(i,0,R)
                fr(j,1,C)
                    if(mark[i][j] && mark[i][j-1])
                        tmp++;
            fr(j,0,C)
                fr(i,1,R) 
                    if(mark[i][j] && mark[i-1][j])
                        tmp++;
            ans = min(ans, tmp);
        }
        return;
    }
    if(c==C) {
        bt(r+1,0,qtd);
        return;
    }
    bt(r,c+1,qtd);
    if(qtd<N) {
        mark[r][c] = 1;
        bt(r,c+1,qtd+1);
        mark[r][c] = 0;
    }
}

int main() {
    int T; scanf("%d", &T);
    fr(cases,1,T+1) {
        cl(mark, 0);
        scanf("%d %d %d", &R, &C, &N);
        ans = INF;
        bt(0,0,0);
        printf("Case #%d: %d\n", cases, ans);
    }
    return 0;
}