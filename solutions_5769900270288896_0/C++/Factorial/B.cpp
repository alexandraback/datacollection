#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <utility>
#include <iterator>
#include <fstream>
#include <cstdio>
#include <functional>
#include <cassert>
#include <array>

using namespace std;

template<class T>
string tostring(T a){ stringstream ss; ss << a; return ss.str(); }

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> II;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])

int NextChoose(int x) {
	int c = x&-x, r = x + c;
	return (((r^x) >> 2) / c) | r;
}

int main(){
	ifstream be("B-small-attempt0.in");
	ofstream ki("ki.txt");
	int T;
	be >> T;
	FOR(tt, T){
		int r, c, n; be >> r >> c >> n;
		int rc = r*c;
		int mi = 1000000;
		if(n == 0){
			mi = 0;
		} else {
			for(int x = (1 << n) - 1; x < (1 << rc); x = NextChoose(x)) {
				int u = 0;
				FOR(k, rc){
					//int i = k / c, j = k % c;
					if((x >> k) & 1) {
						if(k % c < c - 1) {
							if((x >> (k + 1)) & 1)
								u++;
						}
						if(k / c < r - 1) {
							if((x >> (k + c)) & 1)
								u++;
						}
					}
				}
				if(u < mi){
					mi = u;
				}
			}
		}
		ki<<"Case #"<<tt+1<<": "<<mi<<endl;
	}

	ki.close();
	return 0;
}