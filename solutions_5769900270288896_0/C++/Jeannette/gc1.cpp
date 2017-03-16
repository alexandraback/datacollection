#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include <set>
using namespace std;
//
//void add(vector<int> & a1, vector<int> a2)
//{
//    int n = min(a1.size(), a2.size());
//    int d = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        a1[i] += a2[i] + d;
//        d = a1[i]/10;
//        a1[i]%=10;
//    }
//    int m = max(a1.size(), a2.size());
//    if (a1.size() == n)
//        for (int i = n; i < m; ++i)
//        {
//            a1.push_back(a2[i] + d);
//            d = a1[i]/10;
//            a1[i] %= 10;
//        }
//    else
//        for (int i = n; i < m; ++i)
//        {
//            a1[i] += d;
//            d = a1[i]/10;
//            a1[i] %= 10;
//        }
//    if (d != 0)
//        a1.push_back(1);
//}
//vector<vector<int> > mas;

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
	cin>>t;
	for (int j = 0; j < t; ++j)
	{
		int n, r, c;
		cin>>r>>c>>n;
		int w = (r - 1) * c + (c - 1) * r;
		int blank = r * c - n;
		int res = 0;
		if (n > (r * c + 1) / 2)
		{
			int in = ((r - 2) * (c - 2) + 1)/2;
			if (r < 2 || c < 2) in = 0;
			res = w;
			res -= min(in, blank) * 4;
			blank -= in;
			if (blank < 0) blank = 0;
			if (r < c) swap(r, c);
			if (c > 1)
			{
				in =(r - 2)/2 * 2 + (c - 2)/2 * 2 + (r + c)%2;
				res -= min(in, blank) * 3;
				blank -= in;
				if (blank < 0) blank = 0;
				in =(r * c + 1)%2 * 2;
				res -= min(in, blank) * 2;
			} 
			else 
			{
				in =((r - 1) / 2);
				res -= min(in, blank) * 2;
			}
			int res2 = w;
			in = (r - 2) * (c - 2) - ((r - 2) * (c - 2) + 1)/2;
			if (r < 2 || c < 2) in = 0;
			blank = r * c - n;
			res2 -= min(in, blank) * 4;
			blank -= min(in, blank);
			if (r < c) swap(r, c);
			if (c > 1)
			{
				in =(r - 1)/2 * 2 + (c - 1)/2 * 2 - (r + c)%2;
				res2 -= min(in, blank) * 3;
				blank -= min(in, blank);
				in =(r * c + 1)%2 * 2;
				res2 -= min(in, blank) * 2;
			} 
			else 
			{
				in =((r - 1) / 2);
				res2 -= min(in, blank) * 2;
			}
			res = min(res, res2);
		}
		cout<<"Case #"<<j + 1<<": "<<res<<endl;
	}
    return 0;
}