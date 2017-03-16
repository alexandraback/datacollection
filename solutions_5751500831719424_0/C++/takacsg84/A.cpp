#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include <map>
#include <queue>
#include <functional>
#include <memory>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <bitset>
#include <time.h>
#include <assert.h>
#include <limits>

#define EPS (1e-9)
#define PI (2 * acos(0.0))
#define XOR(exp1,exp2) ( ( (exp1)&&!(exp2) ) || (!(exp1) && (exp2)) )
#define REP(x,n)  for(int x=0;x<(int)(n);x++)
#define FOR(x,y,n) for(int x=(int)y;x<(int)(n);x++)
#define RREP(x,n) for(int x=(int)(n)-1;x>=0;--x)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))


using namespace std;
typedef long long LL;
vector<string> X;
vector<int> IDX;
const string BAD = "Fegla Won";
string doStuff() {
    int N, result = 0;
    cin >> N;
    X = vector<string>(N), IDX = vector<int>(N);
    REP(i, N) cin >> X[i];
    while (IDX[0] < X[0].length()) {
        vector<int> temp(N);
        char ch = X[0][IDX[0]];
        REP(i, N) {
            if (X[i][IDX[i]] != ch) return BAD;
            while (IDX[i] < X[i].length() && X[i][IDX[i]] == ch)
                ++IDX[i], ++temp[i];
        }
        int low = numeric_limits<int>::max();
        FOR(k, 1, 101) {
            int aux = 0;
            REP(i, N) aux += abs(k - temp[i]);
            low = min(low, aux);
        }
        result += low;
    }
    REP(i, N) if (IDX[i] < X[i].length()) return BAD;
    cout << result;
    return "";
}

int main() {
    int T;
    scanf("%d", &T);
    REP(t, T) printf("Case #%d: ", t + 1), cout << doStuff() << endl;
    return 0;
}