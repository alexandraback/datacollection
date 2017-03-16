#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <iterator>

using namespace std;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}


//typedef
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int,int> mii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

//container util
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
/******* All Required define Pre-Processors and typedef Constants *******/
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back


int N;
int m[10000];
int main(int argc, char *args[]) {
    freopen("/Users/Hikaru/Desktop/A-small-attempt0.in","rt",stdin);
//    freopen("/Users/Hikaru/Desktop/small.in","rt",stdin);
    freopen("/Users/Hikaru/Desktop/A-small-attempt0.out","wt",stdout);
    
    int T;
    cin >> T;
    FOR(caseNum,1,T+1){
        cin >> N;
        FOR(i,0,N){
            cin >> m[i];
        }
        int sumMush = 0;
        FOR(i,1,N){
            if(m[i] < m[i-1]){
                sumMush += m[i-1] - m[i];
            }
        }
        int ans1 = sumMush;
        
        //--------------------------------------------------------------
        int maxRate = 0;
        FOR(i,1,N){
            if(m[i] < m[i-1]){
                maxRate = max(maxRate,m[i-1] - m[i]);
            }
        }
        dump(maxRate)
        sumMush = 0;
        FOR(i,0,N-1){
            sumMush += min(m[i],maxRate);
        }
        int ans2 = sumMush;
        printf("Case #%d: %d %d\n", caseNum, ans1, ans2);
    }
}
