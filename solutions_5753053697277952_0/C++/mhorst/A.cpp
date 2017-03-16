#include <iostream>
#include <vector>

using namespace std;

static int P[26];

void solve(int r)
{
  int N;
  int i;
  int total = 0;
  bool first = true;
  
  cin >> N;
  
  for (i = 0; i < N; i++) {
    cin >> P[i];
    total = total + P[i];
  }

  cout << "Case #" << r << ": ";
  
  // Print solution
  while (total > 0)
  {
    int maximum = 0;
    int max_nr = 0;

    if (first) first = false;
    else cout << " ";

    for (i = 0; i<N; i++) maximum = max(maximum, P[i]);
    for (i = 0; i<N; i++)
    {
      if (P[i] == maximum) max_nr++;
    }
    if (max_nr != 2)
    {
      /* Pick one */
      i=0;
      while (P[i] != maximum) i++;
      cout << char('A'+i);
      P[i]--;
      total--;
    } else
    {
      /* Pick largest two */
      i=0;
      while (P[i] != maximum) i++;
      cout << char('A'+i);
      P[i]--;
      total--;
      while (P[i] != maximum) i++;
      cout << char('A'+i);
      P[i]--;
      total--;
    }
  }  
  
  cout << "\n";
}

int main (void)
{
  int runs=0;
  int r = 1;

  cin >> runs;
  while (r <= runs)
  {
    solve(r);
    r++;
  }
  return 0;
}
