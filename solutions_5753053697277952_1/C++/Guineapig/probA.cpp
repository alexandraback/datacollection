
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <limits>
using namespace std;

// #pragma warning(disable: 4018)
// #include "../my_header.h"


struct solver
{
  string solve(int N, vector<int> &Ps)
  {
    int count = 0;
    for (int i=0 ; i < N ; i++)
      count += Ps[i];

    string res;
    while (count > 0)
    {
      int p1 = 0;
      int p2 = 0;
      int p1_idx = -1;
      int p2_idx = -1;
      for (int i=0 ; i < N ; i++)
      {
        int p = Ps[i];
        if (p > p2)
        {
          if (p > p1)
          {
            p2 = p1;
            p2_idx = p1_idx;
            p1 = p;
            p1_idx = i;
          }
          else
          {
            p2 = p;
            p2_idx = i;
          }
        }
      }
      assert(p1 > 0);
      assert(p2 > 0);
      assert(p1_idx != -1);
      assert(p2_idx != -1);

      if (res != "")
        res += " ";

      // Let's try to evacuate from the two major parties
      if (p1 > 1)
      {
        res += p1_idx + 'A';
        res += p2_idx + 'A';
        Ps[p1_idx]--;
        Ps[p2_idx]--;
        count -= 2;
      }
      else
      {
        assert(p1 == 1);
        assert(p2 == 1);
        if (count != 3)
        {
          res += p1_idx + 'A';
          res += p2_idx + 'A';
          Ps[p1_idx]--;
          Ps[p2_idx]--;
          count -= 2;
        }
        else
        {
          res += p1_idx + 'A';
          Ps[p1_idx]--;
          count--;
        }
      }
    }

    return res;
  }
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void process_test_case(int case_num)
{
  solver a_solver;

  int N;
  cin >> N;

  vector<int> Ps(N);
  for (int i=0 ; i < N ; i++)
    cin >> Ps[i];

  string res = a_solver.solve(N, Ps);

  cout << "Case #" << case_num << ": " << res << endl;
}

////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
  cout.precision(8);
  cout << fixed;

  int T;
  cin >> T;
  // assert(T > 0 && T < 200);

  for (int i=0 ; i < T ; i++)
  {
    // if (i > 0)
    //  cout << "\n---------------------------------------------\n\n";
    process_test_case(i+1);
  }

  return 0;
}
