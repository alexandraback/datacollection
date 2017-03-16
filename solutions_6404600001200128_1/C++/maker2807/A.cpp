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



int main() {
    int T;
    cin >> T;
    FOR(t,T) {
        int N;
        cin >> N;
        vector <lint> m(N);
        FOR(i,N) cin >> m[i];
        lint res1=0,res2=0,maxd=0;
        FOR(i,N-1) {
            if (m[i+1]<m[i]) {
                res1+=m[i]-m[i+1];
                maxd=max(maxd,m[i]-m[i+1]);
            }
        }
        FOR(i,N-1) {
            res2+=min(m[i],maxd);
        }

        cout << "Case #" << t+1 << ": ";
        cout << res1 << " " << res2 << endl;
    }

}
