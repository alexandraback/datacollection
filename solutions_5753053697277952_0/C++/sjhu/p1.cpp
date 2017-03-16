#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
 
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
 
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long
#define SZ size()
#define read(filename) freopen(filename, "r", stdin)
#define write(filename) freopen(filename, "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define INF 1<<29
#define mod(a) (a>0?a:-a)
#define pf printf
 
using namespace std;
 
char intToChar(int x) {
	return 'A' + x;
}

int main()
{
    int T;
    getint(T); 

 	int list[26];
 	int N;
 	int buff;
 	int sum;
    loop(i, T) {
    	sum = 0;
    	getint(N);
    	loop(j, N) {
    		getint(buff);
    		list[j] = buff;
    		sum += buff;
    	}

    	string r = "";
    	string rbuff = "xx ";
    	int m1, m2;
    	int i1, i2;
    	while (sum > 0) {
    		m1 = -9999;
    		m2 = -9999;

    		loop(x, N) {
    			if (list[x] > m1) {
    				m1 = list[x];
    				i1 = x;
    			}
    		}

    		list[i1]--;
    		sum--;

    		if (sum > 0) {
	    		loop(x, N) {
	    			if (list[x] > m2) {
	    				m2 = list[x];
	    				i2 = x;
	    			}
	    		}

	    		list[i2]--;
	    		sum--;

	    		rbuff[0] = intToChar(i1);
	    		rbuff[1] = intToChar(i2);
	    		r += rbuff;
    		} else {
    			char tmp = r[r.size() - 2];
    			r[r.size() - 2] = ' ';
    			r[r.size() - 1] = tmp;

    			rbuff[0] = intToChar(i1);
    			rbuff[1] = '\0';
    			r += rbuff;
    		}
    	}

    	cout << "Case #" << i+1 << ": " + r << endl;
    	// pf("Case #%d: %s\n", i+1, r);
    }
    return 0;
}