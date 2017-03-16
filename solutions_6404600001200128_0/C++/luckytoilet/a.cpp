#include <bits/stdc++.h>
#define LL long long
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
#define FOR(i,n) for(int i=0;i<(n);++i)
#define pb push_back
using namespace std;
template<typename T> ostream& operator<<(ostream& s, vector<T>& v)
{ s << '{'; for (int i = 0 ; i < v.size(); ++i) s << (i ? "," : "") << v[i]; return s << '}'; }
template<typename S, typename T> ostream& operator<<(ostream &s, pair<S,T>& p)
{ return s << "(" << p.first << "," << p.second << ")"; }


int simulate1(vector<int> v){
  int tot = 0;
  FOR(i,v.size()-1){
    int a2 = v[i+1];
    int a1 = v[i];
    if(a2 < a1){
      tot += a1-a2;
    }
  }
  return tot;
}

int simulate2(vector<int> v){
  int eatspeed = 0;
  FOR(i,v.size()-1){
    int a2 = v[i+1];
    int a1 = v[i];
    if(a2 < a1){
      eatspeed = MAX(eatspeed, a1-a2);
    }
  }
  int tot = 0;
  int cur = v[0];
  for(int i=1; i<v.size(); i++){
    int ncur = cur - eatspeed;
    if(ncur < 0) ncur = 0;
    tot += cur - ncur;
    cur = v[i];
    //cur = ncur;
  }
  return tot;
}

int main(){
  int TC;cin>>TC;
  FOR(tc,TC){
    int N; cin>>N;
    vector<int> inp;
    FOR(i,N){
      int t;cin>>t;
      inp.pb(t);
    }
    int s1 = simulate1(inp);
    int s2 = simulate2(inp);
    cout << "Case #" << tc+1 << ": " << s1 << " " << s2 << endl;
  }
}

