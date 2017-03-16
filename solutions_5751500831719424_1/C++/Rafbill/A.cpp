#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#include <set>

using namespace std;

#define FOR(i, n) for(long i = 0; i < (n); ++i)
#define FORU(i, j, k) for(long i = j; i <= (k); ++i)
#define FORD(i, j, k) for(long i = j; i >= (k); --i)

enum class SolutionE {
  YES, NO
};

struct Solution {
  static Solution OK(long i){
    return Solution {SolutionE::YES, i};
  }
  static Solution NO(){
    return Solution {SolutionE::NO, 0};
  }
  SolutionE p;
  long i;
};

ostream& operator<<(ostream& str, Solution const& s){
  switch(s.p){
    case SolutionE::YES: str << s.i; break;
    case SolutionE::NO: str << "Fegla Won"; break;
  }
  return str;
}


Solution solve(){
  long n; cin >> n;
  long AAA[100]; FOR(i, 100) AAA[i] = i;
  string A[100]; FOR(i, n) cin >> A[i];
  long I[100]; FOR(i, n) I[i] = 0;
  long J[100]; FOR(i, n) J[i] = 0;
  char C[100]; FOR(i, n) C[i] = A[i][0];
  auto f = [&]()->bool{return all_of(C, C+n, [&](long const& i)->bool{return i == C[0];});};
  if(!f()){ return Solution::NO(); }
  long r = 0;
  while(all_of(AAA, AAA+n, [&](long i)->bool{return I[i] != A[i].size();})){
    FOR(i, n){
      J[i] = 0;
      C[i] = A[i][I[i]];
      while(I[i] < A[i].size() && C[i] == A[i][I[i]]){
        I[i] += 1;
        J[i] += 1;
      }
    }
    if(!f()){ return Solution::NO(); }
    sort(J, J+n);
    long m = accumulate(J, J + n, 0) - n*J[0];
    long rm = m;
    FORU(i, 1, n-1){
      m += (n-2*i)*(J[i-1]-J[i]);
      rm = min(rm, m);
    }
    r += rm;
  }
  if(all_of(AAA, AAA+n, [&](long const& i){return I[i] == A[i].size();})){
    return Solution::OK(r);
  }else{
    return Solution::NO();
  }
}

int main(int, char**){
  long n_test; cin >> n_test;
  FOR(t, n_test){
    cout << "Case #" << t+1 << ": " << solve() << "\n";
  }
  return 0;
}