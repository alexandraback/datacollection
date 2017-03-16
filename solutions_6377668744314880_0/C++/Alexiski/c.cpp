#include <iostream>
#include <vector>
using namespace std;

long long prod(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return ((long long)(x3-x1))*(y2-y1) - ((long long)(y3-y1))*(x2-x1);
}

int cnt1(int k1, int k2, int n, const vector<int> &x, const vector<int> &y)
{
    int cn = 0, cp = 0;
    for (int i=0; i<n; i++)
    {
       long long p = prod(x[k1], y[k1], x[k2], y[k2], x[i], y[i]);
       if (p > 0) cp++;
       else
       if (p < 0) cn++;
    }
    return (cn < cp) ? cn : cp;
}

int cnt(int k, int n, const vector<int> &x, const vector<int> &y)
{
    if (n<4) return 0;
    int c = n;
    for (int i=0; i<n; i++)
    {
        if (i != k)
        {
            int cur = cnt1(i, k, n, x, y);
            if (cur == 0) return 0;
            else if (cur < c) c = cur;
        }  
    }
    return c;
}	

int main()
{
  int T; cin >> T;
  for (int ii = 0; ii<T; ii++)
  {
    int d; cin >> d;
    vector<int> x(d), y(d);
    int m = 0;
    for (int i=0; i<d; i++) 
    {
      cin >> x[i] >> y[i];
    }
	
    cout << "Case #" << ii+1 << ": " << endl;
    for (int i=0; i<d; i++) 
    {
      cout << cnt(i, d, x, y) << endl;
    }
  }
  return 0;
}
