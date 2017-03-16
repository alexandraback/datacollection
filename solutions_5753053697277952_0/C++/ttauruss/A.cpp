
#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include <algorithm>
using namespace std;

string solve(vector<int> V)
{
  string res;
  int N = V.size();
  while (true)
  {
    auto me = max_element(V.begin(), V.end());
    if (*me == 0) return res;
    (*me)--;
    if (not res.empty()) res += " ";
    res += ('A' + (me - V.begin()));
    auto total = accumulate(V.begin(), V.end(), 0);
    auto max_elem = *max_element(V.begin(), V.end());
    if (max_elem > total / 2)
    {
      for (int i = 0; i < N; i++)
      {
        if (V[i] == max_elem)
        {
          V[i]--;
          res += ('A' + (char)i);
          break;
        }
      }
    }
  }
  return res;
}

void run(istream& in, ostream& out)
{
  int T; in >> T;
  for (int t = 1; t <= T; t++)
  {
    int N; in >> N;
    vector<int> V(N);
    for (int i = 0; i < N; i++) in >> V[i];
    auto res = solve(V);
    out << "Case #" << t << ": " << res << endl;
  }
}

int main()
{
  ifstream fin("A-small.in");
  ofstream fout("A-small.out");
  run(fin, fout);
}

