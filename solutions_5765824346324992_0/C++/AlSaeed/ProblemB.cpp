#include <iostream>
#include <cstdio>
#include <cmath>
#define BMax 5
#define MMax 25
using namespace std;

int M[BMax];
int B;
int N;

void read()
{
  cin >> B;
  cin >> N;
  for(int i=0;i<B;i++)
    cin >> M[i];
}

long servedBy(long T)
{
  long rst = 0;
  for(int i=0;i<B;i++)
    rst+=(long)ceil(1.0*T/M[i]);
  return rst;
}

int whichPosition(long T)
{
  int rank = (int) ( N - servedBy(T-1));
  T--;
  for(int i=0;i<B;i++)
    if(T%M[i] ==0)
      {
	if(rank == 1)
	  return i+1;
	else
	  rank--;
      }
  return -1;
}

int solve()
{
  if(N<B)//Un naccessary
    return N;
  long l=1,u=MMax * (long)N, m =(l+u)/2;
  long s;
  while( u > l+1 )
    {
      s = servedBy(m);
      if( s >= N )
	u = m;
      else
	l = m;
      m = (u+l)/2;
    }
  for(long i=l;i<=u;i++)
    {
      if(servedBy(i) >=N)
	return whichPosition(i);
    }
  return -1;
}

int main()
{
  int n;
  cin >> n;
  for(int t=1;t<=n;t++)
    {
      read();
      cout << "Case #" << t << ": " << solve() << endl;
    }
  return 0;
}
