/* CodeJam solution Repeater in C++ by domob.  */

//#define NDEBUG

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <deque>
#include <iostream>
#include <algorithm>
#include <stdint.h>

/* Solve a single case.  */
void
solve_case ()
{
  int n;
  std::cin >> n;

  /* Small dataset.  */
  assert (n == 2);

  std::string strAs, strBs;
  std::cin >> strAs >> strBs;

  std::deque<char> strA(strAs.begin (), strAs.end ());
  std::deque<char> strB(strBs.begin (), strBs.end ());

  int moves = 0;
  while (!strA.empty () || !strB.empty ())
    {
      if (strA.empty () || strB.empty ())
        {
          std::cout << "Fegla Won";
          return;
        }

      if (strA.front () != strB.front ())
        {
          std::cout << "Fegla Won";
          return;
        }

      const char c = strA.front ();
      int cntA = 0;
      while (!strA.empty () && strA.front () == c)
        {
          ++cntA;
          strA.pop_front ();
        }
      int cntB = 0;
      while (!strB.empty () && strB.front () == c)
        {
          ++cntB;
          strB.pop_front ();
        }

      assert (cntA > 0 && cntB > 0);
      moves += std::abs (cntA - cntB);
    }

  std::cout << moves;
}

/* Main routine, handling the different cases.  */
int
main ()
{
  int n;

  std::cin >> n;
  for (int i = 1; i <= n; ++i)
    {
      std::cout << "Case #" << i << ": ";
      solve_case ();
      std::cout << std::endl;
    }

  return EXIT_SUCCESS;
}
