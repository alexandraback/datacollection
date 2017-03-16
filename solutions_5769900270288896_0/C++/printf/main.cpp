#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
#include <cstring>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <climits>
#include <iomanip> 
using namespace std;
typedef long long ll;
int calc(int b[][50], int r, int c) {
    int res = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (b[i][j] == 1) {
                if (i + 1 < r && b[i + 1][j] == 1) res++;
                if (j + 1 < c && b[i][j + 1] == 1) res++;
            }
        }
    }
    return res;
}
int main()
{
    int T;
    
    ifstream fp ("/Users/aviral.gupta/Downloads/in.txt");
    ofstream ofp ("/Users/aviral.gupta/Downloads/out.txt");

    fp >> T;
    for(int k = 1; k <= T; k++) {
        int n, r, c, sz, res = INT_MAX;
        fp >> r >> c >> n;
        sz = r * c;
        if (n == 0) {
            res = 0;
        } else {
            int a[50] = {0};
            for (int i = sz - n; i < sz; i++)
                a[i] = 1;
            
            do {
                
                int b[50][50] = {0};
                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        if (a[i * c + j] == 1) b[i][j] = 1;
                int rr = calc(b, r, c);
                //cout << k << " " << rr << endl;
                res = min(res, rr);
                
            } while (next_permutation(a, a + sz));
        }
        ofp << "Case #" << k << ": " << res << endl;
    }
    fp.close();
    ofp.close();
    cout << "done" << endl;
    return 0;
}
