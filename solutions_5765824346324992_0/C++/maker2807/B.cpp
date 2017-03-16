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
        lint B,N;
        cin >> B >> N;
        vector<lint> m(B);
        lint pm=1;
        FOR(i,B) {
            cin >> m[i];
            pm*=m[i];
        }

        //cerr << B*pm << endl;
        lint modulator=0;
        FOR(i,B) modulator+=(pm)/m[i];
        cerr << modulator << endl;
        N%=(modulator);
        if (N==0) N=modulator;

        vector<lint> avail(B,0);
        lint mini=0;
        FOR(i,N) {
            mini = 0;
            FOR(j,B) {
                if (avail[j]<avail[mini]) mini=j;
            }
            avail[mini]+=m[mini];
        }
        //if (N==0) mini=B-1;

        cout << "Case #" << t+1 << ": ";
        cout << mini+1 << endl;
    }

}
