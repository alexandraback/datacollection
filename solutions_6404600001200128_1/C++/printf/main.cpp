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
using namespace std;
struct point{
    int a;
    int b;
} pt[1005];
bool fn (struct point x, struct point y) {
    int m1 = min(x.a, x.b);
    int m2 = min(y.a, y.b);
    return m1 < m2;
}

int main()
{
    int t;
    long long n, a[1005];
    
    ifstream fp ("/Users/aviral.gupta/Downloads/in.txt");
    ofstream ofp ("/Users/aviral.gupta/Downloads/out.txt");
    fp >> t;
    for(int k = 1; k <= t; k++) {
        fp >> n;
        for (int i =0; i < n; i++) {
            fp >> a[i];
        }
        long long res1 = 0, res2 = 0, res3 = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) res1 += a[i-1] - a[i];
        }
        for (int i = 1; i < n; i++) {
            if (res2 < a[i - 1] - a[i]) res2 = a[i - 1] - a[i];
        }
        if (res2 < 0) res2 = 0;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < res2) res3 += a[i];
            else res3 += res2;
        }

        ofp << "Case #" << k << ": " << res1 << " " << res3 << endl;
    }
    fp.close();
    ofp.close();
    cout << "done" << endl;
    return 0;
}
