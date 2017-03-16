#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

__int64 GetCount(vector<int> &v, __int64 t)
{
  __int64 sum = 0;

  for(int i=0; i<v.size(); i++)
  {
    sum += t/v[i];
    if(t%v[i] != 0)
      sum++;
  }

  return sum;
}

int Simulate(vector<int> &v, int N)
{
  int cur = 0;
  __int64 t = 0;
  while(cur < N)
  {
    for(int i=0; i<v.size(); i++)
      if(t%v[i] == 0)
      {
        cur++;
        if(cur == N)
          return i+1;
      }
    t++;
  }
}

int main()
{
  int T;

  //ifstream in("test.in");
  //ofstream out("test.out");

  ifstream in("B-small-attempt1.in");
  ofstream out("B-small-attempt1.out");

  //ifstream in("B-large.in");
  //ofstream out("B-large.out");

  in >> T;

  for(int i=0; i<T; ++i)
  {
    int solve = 0; 
    int B, N;

    in >> B >> N;

    vector<int> v(B);

    for(int j=0; j<B; j++)
      in >> v[j];

    if(N <= B)
      solve = N;
    else
    {
      __int64 t = 1;

      while(GetCount(v,t) < N)
        t*=2;

      __int64 p = t/2;
      __int64 count;

      while(p != t-1)
      {
        __int64 m = (p+t)/2;

        count = GetCount(v,m);

        if(count < N)
          p=m;
        else
          t=m;
      }

      t--;

      count = GetCount(v,t);

      for(int j=0; j<v.size(); j++)
        if(t%v[j] == 0)
        {
          count++;
          if(count == N)
          {
            solve = j+1;
            break;
          }
        }
    }

    //int x = Simulate(v,N);

    out << "Case #"<<i+1<<": ";

    out << solve << endl;
  }

  return 0;
}