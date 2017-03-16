#include <iostream>

using namespace std;


int main(){
    int t, r, c, n, pot;
    int p[20][20];
    int i, j, k, m, tmp, b, tmpr;
    int res;
    
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> r >> c >> n;
        pot = 1;
        for (j = 0; j < r*c; j++)
            pot *= 2;
        res = r*c*4;
        for (j = 0; j < pot; j++) {
            tmp = j;
            //cout << "tmp " << tmp << endl;
            b = 0;
            for (k = 0; k < r; k++) {
                for (m = 0; m < c; m++) {
                    if (tmp % 2 == 0) p[k][m] = 0;
                    else {
                        p[k][m] = 1;
                        b++;
                    }
                    tmp = tmp >> 1;
                    //cout << "tmp_shifted " << tmp << endl;
                }
            }
            if (b != n) continue;
            
            tmpr = 0;
            for (k = 0; k < r; k++) {
                for (m = 0; m < c; m++) {
                    if (p[k][m] == 1) {
                        if (k + 1 < r) tmpr += p[k+1][m];
                        if (m + 1 < c) tmpr += p[k][m+1];
                    }
                }
            }
            if (tmpr < res) res = tmpr;
        }
        
        cout << "Case #" << i+1 << ": " << res << endl;
    }

    return 0;
}
