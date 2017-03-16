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

int solve(int testnr){
    int N, R, C;
    cin >> R >> C >> N;
    if (N <= (R * C + 1)/2) return 0;
    if (R > C) {
        int h = R;
        R = C;
        C = h;
    }
    int walls = (R-1) * C + R * (C-1);//22
    int empty = R * C - N; //5
    if (R == 1) {
        return walls - 2 * empty;
    }
    int rooms_with_four_walls = (R-2) * (C-2); //3
    if (empty <= (rooms_with_four_walls+1)/2) return walls - 4 * empty;
    if (R % 2 == 1 && C % 2 == 1) {
        int central = R - 3 + C - 3;//2
        if (empty <= central + (rooms_with_four_walls+1)/2) return walls - 4 * (rooms_with_four_walls+1)/2 - 3 * (empty - (rooms_with_four_walls+1)/2);
        return walls - 4 * (rooms_with_four_walls/2) - 3 * (empty - rooms_with_four_walls/2);
    } else {
        if (N == R * C / 2 + 1) return 2;
        return walls - 4 * rooms_with_four_walls / 2 - 3 * (empty - rooms_with_four_walls / 2);
    }
}

int main(){

    init();
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": " << solve(i) << "\n";
    }
    
    return 0;
}
