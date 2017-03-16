#include<bits/stdc++.h>
using namespace std;
int N,T;
int M[1111];
int main(){
  cin >> T;
  for(int ttt=1;ttt<=T;ttt++){
    cin >> N;
    for(int i=0;i<N;i++)
      cin >> M[i];

    int maxsa = 0;
    int res1 = 0,pr = M[0];
    for(int i=0;i<N-1;i++){
      maxsa = max( maxsa, M[i]-M[i+1] );
      if( M[i] < M[i+1] ){
	res1 += pr - M[i];
	pr = M[i+1];
      }
    }
    res1 += pr-M[N-1];
    int res2 = 0;
    for(int i=0;i<N-1;i++){
      res2 += min( maxsa, M[i] );
    }
    cout << "Case #" << ttt << ": " << res1 << " " <<res2 << endl;
  }
}
