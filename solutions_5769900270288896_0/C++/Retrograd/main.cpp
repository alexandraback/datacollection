#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef int var;

var best = 200000;
var m, n, k;

var A[100][100];

void check() {
    var c = 0;
    for(var i=1; i<=n; i++) {
        for(var j=1; j<=m; j++) {
            if(i < n && A[i][j] && A[i+1][j])
                c++;
            if(j < m && A[i][j] && A[i][j+1])
                c++;
        }
    }
    best = min(best, c);
}

void gen(var pas, var ci, var cj) {
    if(pas > k) {
        check();
    } else {
        for(var i=ci; i<=n; i++) {
            for(var j=cj; j<=m; j++) {
                if(!A[i][j]) {
                    A[i][j] = 1;
                    gen(pas+1, i, j);
                    A[i][j] = 0;
                }
            }
            cj = 1;
        }
    }
}

var Solve() {
    cin>>n>>m>>k;
    best = 200000;
    gen(1, 1, 1);
    return best;
}

int main() {
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);

    var t;
    cin>>t;
    for(var tt=1; tt<=t; tt++) {
        cout<<"Case #"<<tt<<": "<<Solve()<<'\n';
        cerr << "Gata "<<tt<<endl;
    }
}
