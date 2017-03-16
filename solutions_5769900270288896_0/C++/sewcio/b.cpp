#include<bits/stdc++.h>
using namespace std;
#define FWD(i, a, b) for(int i = (a); i < (b); i++)
typedef pair<int, int> PII;
#define st first
#define nd second

int revi(int x){
  string s = to_string(x);
  string r = string(s.rbegin(), s.rend());
  return stoi(r);
}

int test(int R, int C, int i, int j, int X){
  return (X >> (C*i + j)) & 1;
}

int unhappiness(int R, int C, int X){
  int cnt = 0;
  FWD(i, 0, R)
    FWD(j, 0, C){
    if(i+1 < R && test(R, C, i, j, X) && test(R, C, i+1, j, X)) cnt++;
    if(j+1 < C && test(R, C, i, j, X) && test(R, C, i, j+1, X)) cnt++;

    }
  return cnt;
}
int main(){
  int T;
  ios_base::sync_with_stdio(0);
  cin >> T;
  FWD(t, 1, T+1){
    int R, C, N;
    cin >> R >> C >> N;
    int res = 4*R*C;
    FWD(X, 0, 1<<(R*C))
      if(__builtin_popcount(X) == N)
        res = min(res, unhappiness(R, C, X));
    cout << "Case #" << t << ": " << res << endl;
  }

}
