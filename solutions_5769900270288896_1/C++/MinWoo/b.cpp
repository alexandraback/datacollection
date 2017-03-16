
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

int solve1(int R, int C, int N) {
  if ( R > C ) swap(R, C);

  const int sz = R * C;
  int res = INT_MAX;
  int best = -1;
  for ( int m=0 ; m<(1<<sz) ; ++m ) {
    if ( __builtin_popcount(m) != N ) continue;

    int board[R+1][C+1];
    memset(board, 0, sizeof(board));

    for ( int i=0 ; i<sz ; ++i ) {
      if ( m & (1<<i) ) {
        int r = i / C;
        int c = i % C;
        board[r][c] = 1;
      }
    }

    int share = 0;
    for ( int i=0 ; i<R ; ++i ) {
      for ( int j=0 ; j<C ; ++j ) {
        if ( board[i][j] ) {
          if ( board[i+1][j] ) ++share;
          if ( board[i][j+1] ) ++share;
        }
      }
    }
    if ( res > share ) {
      res = share;
      best = m;
    }
  }

  for ( int i=0 ; i<R ; ++i ) {
    for ( int j=0 ; j<C ; ++j ) {
      printf("%d ", (best & (1<<(i * C + j))) > 0 ? 1 : 0);
    }
    puts("");
  }
  return res;
}

int solve2(int R, int C, int N) {
  if ( R > C ) swap(R, C);

  const int sz = R * C;
  int res = INT_MAX;

  int board[R+1][C+1];
  memset(board, 0, sizeof(board));

  for ( int i=0 ; i<R ; ++i ) {
    for ( int j=0 ; j<C ; ++j ) {
      if ( i > 0 and board[i-1][j] ) continue;
      if ( j > 0 and board[i][j-1] ) continue;
      if ( N>0 ) {
        board[i][j] = 1;
        --N;        
      }
    }
  }

  priority_queue<tuple<int,int,int>> pq;
  for ( int i=0 ; i<R ; ++i ) {
    for ( int j=0 ; j<C ; ++j ) {
      if ( board[i][j] ) continue;
      int cnt = 0;
      if ( i>0 and board[i-1][j] ) ++cnt;
      if ( j>0 and board[i][j-1] ) ++cnt;
      if ( i+1<R and board[i+1][j] ) ++cnt;
      if ( j+1<C and board[i][j+1] ) ++cnt;
      pq.push(make_tuple(-cnt, i, j));
    }
  }

  while ( not pq.empty() and N>0) {
    auto curr = pq.top(); pq.pop();
    int r = get<1>(curr);
    int c = get<2>(curr);
    board[r][c] = 1;
    --N;
  }

  for ( int i=0 ; i<R ; ++i ) {
    for ( int j=0 ; j<C ; ++j ) {
      if ( not board[i][j] and N>0 ) {
        board[i][j] = 1;
        --N;
      }
    }
  }

  for ( int i=0 ; i<R-2 ; ++i ) {
    for ( int j=0 ; j<C-2 ; ++j ) {
      int cnt = 0;
      for ( int ii=0 ; ii<3 ; ++ii ) {
        for ( int jj=0 ; jj<3 ; ++jj ) {
          if ( board[i+ii][j+jj] ) ++cnt;
        }
      }
      if ( cnt == 8 ) {
        for ( int ii=0 ; ii<3 ; ++ii ) {
          for ( int jj=0 ; jj<3 ; ++jj ) {
            board[i+ii][j+jj] = 1;
          }
        }
        board[i+1][j+1] = 0;
      }
    }
  }

  int share = 0;
  for ( int i=0 ; i<R ; ++i ) {
    for ( int j=0 ; j<C ; ++j ) {
      if ( board[i][j] ) {
        if ( board[i+1][j] ) ++share;
        if ( board[i][j+1] ) ++share;
      }
      //printf("%d ", board[i][j]);
    }
    //puts("");
  }
  res = min(res, share);

  return res;
}

int main() {
  int TC;
  cin >> TC;
  for ( int tc=1 ; tc<=TC ; ++tc ) {
    int R, C, N;
    cin >> R >> C >> N;
    printf("Case #%d: %d\n", tc, solve2(R, C, N));
  }
}

