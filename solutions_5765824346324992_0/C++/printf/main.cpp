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
long long m[1005];
bool check(long long t, long long b, long long n) {
    long long res = 0;
    for (int i = 0; i < b; i++) {
        res += t/m[i];
        if (t!= 0 && t % m[i] != 0) res++;
    }
    return res < n;
}
long long solve(long long b, long long n) {
    long long left = 0, right = 1;
    while(check(right, b, n)) {
        left = right;
        right *= 2;
    }
    cout << left << " " << right << endl;
    while(!(check(left, b, n) && !check(left + 1, b, n))) {
        long long k = (left + right) / 2;
        if (check(k, b, n))
            left = k;
        else
            right = k;
    }
    cout << left << endl;
    int i, res = 0, r = 0;
    for (int i = 0; i < b; i++) {
        r += left/m[i];
        if (left % m[i] != 0) r++;
    }
    for (i = 0; i < b; i++)
        if (left % m[i] == 0) {
            res++;
            if (res == n - r) return i + 1;
        }
    return 0;
}
int main()
{
    int t;
    long long n, b;
    
    ifstream fp ("/Users/aviral.gupta/Downloads/in.txt");
    ofstream ofp ("/Users/aviral.gupta/Downloads/out.txt");
    fp >> t;
    for(int k = 1; k <= t; k++) {
        long long res = 0;
        fp >> b >> n;
        for (int i =0; i < b; i++)
            fp >> m[i];
        res = solve(b, n);
        ofp << "Case #" << k << ": " << res << endl;
    }
    fp.close();
    ofp.close();
    cout << "done" << endl;
    return 0;
}
