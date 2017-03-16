#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <string>
#include <fstream>
#define REP(k,a) for(int k=0; k < (a); ++k)
#define REPP(k,a,b) for(int k= (a); k < (b); ++k)
#define INF 200000000
#define mp make_pair
#define len(s) (int)((s).size())
#define pb push_back
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef unsigned int uint;
using vi = vector<int>;
using vii = vector<vector<int>>;
using pii = pair<int,int>;
template <class T>
void print(vector<T> v){ bool first=true; for(T x : v) { if(!first) cout << " "; first = false; cout << x; } cout << endl;}

  vi sel(ll n){
    vi ans;
    int p=0;
    while(n > 0){
      if(n & 1){
        ans.pb(p);
      }
      p++;
      n/=2;
    }
    return ans;
  }
  
int main(){
  int T;
  ifstream fin("b.in");
  ofstream fout("b.out");
  fin >> T;
  REP(t, T){
    int R, C, N;
    fin >> R >> C >> N;
    int up = R*C;
    int ans=INF;
    vector<pair<int,int>> neigh;
    REP(i, R){
      REP(j, C){
        if(j+1 < C)
          neigh.pb(mp(i*C+j, i*C+j+1));
        if(i+1 < R)
          neigh.pb(mp(i*C+j, i*C+j+C));
      }
    }
    for(ll i=0; i < pow(2, up); i++){
      vi s=sel(i);
      if(len(s) == N){
          int u=0;
          for(auto n : neigh){
            if(find(all(s), n.first) != s.end() && find(all(s), n.second) != s.end()){
              u++;
            }
          }
          ans = min(ans, u);
      }
    }
    fout << "Case #" << (t+1) << ": " << ans << endl;
  }
	return 0;
}
