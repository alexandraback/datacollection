//
//  main.cpp
//  codex
//
//  Created by MarekCerny.com.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <cstdlib>
#include <unordered_set>

using namespace std;
#define X first
#define Y second
#define EX(x) do{cout<<(x)<<endl;return 0;}while(0)
#define SW(a,b) do{auto ___t=a;a=b;b=___t;}while(0)
//#define endl "\n"
#define SZ(v) (int(v.size()))
#define ALL(v) v.begin(),v.end()
#define IN(arr,x) (unsigned)(&x-&arr[0])
#define AT(arr,x) (unsigned)(x-&arr[0])

#define FOR(i,n) for(int i=0;i<int(n);++i)
#define ROF(i,n) for(int i=int(n)-1;i>=0;--i)
#define RAN(i,b,e) for(int i=b;i<=int(e);++i)
#define NAR(i,b,e) for (int i=e;i>=int(b);--i)

#define ASSERT(i,c) do{if(!(c))exit(i);}while(0)
//#include <cassert>
//#define ASSERT(i,c) assert(c)

#define $(a,op,b) \
([](typeof(a) &_a, typeof(b) &_b) {\
if (!(_b op _a)) return false; \
_a = _b;\
return true;\
})(a,b)

typedef __uint128_t lll;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;

//#ifdef DEBUG
std::ifstream __fin("A-large.in.txt");
//std::ifstream __fin("in.txt");
std::ofstream __fout("out.txt");
#define cin __fin
#define cout __fout
//#endif

vector<int> pa; int n; int sum;

int find_max() {
	int st=INT_MIN, nd=INT_MIN;
	
	for (int p: pa) {
		if (p > st) {
			nd = st;
			st = p;
		}
		if (st > p && p > nd) {
			nd = p;
		}
 	}
	
	//cout << ":" << st << " " << nd << endl;
	
	return nd;
}

bool is_major() {
	sum = 0;
	FOR (i, n) {
		sum += pa[i];
	}
	
	FOR (i, n) {
		if (2*pa[i]>sum) {
			return false;
		}
	}
	return true;
}


int test_main() {
	cin >> n;
	pa = vector<int>(n);

	FOR (i,n) {
		cin >> pa[i];
	}
	
	int nd;
	while ((nd = find_max()) > INT_MIN) {
		
		bool nop = true;
		do {
			nop = true;
			FOR (i,n) if (pa[i] > nd) {
				cout << char(i+'A') << " ";
				pa[i]--;
				nop = false;
			}
			//is_major();
		} while (nop == false);
		//is_major();
	}
	
	RAN (i, 2, n-1) {
		while (pa[i] > 0) {
			cout << char(i+'A') << " ";
			pa[i]--;
			//is_major();
		}
	}
	
	while (pa[0] > 0) {
		cout << char(0+'A') << char(1+'A') <<  " ";
		pa[0]--; pa[1]--;
		//is_major();
	}

	//cout << find_max();
	cout << endl;
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	int t; cin >> t; RAN (i,1,t) {
		cout << "Case #" << i << ": ";
		test_main();
	}
	return 0;
}












































