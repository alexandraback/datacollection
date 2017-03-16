#include "bits/stdc++.h"

using namespace std;

void test()
{
  priority_queue <pair <int, int> > Q;
  int n;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    int x;
    cin >> x;
    Q.push(make_pair(x,i));
  }
  while(!Q.empty())
  {
    pair <int, int> fir = Q.top();
    Q.pop();
    cout << (char)(fir.second+'A');
    if(!Q.empty() and Q.size() != 2)
    {
      pair <int, int> sec = Q.top();
      Q.pop();
      cout << (char)(sec.second+'A');
      if(sec.first != 1)
        Q.push(make_pair(sec.first-1, sec.second));
    }
    if(fir.first != 1)
      Q.push(make_pair(fir.first-1, fir.second));
    cout << " ";
  }
}

int main()
{
  int t;
  cin >> t;
  for(int tti=1; tti<=t; tti++)
  {
    cout << "Case #" << tti << ": ";
    test();
    cout << "\n";
  }
}
