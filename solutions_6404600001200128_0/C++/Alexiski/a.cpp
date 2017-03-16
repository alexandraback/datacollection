#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int T; cin >> T;
  for (int ii = 0; ii<T; ii++)
  {
    int d; cin >> d;
    vector<int> v(d);
    for (int i=0; i<d; i++)
    {
      cin >> v[i];
    }  
    
    long long s1 = 0;
    long long  mx = 0;
    for (int i=1; i<d; i++)
    {
      if (v[i] < v[i-1])
      {
        long long d = v[i-1] - v[i];
        s1 += d;
        if (d > mx) mx = d;
      }
    }
    long long s2 = 0;
    for (int i=0; i<d-1; i++)
    {
      if (v[i] > mx)
      {
        s2 += mx;
      }
      else
      {
        s2 += v[i];
      }
    }
    
    cout << "Case #" << ii+1 << ": " << s1 << " " << s2 << endl;
  }
  return 0;
}
