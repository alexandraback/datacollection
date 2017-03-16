#include <limits>
#include <algorithm>
#include <iostream>


int unhappiness(unsigned app, int R, int C)
{
  int u = 0;
  for ( int r = 0; r < R; ++r )
    for ( int c = 0; c < C; ++c )
    {
      int idx = r*C + c;
      if ( app&(1U<<idx) )
      {
        if ( c + 1 < C && (app&(1U<<(idx + 1))) )
          ++u;
        if ( r + 1 < R && (app&(1U<<(idx + C))) )
          ++u;
      }
    }
  return u;
}


unsigned nextp(unsigned v)
{
  unsigned t = (v|(v - 1)) + 1;  
  return t|((((t&-t)/(v&-v))>>1)-1);
}


int happ(int R, int C, int N)
{
  if ( N > 0 )
  {
    unsigned s0 = (1U<<N) - 1;
    unsigned s1 = s0<<(R*C - N);
    int best = std::numeric_limits<int>::max();
    while ( s0 <= s1 )
    {
      best = std::min(best, unhappiness(s0, R, C));
      s0 = nextp(s0);
    }
    return best;
  }
  else
    return 0;
}


int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    int R, C, N;
    std::cin >> R >> C >> N;
    std::cout << "Case #" << t << ": " << happ(R, C, N) << '\n';
  }
  return 0;
}
