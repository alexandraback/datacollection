#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

#define mx 1000000

int W[100][100];

int main() {
    cin.sync_with_stdio(false);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    long long r, c, n;
    
    int test_case = 0;
    int i, i1, j, j1;
    while(t--) {
        cin >> r >> c >> n;
        int ans = -1;
        //cout << (1<<(r * c + 1)) << endl;
        for (i = 0; i < (1<<(r * c + 1)); i++) {
            int k = 0;
            for (j = 0; j < r*c; j++) {
                if ((i >> j) & 1) k++;
            }
            //cout << i << ":" << k << endl;
            if (k == n) {
                //cout << i << endl;
                for(i1 = 0; i1 < r; i1++) {
                    for (j1 = 0; j1 < c; j1++) {
                        if ((i >> (i1 * c + j1) )& 1) W[i1][j1] = 1;
                        else W[i1][j1] = 0;
                    }
                }
                int p = 0;
                for(i1 = 0; i1 < r; i1++) {
                    for (j1 = 0; j1 < c; j1++) {
                        if (i1 + 1 < r && W[i1][j1] == 1 && W[i1+1][j1] == 1) p++; 
                        if (j1 + 1 < c && W[i1][j1] == 1 && W[i1][j1 + 1] == 1) p++;
                    }
                }
                
                if (ans == -1 || p < ans) {
                    ans = p;
                    /*for(i1 = 0; i1 < r; i1++) {
                        for (j1 = 0; j1 < c; j1++) {
                            cout << W[i1][j1];
                        }
                        cout << endl;
                    }
                    cout << i << endl;*/
                }
            }
        }
        
        test_case++;
        cout << "Case #" << test_case << ": " << ans << endl;
    }
    
    return 0;
}
