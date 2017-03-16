#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

const int N = 17;

int r, c, n, x[N][N];

int co() {
    int i, j, rr = 0;

    for(i = 1; i <= r; ++i)
        for(j = 1; j <= c; ++j) if(x[i][j])
            rr += x[i][j + 1] + x[i][j - 1] + x[i - 1][j] + x[i + 1][j];
    return rr;
}

int calc(int m) {
    int i, j, nr = 0;
    memset(x, 0, sizeof(x));

    for(i = 1; i <= r; ++i)
    for(j = 1; j <= c; ++j) {
        x[i][j] = (m & (1<<nr));
        if(x[i][j])
            x[i][j] = 1;
        ++nr;
    }

    return co() / 2;
}

void brut() {
    int i, j;
    int rez = 1000000;

    for(i = 1; i < (1<<(r * c)); ++i) {
        int nrb = 0;

        for(j = 0; j < (r * c); ++j) if(i & (1<<j))
            ++nrb;

        if(nrb == n)
            rez = min(rez, calc(i));
    }

    cout << rez;
}

void sol() {

}

int main() {
    freopen("ttt", "r", stdin);
    freopen("tttt", "w", stdout);

    int t, a = 0;
    cin >> t;

    while(t--) {
        ++a;
        cout << "Case #" << a << ": ";

        cin >> r >> c >> n;

        if(!n) {
            cout << "0\n";
            continue;
        }

        sol();
        brut();
        cout << "\n";
    }

    return 0;
}
