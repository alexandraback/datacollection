#include <cstdio>
#include <algorithm>
#include <vector>

#define MAXN 30
#define X first
#define Y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair< int, int > pii;

pii A[ MAXN + 1 ];

int N;

char geti( int i ) {
  return ( char )( 'A' + i - 1 );
}

int main( void ) {
  int T;
  freopen("Asmall.in","rt",stdin);
freopen("Asmall.out","wt",stdout);
scanf("%d", &T );
  for( int t = 1; t <= T; t++ ) {
    scanf("%d", &N );
    for( int i = 1; i <= N; i++ ) {
      scanf("%d", &A[ i ].X );
      A[ i ].Y = i;
    }
    sort( A + 1, A + N + 1 );
    printf("Case #%d:", t );
    while( A[ N ].X > A[ N - 1 ].X ) {
      printf(" %c", geti( A[ N ].Y ) );
      A[ N ].X--;
    }
    for( int i = 1; i <= N - 2; i++ ) {
      while( A[ i ].X > 1 ) {
        printf(" %c%c", geti( A[ i ].Y ), geti( A[ i ].Y ) );
        A[ i ].X -= 2;
      }
      if( A[ i ].X == 1 ) {
        printf(" %c", geti( A[ i ].Y ) );
        A[ i ].X--;
      }
    }
    while( A[ N - 1 ].X > 0 ) {
      printf(" %c%c", geti( A[ N - 1 ].Y ), geti( A[ N ].Y ) );
      A[ N ].X--;
      A[ N - 1 ].X--;
    }
    printf("\n");
  }
  return 0;
}
