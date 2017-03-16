#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

int t[17][17][17];
bool tab[17][17];

int hany(int n, int m) {
    int c=0;
    for (int a=1;a<=n;a++) for (int b=1;b<=m;b++) if (tab[a][b]) c++;
    return c;
}

int szamol(int n, int m) {
    int c=0;
    for (int a=1;a<=n;a++) for (int b=1;b<=m;b++) {
        int k=0;
        for (int i=max(1, a-1);i<=min(n, a+1);i++) {
            for (int j=max(1, b-1);j<=min(m, b+1);j++) {
                if (abs(a-i)+abs(b-j)==1) if (tab[i][j] && tab[a][b]) k++;
            }
        }
        c+=k;
    }
    return c/2;
}

int csinal(int n, int m, int x, int y) {
    if (x==n && y==m) {
        tab[n][m]=0;
        t[n][m][hany(n, m)]=min(szamol(n, m), t[n][m][hany(n, m)]);
        tab[n][m]=1;
        t[n][m][hany(n, m)]=min(szamol(n, m), t[n][m][hany(n, m)]);

        /*if (hany(n, m)==4 && n==2 && m==2) {
            cout << szamol(n, m)<<endl;
        }*/
    }
    else {
        tab[x][y]=0;
        if (y<m) {
            csinal(n, m, x, y+1);
        }
        else csinal(n, m, x+1, 1);

        tab[x][y]=1;
        if (y<m) {
            csinal(n, m, x, y+1);
        }
        else csinal(n, m, x+1, 1);
    }
}

int tt;

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("ki.txt", "w", stdout);

    for (int i=1;i<=16;i++) {
        for (int j=1;j<=16;j++) {
            for (int k=0;k<=16;k++) {
                t[i][j][k]=100000;
            }
        }
    }


    for (int i=1;i<=16;i++) {
        for (int j=1;j<=16;j++) {
            for (int a=1;a<=i;a++) for (int b=1;b<=j;b++) tab[a][b]=0;
            if (i*j<=16) csinal(i, j, 1, 1);
        }
    }
    /*for (int i=1;i<=16;i++) {
        for (int j=1;j<=16;j++) {
            for (int k=0;k<=16;k++) {
                cout << t[i][j][k]<<endl;
            }
        }
    }*/


    cin >> tt;
    for (int ttt=1;ttt<=tt;ttt++) {
        int r, c, n;
        cin >> r>> c>>n;
        cout << "Case #" << ttt<< ": " <<t[r][c][n]<<endl;
    }
    return 0;
}
