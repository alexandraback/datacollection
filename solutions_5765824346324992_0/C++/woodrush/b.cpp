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


int B, N;
uint64 M[100000];
int main(int argc, char *args[]) {
    freopen("/Users/Hikaru/Desktop/B-small-attempt1.in","rt",stdin);
//    freopen("/Users/Hikaru/Desktop/small.in","rt",stdin);
    freopen("/Users/Hikaru/Desktop/B-small-attempt1.out","wt",stdout);
    
    int T;
    cin >> T;
    FOR(caseNum,1,T+1){
        cin >> B >> N;
        FOR(i,0,B){
            cin >> M[i];
        }
        int ans = -1;
        uint64 minutesMaxT = 1000000000000000000;
        uint64 minutesMinT = 0;
        uint64 minutesTest = 1000000000000000000/2;
        int j = 0;
        uint64 sumN = 0;
        while(j++ < 100){
            //        while(j++ < 40){
            sumN = 0;
            FOR(i,0,B){
                sumN += minutesTest/M[i] + (minutesTest % M[i] == 0 ? 0 : 1);
            }
            if(N+B < sumN){
                minutesMaxT = minutesTest;
            } else if(sumN < N+B){
                minutesMinT = minutesTest;
            }
            minutesTest = (minutesMaxT + minutesMinT)/2;
        }
        while(sumN >= N){
            minutesTest--;
            sumN = 0;
            FOR(i,0,B){
                sumN += minutesTest/M[i] + (minutesTest % M[i] == 0 ? 0 : 1);
            }
        }
        sumN = 0;
        FOR(i,0,B){
            sumN += minutesTest/M[i] + (minutesTest % M[i] == 0 ? 0 : 1);
        }
        FOR(i,0,B){
            if(minutesTest % M[i] == 0){
                sumN++;
            }
            if(sumN == N){
                ans = i;
                break;
            }
        }
        printf("Case #%d: %d\n", caseNum, ans+1);
    }
}
