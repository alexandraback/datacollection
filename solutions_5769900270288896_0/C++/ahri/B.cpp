/*
ID: ahri1
PROG: A
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define sz(X) ((int)(X).size())
#define foreach(i,c) for(__typeof((c).begin()) i=((c).begin());i!=(c).end();++i)
#define EXISTS(x, s) ( (s).find((x)) != (s).end() ) 
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
template<typename T> string v_2_s(vector<T> &a) { stringstream sb; __typeof(a.begin()) i = a.begin(); if (i!=a.end()) { sb << *i; ++i; } for (; i!=a.end();++i) { sb << " " << *i; } return sb.str(); }


template<typename T, typename U> inline void relaxmin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}
template<typename T, typename U> inline void relaxmax(T &res, const U &x) {
  if (x > res) {
    res = x;
  }
}


template<typename T>
T binomial(int x, int y) { if (2*y>x) y=x-y; T a=1, b=1, c; int i; for (i=0;i<y;i++) { a=a*(x-i); b=b*(1+i); c=gcd(a,b); a=a/c; b=b/c; } return (a/b);}

void binomialCombinationsBinaryWork(vector<vector<int> > &result, vector<int> &tempState, int totalNumber, int current, int index) {
  if (index==(int)tempState.size()) {
    vector<int> temp(totalNumber);
    for (unsigned i=0;i<tempState.size();i++)
      temp[tempState[i]]=1;
    result.push_back(temp);
  } else {
    int n = totalNumber-(int)tempState.size()+index+1;
    for (int i = current; i < n; i++) {
      tempState[index]=i;
      binomialCombinationsBinaryWork(result, tempState, totalNumber, i+1, index+1);
    }
  }
}
// generates all binomial combinations (a // b), representing them as binary (1 = "on", 0 = "off")
vector<vector<int> > bin_comb_all_bin(int a, int b){ // zero indexed
  vector<vector<int> > result;
  vector<int> tempState(b);
  binomialCombinationsBinaryWork(result, tempState, a, 0, 0);
  return result;
}

vector<pair<int, int> > create_walls(int R, int C) {
	vector<pair<int, int> > ret;
	for (int i = 0; i < R; ++i) {
		for(int j = 0; j < C; ++j) {
			if (j < C - 1) ret.push_back(make_pair(i * C + j, i * C + j + 1));
			if (i < R - 1) ret.push_back(make_pair(i * C + j, (i + 1) * C + j));
		}
	}
	return ret;	
}

int brute_force(int R, int C, int N) {
	vector<pair<int, int> > walls = create_walls(R, C);
	int M = sz(walls);
	// cerr << M << endl;
	
	vector<vector<int> > combs = bin_comb_all_bin(R*C, N);
	
	int K = sz(combs);
	
	int ret = M;
	
	// cerr << K << endl;

	// cerr << "!!!" << endl;
	
	// for (int i = 0; i < M; ++i) {
		// cerr << walls[i].first << " " << walls[i].second << endl;
	// }


	for(int i=0;i<K;++i){
		int count = 0;
		for(int j=0;j<M;++j){
			if (combs[i][walls[j].first] && combs[i][walls[j].second]) {
				count++;
			}
		}
		relaxmin(ret, count);
	}
	
	return ret;
}

void solve(){
	int R, C, N;
	cin >> R >> C >> N;
	cout << brute_force(R, C, N) << endl;
}

int main() {

  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}
