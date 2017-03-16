/* CodeJam solution Repeater in C++ by domob.  */

//#define NDEBUG

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <deque>
#include <iostream>
#include <algorithm>
#include <stdint.h>

typedef std::deque<char> mystr;

/* Get number of repeats of the first character.  */
unsigned
getFirstCount (mystr& str)
{
  assert (!str.empty ());
  const char c = str.front ();
  unsigned res = 0;
  while (!str.empty () && str.front () == c)
    {
      ++res;
      str.pop_front ();
    }

  return res;
}

/* Solve a single case.  */
void
solve_case ()
{
  unsigned n;
  std::cin >> n;

  std::vector<mystr> strs;
  strs.reserve (n);
  for (unsigned i = 0; i < n; ++i)
    {
      std::string str;
      std::cin >> str;

      mystr mstr(str.begin (), str.end ());
      strs.push_back (mstr);
    }
  assert (strs.size () == n);

  int moves = 0;
  while (true)
    {
      bool allEmpty = true;
      bool foundEmpty = false;
      for (const auto& str : strs)
        {
          if (str.empty ())
            foundEmpty = true;
          else
            allEmpty = false;
        }
      if (allEmpty)
        break;
      if (foundEmpty)
        {
          std::cout << "Fegla Won";
          return;
        }

      const char c = strs.front ().front ();
      for (const auto& str : strs)
        if (str.front () != c)
          {
            std::cout << "Fegla Won";
            return;
          }

      unsigned minCnt = 100000;
      unsigned maxCnt = 0;
      for (auto& str : strs)
        {
          const unsigned cur = getFirstCount (str);
          minCnt = std::min (cur, minCnt);
          maxCnt = std::max (cur, maxCnt);
        }

      assert (minCnt > 0);
      assert (maxCnt >= minCnt);
      moves += maxCnt - minCnt;
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
