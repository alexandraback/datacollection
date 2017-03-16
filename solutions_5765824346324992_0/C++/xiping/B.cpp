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
   ist B, N;
   vi ms;
   ist ans;

   void read_input()
   {
      cin >> B >> N;
      ms.resize(B);
      for (auto & m : ms) cin >> m;
   }

   void find_answer(ist n, ist m)
   {
      for (ans = 0;ans < B; ++ans)
      {
         if (m % ms[ans] != 0)
         {
            ++n;
         }
      }

      for (ans = 0;ans < B; ++ans)
      {
         if (m % ms[ans] == 0)
         {
            ++n;
            if (n >= N)
            {
               ++ans;
               return;
            }
         }
      }
   }

   ist get_done(ist m2)
   {
      ist n = 0;
      for (auto & m : ms)
      {
         n += m2 / m;
      }
      return n;
   }

   void solve()
   {
      ist low = 0;
      ist hi = N * *std::min_element(ms.begin(), ms.end());
      ist dl = 0;
      ist dh = get_done(hi);

      while (dl + B < N)
      {
         ist mid = (low + hi) / 2;
         if (mid == low)
         {
            low = hi;
            dl = dh;
            break;
         }
         ist dm = get_done(mid);

         if (dm + B < N)
         {
            low = mid;
            dl = dm;
         }
         else
         {
            hi = mid;
            dh = dm;
         }
      }
      find_answer(dl, low);
   }

   void print_output()
   {
      cout << ans;
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

