#include <iostream>
#include <algorithm>
using namespace std;
int bitcount( int N ){
  int ret = 0;
  while( N > 0 ){
    ret += N&1;
    N >>= 1;
  }
  return ret;
}
int main( void )
{
  int T;
  cin >> T;
  for( int ti=1; ti<=T; ti++ ){
    int R,C,N;
    cin >> R >> C >> N;
    int ret = 114514;
    for( int i=0; i<(1<<(R*C)); i++ ){
      if( bitcount(i) != N ) continue;
      int c = 0;
      for( int j=0; j<R; j++ ){
        for( int k=0; k<C-1; k++ ){
          int a = (i >> (j*C+k)) & 1;
          int b = (i >> (j*C+k+1)) & 1;
          if( a && b ){
            c++;
          }
        }
      }
      for( int j=0; j<R-1; j++ ){
        for( int k=0; k<C; k++ ){
          int a = (i >> (j*C+k)) & 1;
          int b = (i >> ((j+1)*C+k)) & 1;
          if( a && b ){
            c++;
          }
        }
      }
      ret = min( ret, c );
    }
    cout << "Case #" << ti << ": " << ret << endl;
  }
}
