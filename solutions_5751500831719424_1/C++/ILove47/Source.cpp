#include <ctime>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
using namespace std;
 
 
#define PB	push_back
#define MP  make_pair
#define ALL(a) 	(a).begin(), (a).end()
#define FILL(a,v) memset(a,v,sizeof(a))

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ABS(A) ((A) < 0 ? (-(A)) : (A))
#define SQR(x) (x)*(x)

const double PI = acos(-1.0);
const double EPS = 1e-7;

const int INF = 2000000000;
 
const string felga = "Fegla Won";

string a[111];
vector<int> v[111];
void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		v[i].clear();
		string s;
		cin >> s;
		a[i] = "";

		for (int j = 0; j < s.size(); ++j)
		{
			if (j==0)
			{
				a[i].push_back(s[j]);
				v[i].push_back(1);
			}
			else
			{
				if (s[j] == s[j-1])
				{
					v[i][v[i].size()-1]++;
				}
				else
				{
					a[i].push_back(s[j]);
					v[i].push_back(1);
				}
			}
		}
	}
	bool b = false;
	for (int i = 1; i < n; ++i)
	{
		if (strcmp(a[i].c_str(), a[i-1].c_str()) != 0)
		{
			b = true;
			break;
		}
	}
	if(b)
	{
		cout << felga;
	}
	else
	{
		long long res = 0;
		for (int i = 0; i < v[0].size(); ++i)
		{
			int mx,mn;
			mx=mn=v[0][i];
			for (int j = 0; j < n; ++j)
			{
				if (v[j][i] < mn)
				{
					mn = v[j][i];
				}
				if (v[j][i] > mx)
				{
					mx = v[j][i];
				}
			}
			res += mx-mn;
		}
		cout << res;
	}
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test)
	{
		cout << "Case #"<<test<<": ";
		solve();
		cout << endl;
	}





	return 0;
} 
