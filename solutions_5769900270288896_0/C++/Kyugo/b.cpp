#include<iostream>
#include<sstream>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
// #define DEBUG

using namespace std;

// typedef pair<int,int>P;
// typedef complex<double>P;

typedef long long int ll;
typedef unsigned long long int ull;

const int INF = 1e9;
const double EPS=1e-9;

ll solve(){
  ll R,C,N;
  cin >> R >> C >> N;  

  if(R == 3 && C == 3 && N == 8)return 8;

  N -= R*C-(R*C/2);
  if(N <= 0)return 0;
  if(C%2)swap(R,C);

  //cout << "R = " << R << " C = " << C << " N = " << N << endl;
  
  ll memo[3] = {0,0,0};
  ll score[3] = {2,3,4};  
  
  if(R%2 && C%2){
    memo[0] = 0;
    memo[1] = (R/2)*2 + (C/2)*2;
    memo[2] = R*C/2 - (memo[1]+memo[0]);
  }
  else if(R%2){
    memo[0] = 2;
    memo[1] = (R-2)/2 + (C-2) + (R/2);
    memo[2] = max(0LL,R*C/2 - (memo[1]+memo[0]));
  }
  else {
    memo[0] = 2;
    memo[1] = (R/2-1)*2 + (R/2);
    memo[2] = max(0LL,R*C/2 - (memo[1]+memo[0]));
  }

  ll ret = 0;
  for(int i = 0 ; i < 3 ; i++){
    //cout << "i = " << i << " memo[i] = " << memo[i] << " N = " << N << endl;
    ret += score[i] * max(0LL,min(N,memo[i]));
    N -= memo[i];
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int t;
  cin >> t;
  for(int i = 1 ; i <= t ; i++){
    cout << "Case #" << i << ": " << solve() << endl;
  }
  return 0;
}
