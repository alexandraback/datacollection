#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define vi vector<int>
#define vs vector<string>
#define vl vector<LL>
#define pb push_back
#define endl "\n"

struct Point
{
   LL X;
   LL Y;
};

LL check(const vector<Point>& pts, int i, int j)
{
   LL side1 = 0;
   LL side2 = 0;
   LL N = pts.size();
   for(int k=0;k<N;++k)
   {
      if (k==i || k == j) continue;
      LL val = (pts[j].X - pts[i].X)*(pts[k].Y - pts[j].Y) - (pts[k].X-pts[j].X)*(pts[j].Y - pts[i].Y);
      if (val < 0)
         side1 ++;
      else
         side2 ++;
   }
   return min(side1, side2);
}

void solve(vl& ret)
{
   vector<Point> pts;
   LL N;
   cin >> N;
   for(int i=0;i<N;i++)
   {
      Point p;
      cin >> p.X >> p.Y;
      pts.pb(p);
   }

   for (int i=0;i<N;i++)
   {
      LL num = N;
      for (int j=0;j<N;j++)
      {
         if  (j == i) continue;
         num = min(num, check(pts, i, j));
      }
      if  (N <= 2)
         num = 0;
      assert(num < N);
      ret.pb(num);
   }
   assert(LL(ret.size()) == N);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
	   vl ret;
	   solve(ret);
	   cout  << "Case #" << i << ":" << endl;
	   for (auto it : ret)
	      cout << it  << endl;
	}

	return 0;
}
