#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

void solve(const vector<int> &M, int &y, int &z){
    y = z = 0;
    int m = 0;
    REP(i,(int)M.size()-1){
        m = max(m, M[i]-M[i+1]);
        y += max(0, M[i]-M[i+1]);;
    }
    REP(i,(int)M.size()-1){
        z += min(m, M[i]);
    }
}

int main(){
    int T;
    cin >> T;

    REP(i, T){
        int N;
        cin >> N;
        vector<int> M(N);
        REP(j,N)cin >> M[j];
        int y,z;
        solve(M,y,z);
        cout << "Case #" << i+1 << ": "<< y << " " << z << endl;
    }
    return 0;
}
