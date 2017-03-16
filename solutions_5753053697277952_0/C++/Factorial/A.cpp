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


char party(int x){
	return 'A' + x;
}

int main(){
	ifstream be("A-small-attempt0.in");
	ofstream ki("ki.txt");
	int T;
	be >> T;
	FOR(tt, T){
		int n;
		be >> n;
		VI p;
		FOR(i, n){
			int x;
			be >> x;
			p.push_back(x);
		}

		ki << "Case #" << tt + 1 << ":";
		while(1){
			int ma = -1, mh = -2;
			int c = 0;
			FOR(i, n){
				if(p[i] > ma){
					ma = p[i];
					mh = i;
				}
				if(p[i])
					c++;
			}
			if(c == 2){
				int a = -1, b = -1;
				FOR(i, n){
					if(p[i] != 0)
						if(a == -1)
							a = i;
						else
							b = i;
				}
				assert(p[a] == p[b]);
				FOR(j, p[a]){
					ki << " " << party(a) << party(b);
				}
				break;
			} else if(c > 2) {
				ki << " " << party(mh);
				p[mh]--;
			} else {
				assert(false);
			}
		}
		ki << endl;


		//ki<<"Case #"<<tt+1<<": "<< <<endl;
	}

	ki.close();
	return 0;
}