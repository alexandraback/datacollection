#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <set>

#define mp make_pair
#define pb push_back
#define problem "test"
typedef __int128 ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
const int z = 111111;
const double eps = 1e-9;
const int inf = int(1e9);
const ll llinf = ll(1e18);
using namespace std;

int p, x;
set <pair <int, int> > cnt;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen(problem".in", "r", stdin);
	freopen(problem".out", "w", stdout);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
		cout << "Case #" << test << ": ";

		cin >> p;
		for (int i = 0; i < p; i++)
		{
			cin >> x;
			cnt.insert({-x, i});
		}
		while (1)
		{
		    pair <int, int> tmp, tmp1, tmp2;
			if (cnt.size() > 2)
			{
				tmp = *cnt.begin();
				cnt.erase(tmp);
				tmp.first++;
				if (tmp.first)
					cnt.insert(tmp);
				cout << char(tmp.second + 'A') << " ";
			}
			else
			{
			    if (cnt.empty())
			    	break;
				tmp1 = *cnt.begin();
				cnt.erase(tmp1);
				tmp2 = *cnt.begin();
				cnt.erase(tmp2);
				if (tmp1.first == tmp2.first)
				{
					tmp1.first++;
					tmp2.first++;
				    if (tmp1.first)
						cnt.insert(tmp1);
	                if (tmp2.first)
						cnt.insert(tmp2);
					cout << char(tmp1.second + 'A') << char(tmp2.second + 'A') << " ";
				}
				else
				{
					tmp1.first++;
				    if (tmp1.first)
						cnt.insert(tmp1);
					cnt.insert(tmp2);
					cout << char(tmp1.second + 'A') << " ";
				}
			}
		}
		cout << "\n";
	}
	
	return 0;
}