#include <bits/stdc++.h>
#define MAX_R 18
using namespace std;

int t, r, c, n;
char mat[MAX_R][MAX_R];

int tot_board() {
    int ans=0;
    for (int i=0; i<r-1; i++) {
        for (int j=0; j<c; j++) {
            if (mat[i][j]=='x' && mat[i+1][j]=='x') ans++;
        }
    }
    for (int i=0; i<r; i++) {
        for (int j=0; j<c-1; j++) {
            if (mat[i][j]=='x' && mat[i][j+1]=='x') ans++;
        }
    }
    return ans;
}

int compute(int i, int j) {
    if (i>=r) {
        if (n!=0) return 1 << 26;
        return tot_board();
    }
    int ans=INT_MAX;
    if (n>0) {
        mat[i][j]='x';
        n--;
        if (j==c-1) {
            ans=min(ans,compute(i+1,0));
        }
        else {
            ans=min(ans,compute(i,j+1));
        }
        n++;
        mat[i][j]='.';
    }
    if (j==c-1) {
        ans=min(ans,compute(i+1,0));
    }
    else {
        ans=min(ans,compute(i,j+1));
    }
    return ans;
}

int main(void) {
    if (fopen("b.in","r")) {
        freopen("b.in","r",stdin);
        freopen("b.out","w",stdout);
    }
    cin >> t;
    for (int ii=1; ii<=t; ii++) {
        cin >> r >> c >> n;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                mat[i][j]='.';
            }
        }
        cout << "Case #" << ii << ": " << compute(0,0) << "\n";
    }
    return 0;
}
