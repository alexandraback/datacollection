#include <algorithm>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 1000000000
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


typedef std::pair<long long, int> plli;


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int T, N, B, M[111111];
  
  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    std::cin >> B >> N;

    for (int i = 0; i < B; i ++)
      std::cin >> M[i];

    int barber = -1;

    if (N <= B) {
      barber = N - 1;
    }
    else {
      long long l = -1, u = 1LL << 62;

      while (u - l > 1) {
        long long m = (l + u) / 2;

        long long c = 0;

        for (int i = 0; i < B; i ++)
          c += m / M[i] + 1;

        if (c < N) {
          l = m;
        }
        else {
          u = m;
        }
      }

      assert(u);

      long long c = 0;
      
      for (int i = 0; i < B; i ++)
        c += (u - 1) / M[i] + 1;

      assert(c < N);

      N -= c;

      std::vector<int> indices;

      for (int i = 0; i < B; i ++)
        if (u % M[i] == 0)
          indices.push_back(i);

      if ((N - 1 < indices.size()))
        assert(N - 1 < indices.size());

      barber = indices[N - 1];
    }

    std::cout << "Case #" << t << ": " << barber + 1 << std::endl;
  }
  
  return 0;
}
