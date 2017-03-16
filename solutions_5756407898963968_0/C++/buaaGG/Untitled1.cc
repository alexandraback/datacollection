#include <iostream>
#include <algorithm>
using namespace std;



void solve(int ri) {
    int r1; cin >> r1; --r1;
    int mat1[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> mat1[i][j];
        }
    }
    int r2; cin >> r2; --r2;
    int mat2[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> mat2[i][j];
        }
    }
    sort( begin(mat1[r1]), end(mat1[r1]) );
    sort( begin(mat2[r2]), end(mat2[r2]) );
    int mat[4];
    auto iter = set_intersection(  begin(mat1[r1]), end(mat1[r1]), begin(mat2[r2]), end(mat2[r2]), mat );
    printf("Case #%d: ", ri);
    if ( iter - mat == 1 ) {
        cout << mat[0] << endl;
    } else if ( iter == mat ) {
        cout << "Volunteer cheated!" << endl;
    } else {
        cout << "Bad magician!" << endl;
    }
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
    int re; cin >> re;
    for (int ri = 1; ri <= re; ++ri) solve(ri);
}
