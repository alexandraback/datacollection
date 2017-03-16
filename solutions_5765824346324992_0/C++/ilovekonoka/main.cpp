#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

int T;
int B, N;
vector<int> M;
vector<int> Morig;
vector<int> V;

//string input = "B-sample";
string input = "B-small-attempt6";
//string input = "A-large";

int main()
{
  ifstream fin(input + ".in");
  ofstream fout(input + ".out");
  fin >> T;
  for (auto t = 1; t <= T; ++t)
  {
    fin >> B >> N;
    M.resize(B);
    V.resize(B);
    for (int i = 0; i < B; ++i)
    {
      fin >> M[i];
    }
    Morig = M;
    int result = -1;
    if (N <= B)
    {
      result = N;
    }
    else // N > B
    {
      int product = 1;
      // all the barbers start out full
      int minM = M[0]; // fastest barber
      int maxM =  M[0];
      int sofar = B;
      for (int i = 0; i < B; ++i)
      {
        product *= M[i];
      }
      int sum = 0;
      for (int i = 0; i < B; ++i)
      {
        V[i] = product / M[i];
        sum += V[i];
      }
      if (sum <= N)
      {
        sofar += (N / sum) * sum;
      }
      if (sofar > N)
        sofar -= sum;
      if (sofar > N)
         int a = 0;

      if (sofar < 0)
        sofar = B;

      if (sofar == N)
        result = B;

      for (int i = 0; i < B; ++i)
      {
        if (M[i] < minM) minM = M[i];
        if (M[i] > maxM) maxM = M[i];
      }
      while (sofar < N)
      {
        for (int i = 0; i < B; ++i)
        {
          M[i] -= minM;
        }
        for (int i = 0; i < B; ++i)
        {
          if (M[i] == 0)
          {
            M[i] = Morig[i];
            ++sofar;
            if (sofar == N)
            {
              result = i + 1;
              break;
            }
          }
        }
        minM = M[0];
        for (int i = 0; i < B; ++i)
        {
          if (M[i] < minM) minM = M[i];
        }
      }
    }
    fout << "Case #" << t << ": " << result << endl;
    cout << t << endl;
  }
}