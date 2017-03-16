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
#include <climits>

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
        //lint pm=1;
        FOR(i,B) {
            cin >> m[i];
            //pm*=m[i];
        }

        //cerr << B*pm << endl;
        //lint modulator=0;
        //FOR(i,B) modulator+=(pm)/m[i];
        //cerr << modulator << endl;
        //N%=(modulator);
        //if (N==0) N=modulator;

        vector<lint> avail(B,0);

        lint left=0, mid=0, right=LLONG_MAX/3;
        while (left<right) {

            mid = (left+right)/2;
            lint cn=0;
            FOR(i,B) {
                cn+=mid/m[i]+COND(mid%m[i],1,0);
            }
            //cerr << left << " " << right <<" "<<cn<< " " <<mid << endl;
            if (cn<N && N-cn>B && N-cn<3*B) break;
            if (N-cn<=B) right=mid-1;
            else left=mid+1;
        }

        if (left<right)  {
            lint cn=0;
            FOR(i,B) {
                lint p=mid/m[i]+COND(mid%m[i],1,0);
                cn+=p;
                avail[i]=p*m[i];
            }
            //cerr << "N, cn, mid " << N << " " << cn << " " << mid << endl;
            N-=cn;
            //cerr << "N decreased" << endl;
        }
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
        cerr << t+1 << endl;
    }

}
