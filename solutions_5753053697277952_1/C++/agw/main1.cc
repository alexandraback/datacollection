#include <algorithm>
#include <cassert>
#include <cstdio>
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


#define INF 1000000002486618624LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int T, N;

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    std::cin >> N;

    std::vector<int> P(N);

    int C = 0;

    std::priority_queue<std::pair<int, char>> pq;

    for (int i = 0; i < N; i ++) {
      std::cin >> P[i];

      pq.emplace(P[i], 'A' + i);

      C += P[i];
    }

    std::string s;

    while (! pq.empty()) {
      auto x = pq.top();

      pq.pop();

      s.push_back(x.second);

#if 0
      std::cerr << "  " << x.second << ' ' << x.first << std::endl;
#endif

      if (x.first - 1)
        pq.emplace(x.first - 1, x.second);
    }

    assert(s.size() == C);

#if 1
    std::vector<int> PP(P);
#endif

    std::vector<std::string> a;

    bool consecutive = false;

    for (int i = 0, size = s.size(); i < size; ) {
      char c = s[i];
      
      int j = c - 'A';

      assert(P[j] > 0);

      P[j] --;

      C --;

      for (int i = 0; i < N; i ++)
        if (P[i] > C / 2) {
          consecutive = true;
          
          break;
        }
      
      if (consecutive) {
        char cc = s[i + 1];

        a.emplace_back(1, c);
        
        a.back().push_back(cc);

        i += 2;
      }
      else {
        a.emplace_back(1, c);

        i ++;
      }
    }

    std::cout << "Case #" << t << ':';

    for (const auto& s : a)
      std::cout << ' ' << s;

    std::cout << std::endl;

#if 1
    P = PP;
    
    C = std::accumulate(ALL(P), 0);
    
    for (const auto& s : a) {
      for (const auto& c : s) {
        int i = c - 'A';

        assert(P[i] > 0);

        P[i] --;

        C --;
      }

      for (int i = 0; i < N; i ++)
        assert(P[i] <= C / 2);
    }
#endif
  }
  
  return 0;
}
