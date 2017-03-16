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
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define sz(X) ((int)(X).size())
#define foreach(i,c) for(__typeof((c).begin()) i=((c).begin());i!=(c).end();++i)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }

string FAIL = "Fegla Won";

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

void analyze(string s, string &com, vector<int> &counts) {
  com="";
  int count = 1;
  for(int i=1;i<=sz(s);++i){
    if (i<sz(s) && s[i]==s[i-1]) { 
      count++;
    } else {
      com+=s[i-1];
      counts.push_back(count);
      count=1;
    }    
  }  
}


void solve(){
  int N;
  cin >> N;
  vector<string> A(N);
  for(int i=0;i<N;++i){
    cin >> A[i];
  }
  vector<int> pos(N, 0);  
  vector<vector<int> >counts(N);
  string com;
  string ret_com;
  analyze(A[0], com, counts[0]); 
  for(int i=1;i<N;++i){
    analyze(A[i], ret_com, counts[i]);    
    // cout << ret_com << endl;
    if (ret_com!=com) {
      cout << FAIL << endl;
      return;
    }
  }
  int ret=0;
  // for(int i=0;i<N;++i){
    // cout << sz(counts[i]) << endl;
  // }
  // cout << "---" << endl;
  for(int j=0;j<sz(com);++j){
    int min_v=counts[0][j];
    int max_v=counts[0][j];
    for(int i=1;i<N;++i){
      relaxmin(min_v, counts[i][j]);
      relaxmax(max_v, counts[i][j]);
    }
    ret+=max_v-min_v;
  }
  
  cout << ret << endl;
  
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
