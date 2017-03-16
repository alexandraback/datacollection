#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int count(vector<vector<int>> &m)
{
  int c = 0;
  int R=m.size();
  int C=m[0].size();
  for(int i=0; i<R-1; i++)
    for(int j=0; j<C-1; j++)
    {
      if(m[i][j] != 0 && m[i][j+1] != 0)
        c++;
      if(m[i][j] != 0 && m[i+1][j] != 0)
        c++;
    }

  for(int i=0; i<R-1; i++)
    if(m[i][C-1] != 0 && m[i+1][C-1] != 0)
      c++;

  for(int j=0; j<C-1; j++)
    if(m[R-1][j] != 0 && m[R-1][j+1] != 0)
      c++;

  return c;
}

int solve(vector<vector<int>> &m, int N)
{
  if(N==0)
  {
    return count(m);
  }

  int min = 1000000;
  for(int i=0; i<m.size(); i++)
    for(int j=0; j<m[i].size(); j++)
    {
      if(m[i][j] == 0)
      {
        //vector<vector<int>> t = m;
        m[i][j] = 1;
        int s = solve(m, N-1);
        m[i][j] = 0;


        if(s < min)
          min = s;
      }
    }

  return min;
}

void place(vector<vector<int>> &m, int R, int C, int N)
{
  if(N==0)
    return;

  if(m[0][0] == 0)
  {
    m[0][0]=1;
    N--;
  }

  if(N==0)
    return;

  if(m[0][C-1] == 0)
  {
    m[0][C-1]=1;
    N--;
  }

  if(N==0)
    return;

  if(m[R-1][0] == 0)
  {
    m[R-1][0]=1;
    N--;
  }

  if(N==0)
    return;

  if(m[R-1][C-1] == 0)
  {
    m[R-1][C-1]=1;
    N--;
  }

  if(N==0)
    return;

  for(int i=0; i<R; i++)
  {
    if(m[i][0] == 0)
    {
      m[i][0]=1;
      N--;
    }

    if(N==0)
      return;
  }

  for(int i=0; i<R; i++)
  {
    if(m[i][C-1] == 0)
    {
      m[i][C-1]=1;
      N--;
    }

    if(N==0)
      return;
  }

  for(int i=0; i<C; i++)
  {
    if(m[0][i] == 0)
    {
      m[0][i]=1;
      N--;
    }

    if(N==0)
      return;
  }

  for(int i=0; i<C; i++)
  {
    if(m[R-1][i] == 0)
    {
      m[R-1][i]=1;
      N--;
    }

    if(N==0)
      return;
  }

  for(int i=0; i<R; i++)
    for(int j=0; j<C; j++)
      if(m[i][j]==0)
      {
        m[i][j]=1;
        N--;

        if(N==0)
          return;
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

  for(int testCase=0; testCase<T; ++testCase)
  {
    int s = 0; 
    int R, C, N;

    in >> R >> C >> N;

    vector<vector<int>> m1(R, vector<int>(C));
    vector<vector<int>> m2(R, vector<int>(C));

    int count1=0, count2 =0;

    int sm = 1;

    for(int i=0; i<R; i++)
    {
      for(int j=sm; j<C; j+=2)
      {
        m1[i][j]=1;
        count1++;
      }

      sm = (sm+1)%2;
    }

    sm=0;

    for(int i=0; i<R; i++)
    {
      for(int j=sm; j<C; j+=2)
      {
        m2[i][j]=1;
        count2++;
      }

      sm = (sm+1)%2;
    }

    if(N<=count1 || N <= count2)
      s = 0;
    else
    {
      place(m1,R,C, N-count1);
      int c1=count(m1);

      place(m2,R,C, N-count2);
      int c2=count(m2);

      s = min(c1,c2);
    }


    out << "Case #"<<testCase+1<<": ";

    out << s << endl;
  }

  return 0;
}