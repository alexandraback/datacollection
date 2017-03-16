#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <numeric>

using namespace std;

typedef ptrdiff_t ist;
typedef size_t iut;
typedef vector<ist> vi;
typedef pair<ist, ist> pii;

bool trailing_space = true; // for output

struct Solver
{
   ist N;
   vi counts;
   ist ans;
   ist ans2;

   void read_input()
   {
      cin >> N;
      counts.resize(N);

      for (auto & c : counts) cin >> c;
   }

   void solve()
   {
      ans = 0;
      ans2 = 0;

      ist s = 0;

      for (ist i = 1; i < N; ++i)
      {
         if (counts[i] < counts[i - 1])
         {
            ans += counts[i - 1] - counts[i];

            s = std::max(s, counts[i - 1] - counts[i]);
         }
      }

      for (ist i = 0; i < N - 1; ++i)
      {
         ans2 += std::min(counts[i], s);
      }
   }

   void print_output()
   {
      cout << ans << ' ' << ans2;
   }

   void execute()
   {
      read_input();
      chrono::time_point<chrono::high_resolution_clock> start = chrono::high_resolution_clock::now();
      solve();
      chrono::time_point<chrono::high_resolution_clock> finish = chrono::high_resolution_clock::now();
      cerr << "PERF: size: " << N << " time: " << chrono::duration_cast<chrono::microseconds>(finish - start).count() << " us\n";
      print_output();
   }
};


int main()
{
   int T = 0;
   cin >> T;
   for (int i = 0; i < T; ++ i)
   {
      cerr << "Solving Case #" << i + 1 << '\n';
      cout << "Case #" << i + 1 << ':';
      if (trailing_space) cout << ' ';
      Solver s;
      s.execute();
      cout << '\n';
   }

   return 0;
}

