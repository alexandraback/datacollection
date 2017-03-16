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

LL freebarb[1005];

LL gcd(LL a, LL b){
  if(a<b) return gcd(b,a);
  if(b==0) return a;
  return gcd(b,a%b);
}

LL lcm(LL a, LL b){
  return a*b / gcd(a,b);
}

int main(){
  int TC;cin>>TC;
  FOR(tc,TC){
    int B;
    LL N; cin>>B>>N;
    vector<int> barbers;
    FOR(i,B){
      int t;cin>>t;
      barbers.pb(t);
    }
    FOR(i,B) freebarb[i] = 0;

    // find lcm
    LL cyclelen = 1;
    FOR(i,B) cyclelen = lcm(cyclelen, barbers[i]);

    int percycle = 0;
    FOR(i,B) percycle += cyclelen / barbers[i];

    N = N % percycle;
    if(N == 0){
      N = percycle;
    }

    int ans = 0;
    LL time = 0;
    int served = 0;
    int wake = 0;

    while(true){
      // look for first free barber
      int barbnum = -1;
      FOR(i,B){
        if(freebarb[i] <= time){
          barbnum = i;
          break;
        }
      }

      if(barbnum == -1){
        cout << "catastrophe" << endl;
        FOR(i,B){
          cout << freebarb[i] << endl;
        }
        break;
      }
      if(served == N-1){
        ans = barbnum+1;
        break;
      }
      freebarb[barbnum] = time + barbers[barbnum];
      LL wake = 150000000000000LL;
      FOR(i,B){
        wake = MIN(wake,freebarb[i]);
      }
      time = wake;
      served++;
    }
    fin:
    cout << "Case #" << tc+1 << ": " << ans << endl;
  }
}


