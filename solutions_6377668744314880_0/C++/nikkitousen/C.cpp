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

#define POINT pair<long long, long long>
#define X first
#define Y second
#define SQ(x) ((x)*(x))

#define INF 1000000000

POINT pointdiff(POINT p, POINT q) {
	POINT r;
	r.X = p.X-q.X;
	r.Y = p.Y-q.Y;
	return r;
}

long long dotprod(POINT p, POINT q) {
	return p.X*q.X + p.Y*q.Y;
}

long long crossprod(POINT p, POINT q) {
	return p.X*q.Y - p.Y*q.X;
}

long long qdist(POINT p, POINT q) {
	return SQ(p.X-q.X) + SQ(p.Y-q.Y);
}
    
int N;
POINT m[3010];
bool considered[3010];

vector<bool> convexHull(){
  int p = -1;
  vector<bool> used(N, false);
  REP(i, N) {
  	if(!considered[i]) continue;
  	if(p == -1) {
  		p = i;
  		continue;
  	}
    if(m[i].X < m[p].X || (m[i].X == m[p].X && m[i].Y < m[p].Y)) p = i;
  }
  
  int start = p;
  do{
    int n = -1;
    int dist = INF;
    REP(i, N) {
    	if(!considered[i]) continue;
      if(i==p) continue;
      if(used[i]) continue;

      if(n == -1) n = i;
      int cross = crossprod(pointdiff(m[i],m[p]), pointdiff(m[n], m[p]));
      int d = qdist(m[i], m[p]);
      if(cross < 0){
        n = i;
        dist = d;
      }else if(cross == 0){
        if(d < dist){
            dist = d;
            n = i;
        }
      }
    }
    p = n;
    used[p] = true;
  }while(start!=p);
  
  return used;
}






int main()
{
  int T;
  cin >> T;
  REP(caso, T) {
    cout << "Case #" << caso+1 << ": ";
    cout << endl;
    
    cin >> N;
    REP(i, N) cin >> m[i].X >> m[i].Y;
    
    REP(i, N) {
    	int best = N;
    	REP(mask, (1<<N)) {
    		if(best == 0) break;
    		int notused = 0;
    		REP(j, N) {
    			if(mask&(1<<j)) notused++, considered[j] = false;
    			else considered[j] = true;
    		}
    		if(best <= notused) continue;
    		
    		//check colinearity
    		int first = -1;
    		int second = -1;
    		bool isline = true;
    		REP(j, N) {
    			if(!considered[j]) continue;
    			if(first == -1) {
    				first = j;
    				continue;
    			}
    			if(second == -1) {
    				second = j;
    				continue;
    			}
    			
    			if(crossprod(pointdiff(m[second], m[first]), pointdiff(m[j], m[first])) != 0) {
    				isline = false;
    				break;
    			}
    		}
    		
    		if(isline) best = notused;
    		else {
	    		vector<bool> h = convexHull();
	    		if(h[i]) best = notused;
	    	}
    	}
    	// cout << "point " << m[i].X << ", " << m[i].Y << ": " << best << endl;
    	cout << best << endl;
    }
    
  }
}



