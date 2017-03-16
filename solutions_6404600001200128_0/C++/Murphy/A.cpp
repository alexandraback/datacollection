#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int main(){
    int caseNumber;
    //scanf("%d", &caseNumber);
    cin>>caseNumber;
    REP(caseN, caseNumber) {
        int r1 = 0, r2 = 0;
        int N; cin>>N;
        vector<int> V(N, 0);
        REP(i, N) {
            cin>>V[i];
        }
        REP(i, N - 1) if (V[i + 1] < V[i]) r1 += V[i] - V[i + 1];
        REP(i, N - 1) if (V[i + 1] < V[i]) r2 = max(r2, V[i] - V[i + 1]);
        // if (r2 / 10 * 10 != r2) r2 = (r2 / 10 + 1) * 10;
        // cout<<r2<<endl;
        int r3 = 0;
        REP(i, N - 1) r3 += min(r2, V[i]);
    	printf("Case #%d: %d %d\n", caseN + 1, r1, r3);
    }
    return 0;
}