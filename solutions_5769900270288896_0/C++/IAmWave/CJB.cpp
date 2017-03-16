//Author: Václav Volhejn (IAmWave)
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;

const bool distribute = true;

void solve(istream *in, ostream *out) {
    int r, c, n;
    *in >> r >> c >> n;
    int s = r * c;
    vector<bool> co(s);
    rep(i, s - n, s) co[i] = true;
    int best = s * 4;
    do {
        bool map[r][c];
        rep(i, 0, r) rep(j, 0, c) {
            map[i][j] = co[j + i * c];
        }
        //rep(i,0,s) cout << co[i];
        //cout << endl;
        int cur = 0;
        rep(i, 0, r) rep(j, 0, c) {
            if(!map[i][j]) continue;
            if((j < (c - 1)) && map[i][j + 1]) cur++;
            if((i < (r - 1)) && map[i + 1][j]) cur++;
        }
        best = min(best, cur);
    } while(next_permutation(co.begin(), co.end()));
    *out << best << endl;
}

int main() {
    ostream *out;
    istream *in = new ifstream(distribute ? "/home/vaclav/Downloads/B-small-attempt3.in" : "in.txt");
    out = distribute ? (new ofstream("out.txt")) : &cout;
    int cases;
    *in >> cases;
    rep(caseI, 0, cases) {
        *out << "Case #" << (caseI + 1) << ": ";
        solve(in, out);
    }
    return 0;
}
