#include <cassert>
#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main ()
{
  freopen ("in.txt", "rb", stdin);
  freopen ("out.txt", "wb", stdout);

  int T;
  scanf ("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    int N;
    int Psum = 0;
    vector< pair<int, char> > P;

    scanf ("%d", &N);
    for (int i = 0; i < N; i++) {
      int p;
      scanf ("%d", &p);

      P.push_back (make_pair (p, 'A' + i));
      Psum += p;
    }

    bool is_step_complete = false;

    printf ("Case #%d: ", t);

    while (P.size () != 0) {
      sort (P.rbegin (), P.rend ());

      printf ("%c", P[0].second);
      if (--P[0].first == 0) {
        P.erase (P.begin ());
      }
      --Psum;

      if (Psum == 2) {
        is_step_complete = true;
      }

      if (is_step_complete) {
        assert (P[0].first * 2 <= Psum);

        if (P.size () != 0) {
          printf (" ");
        }

        is_step_complete = false;
      } else {
        is_step_complete = true;
      }
    }

    printf ("\n");
  }

  fclose (stdin);
  fclose (stdout);

  return 0;
}
