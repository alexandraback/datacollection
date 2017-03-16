#include <iostream>
#include <vector>
using namespace std;

long long attempt(long long t, int d, const vector<int> &data)
{
   long long s = 0;
   for (int i= 0; i<d; i++)
   {
     s += (t-1)/data[i] + 1;
   }
   return s;
}

int cnt(int n, int d, const vector<int> &data)
{
   if (n <=d) return n;
   long long t1 = 0; long long a1 = 0;
   long long t2 = 1000000; long long a2;
   do
   {
     t2 *= 2;
     a2 = attempt(t2, d, data);
   }  while (a2 < n-1);
   while ((t2-t1 > 1) && (a1 != n-1))
   {
      long long t = (t1 + t2)/2;
      long long a = attempt(t, d, data);
      if (a > n-1)
      {
        t2 = t;
        a2 = a;
      }
      else
      {
        t1 = t;
        a1 = a;
      }
   }
   int r = n - a1;
   int mn = data[0];
   for (int i= 0; i<d; i++)
   {
     int cur = data[i]*((t1-1)/data[i] + 1) - t1;
     if (cur < mn) mn = cur;
   }
   //cout << " <t1>: " << t1 << " <a1>: " << a1 << " <t2>: " << t2 << " <a2>: " << a2 << " <mn>: " << mn << endl;
   for (int i= 0; i<d; i++)
   {
     int cur = data[i]*((t1-1)/data[i] + 1) - t1;
     if (cur == mn) 
     {
       r--;
       if (r == 0) return i+1;
     }
   }
   return 0;
}

int main()
{
  int T; cin >> T;
  for (int ii = 0; ii<T; ii++)
  {
    int d, n; cin >> d >> n;
    vector<int> data(d);
    for (int i=0; i<d; i++) 
    {
      cin >> data[i];
    }
	
    cout << "Case #" << ii+1 << ": " << cnt(n, d, data) << endl;
  }
  return 0;
}
