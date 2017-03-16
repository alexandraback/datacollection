#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int P[26];
int N;

void read()
{
  cin >> N;
  for(int i=0;i<N;i++)
    cin >> P[i];
}

bool test()
{
  int S=0;
  for(int i=0;i<N;i++)
    S+=P[i];
  if(S==0)
    return true;
  for(int i=0;i<N;i++)
    if(P[i]*2>S)
      return false;
  return true;
}

bool done()
{
  for(int i=0;i<N;i++)
    if(P[i]!=0)
      return false;
  return true;
}

int max()
{
  int rst = -1;
  int ndx = -1;
  for(int i=0;i<N;i++)
    if(P[i]>rst)
      {
	rst=P[i];
	ndx=i;
      }
  return ndx;
}

void solve()
{
  while(!done())
    {
      cout << " ";
      int m = max();
      cout << (char)(m+'A');
      P[m]--;
      if(!test())
	{
	  m = max();
	  cout << (char)(m+'A');
	  P[m]--;
	}
      if(!test())
	cout << " [Error] "; 
    }
}

int main()
{
  int T;
  cin >> T;
  for(int t=1;t<=T;t++)
    {
      read();
      cout << "Case #" << t << ":";
      solve();
      cout << endl;
    }
  return 0;
}
