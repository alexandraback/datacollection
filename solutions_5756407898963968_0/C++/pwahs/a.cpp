#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <ctime>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define dbg(args...) {debug,args; cerr << endl;}

#define mp make_pair
#define mt(a,b,c) mp(a,mp(b,c))
#define P1(a) (a).first
#define P2(a) (a).second
#define T1(a) (a).first
#define T2(a) (a).second.first
#define T3(a) (a).second.second
#define INF 1e20
#define EPS 1e-8

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> tiii;

class debu{
	public:
	template<class someClass>
	debu & operator,(someClass arg){
		cerr << arg << " ";
		return *this;
	}
} debug;


void init(){
    cout << setprecision(8)<< fixed;
}

void solve(int testnr){
    int r;
    vector<int> count(16,0);
    for (int i=0; i<2; i++){
        cin >> r;
        int dummy;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cin >> dummy;
                if (i==r-1) count[dummy-1]++;
            }
        }
    }
    
    int total = 0;
    int result = -1;
    for(int i=0;i<16;i++){
        if (count[i]==2){
            total++;
            result = i+1;
        }
    }
    if (total == 0) {
        cout << "Volunteer cheated!";
        return;
    }
    if (total == 1) {
        cout << result;
        return;
    }
    cout << "Bad magician!";
    return;
}

int main(){

    init();
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": ";
        solve(i);
        cout << "\n";
    }
    
    return 0;
}
