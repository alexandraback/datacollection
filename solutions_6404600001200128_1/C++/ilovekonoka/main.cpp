#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

int T;
int N;
vector<int> m;

//string input = "A-sample";
//string input = "A-small-attempt4";
string input = "A-large";

int main()
{
  ifstream fin(input + ".in");
  ofstream fout(input + ".out");
  fin >> T;
  for (auto t = 1; t <= T; ++t)
  {
    fin >> N;
    m.resize(N);
    for (int i = 0; i < N; ++i)
    {
      fin >> m[i];
    }

    int s0 = 0;
    int s1 = 0;
    double rate = 0;
    double maxDiff = 0;
    for (int i = 0; i < N - 1; ++i)
    {
      if (m[i] > m[i + 1]) // eat
      {
        int diff = m[i] - m[i + 1];
        s0 += diff;
        if (diff > maxDiff) maxDiff = diff;
      }
    }
    rate = maxDiff / 10;
    for (int i = 0; i < N - 1; ++i)
    {
        if (m[i] > rate * 10)
          s1 += rate * 10;
        else
          s1 += m[i];
    }
    /*if (m[N - 2] >= m[N - 1])
    {
      int diff = (m[N - 2] - m[N - 1]);
      if (diff > rate * 10)
        s1 += rate * 10;
      else
        s1 += diff;
    }
    else
    {
      if (m[N - 2] > rate * 10)
        s1 += rate * 10;
      else
        s1 += m[N - 2];
    }*/
    fout << "Case #" << t << ": " << s0 << " " << s1 << endl;
  }
}