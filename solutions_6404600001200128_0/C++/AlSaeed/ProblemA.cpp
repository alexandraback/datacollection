#include <iostream>
#include <cstdio>
#define NMax 1000
using namespace std;

int m[NMax];
int N,Rst1,Rst2;

void read()
{
  cin >> N;
  for(int i=0;i<N;i++)
    cin >> m[i];
}

int computeFirst()
{
  int sum=0;
  for(int i=1;i<N;i++)
    if(m[i-1]>m[i])
      sum+=m[i-1]-m[i];
  return sum;
}

int computeSecond()
{
  int max=0;
  for(int i=1;i<N;i++)
    {
      int tmp = m[i-1]-m[i];
      if(tmp>max)
	max=tmp;
    }
  int sum=0;
  for(int i=0;i<N-1;i++)
    if(m[i]<max)
      sum+=m[i];
    else
      sum+=max;
  return sum;
}

void solve()
{
  Rst1 = computeFirst();
  Rst2 = computeSecond();
}

int main()
{
  int n;
  cin >> n;
  for(int t=1;t<=n;t++)
    {
      read();
      solve();
      cout << "Case #"<<t<<": "<<Rst1<<" "<<Rst2<<endl;
    }
  return 0;
}
