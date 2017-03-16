#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define N 20

int ans, nr, nc, target;

int check(int a[][N]) {
    int ret = 0;

    for(int i = 0; i < nr; i++)
        for(int j = 0; j < nc; j++)
            if(a[i][j]) {
                if(j + 1 < nc)
                    ret += a[i][j + 1];
                if(i + 1 < nr)
                    ret += a[i + 1][j];
            }
    return ret;
}

void f(int a[][N], int r, int c, int k) {
    if(r == nr && k == target) {
        ans = min(ans, check(a));
        return ;
    }
    if(r == nr && k != target)
        return ;

    a[r][c] = 1;
    if(c == nc - 1)
        f(a, r + 1, 0, k + 1);
    else 
        f(a, r, c + 1, k + 1);
    
    a[r][c] = 0;
    if(c == nc - 1)
        f(a, r + 1, 0, k);
    else f(a, r, c + 1, k);
}

int main ( void ) {
    int TA; cin >> TA;
    int a[N][N];
    int cc = 1;

    while(TA--) {
        cin >> nr >> nc >> target;
        ans = 10000000;
        memset(a, 0, sizeof a);

        printf("Case #%d: ", cc++);

        f(a, 0, 0, 0);
        cout << ans << endl;
    }



}

