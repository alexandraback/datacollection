#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <utility>
#include <set>
#include <map>
#include <cctype>

#define FOR(i,n) for(long long int i=0; i<n; i++)
#define MP(a,b) make_pair(a,b)
#define PB(x) push_back(x)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(), a.end())

#define COND(p,t,f) ((p)?(t):(f))

#define PI 3.14159265

using namespace std;
typedef long long int lint;
typedef unsigned long long int ulint;


lint computeUnhappines(vector <vector <bool> >& a) {
    lint dx[] = {1,-1,0,0};
    lint dy[] = {0,0,1,-1};
    lint ret=0;
    FOR (i, a.size()) {
        FOR(j, a[0].size()) {
            if (!a[i][j]) continue;
            FOR(k,4) {
                lint ni = i + dx[k];
                lint nj = j + dy[k];
                if (ni<0 || ni>=a.size() || nj < 0 || nj >= a[0].size()) continue;
                if (a[ni][nj]) ret+=1;
            }
        }
    }
    return ret/2;
}

int main() {
    int T;
    cin >> T;
    FOR(t,T) {
        lint N,R,C;
        cin >> R >> C >> N;
        lint best=47*R*C*N;
        FOR(n,1<<(R*C)) {
            //cerr << (1<<(R*C)) << endl;
            vector <vector <bool> > a(R, vector<bool> (C,false));
            lint p=0;
            lint filled=0;
            FOR(i,R) {
                FOR (j,C) {
                    if (n&(1<<p)) {
                        a[i][j] = true;
                        filled++;
                    }
                    p++;
                }
            }
            if (filled!=N) continue;
            best = min(best,computeUnhappines(a));
        }

        cout << "Case #" << t+1 << ": " << best << endl;

    }

}
