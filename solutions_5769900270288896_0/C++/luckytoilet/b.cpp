#include <bits/stdc++.h>
#define LL long long
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORIT(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
template<typename T> ostream& operator<<(ostream& s, vector<T>& v)
{ s << '{'; for (int i = 0 ; i < v.size(); ++i) s << (i ? "," : "") << v[i]; return s << '}'; }
template<typename S, typename T> ostream& operator<<(ostream &s, pair<S,T>& p)
{ return s << "(" << p.first << "," << p.second << ")"; }

int unhappiness(vector< vector<bool> > &bits, int W, int H){
  int unh = 0;
  FOR(w,W){
    FOR(h,H){
      // right
      if(w < W-1){
        if(bits[w][h] && bits[w+1][h]) unh++;
      }
      // down
      if(h < H-1){
        if(bits[w][h] && bits[w][h+1]) unh++;
      }
    }
  }
  return unh;
}

int main(){
  int TC;cin>>TC;
  FOR(tc,TC){
    int W,H,n; cin>>W>>H>>n;
    int ans = 1000000;
    for(int b=0; b<(1<<(W*H)); b++){
      if(__builtin_popcount(b) != n) continue;
      vector< vector<bool> > bf(W);
      FOR(w,W){
        bf[w].resize(H);
      }
      FOR(w,W){
        FOR(h,H){
          bf[w][h] = (b >> (w*H+h)) & 1;
        }
      }
      int cur = unhappiness(bf,W,H);
      ans = MIN(ans,cur);
    }
    cout<<"Case #" << tc+1 << ": " << ans<<endl;
  }
}

