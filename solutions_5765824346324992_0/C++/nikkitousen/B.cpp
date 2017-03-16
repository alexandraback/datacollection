#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define LL long long

long long N, B;
long long m[1010];

int main()
{
  int T;
  cin >> T;
  REP(caso, T) {
    cout << "Case #" << caso+1 << ": ";
    cin >> B >> N;
    
    LL max_m = 0;
    REP(i, B) {
    	cin >> m[i];
    	max_m = max(max_m, m[i]);
    }
    
    long long t = N*max_m*2;
    long long a = 0, b = t;
    long long x; 
    // cout << a << " " << b << endl;
    while(a < b) {
    	x = (a+b)/2;
    	long long clients = 0;
    	REP(i, B) {
    		clients += x/m[i];
    		if(x % m[i]) clients++;
    	}
    	
    	if(clients >= N) {
    		b = x;
    	} else {
    		a = x+1;
    	}
    	// cout << a << " " << b << endl;
    }
    x = --a;
    // cout << x << endl;
    
    long long clients2 = 0;
    REP(i, B) {
  		clients2 += x/m[i];
  		if(x % m[i]) clients2++;
  	}
    
    
    int res = 0;
    REP(i, B) {
    	// cout << x%m[i] << endl;
    	if(x % m[i] == 0) {
    		clients2++;
    		if(clients2 == N) {
	    		res = i+1;
	    		break;
	    	}
    	}
    }
    
    cout << res << endl;
    
    
     
  }
}
