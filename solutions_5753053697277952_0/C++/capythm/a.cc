#include <iostream>
#include <algorithm>
using namespace std;
int main( void )
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    int P[26];
    int sum = 0, N;
    cin >> N;
    for( int i=0; i<N; i++ ){
      cin >> P[i];
      sum += P[i];
    }
    cout << "Case #" << testcase << ":";
    while( sum > 0 ){
      int *p = max_element( P, P+N );
      int idx0 = p - P;
      P[idx0]--; sum--;
      p = max_element( P, P+N );
      int idx1 = p - P;
      bool f = false;
      if( P[idx1]*2 > sum ){
        f = true; P[idx1]--; sum--;
      }
      cout << ' ';
      cout << (char)('A' + idx0);
      if( f ) cout << (char)('A' + idx1);
    }
    cout << endl;
  }
}
