/* In the name of ALLAH, most gracious, most merciful */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <ios>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <queue>
#include <cassert>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

typedef long long ll;

int r, c, n;
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int recur(int idx, int taken, int mask){
    if(taken < 0) return 1e9;
    if(idx == r*c){
        if(taken != n) return 1e9;
        int ret = 0;
        for(int i = 0; i < r*c; i++){
            if((mask >> i) & 1){
                int myR = i / c;
                int myC = i % c;
                for(int k = 0; k < 4; k++){
                    int nR = myR + dr[k];
                    int nC = myC + dc[k];
                    if(nR >= r || nR < 0 || nC >= c || nC < 0) continue;
                    ret += (mask >> (nR * c + nC)) & 1;
                }
            }
        }
        return ret;
    }
    return min(recur(idx + 1, taken + 1, mask | (1 << idx)),
            recur(idx + 1, taken, mask));
}

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int t;
    cin >> t;
    for(int T = 1; T <= t; T++){
        cin >> r >> c >> n;
        cout << "Case #" << T << ": " << recur(0, 0, 0) / 2 << endl;
    }

}
