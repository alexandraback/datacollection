#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define psv pair <string, vector<int> >
#define mp make_pair 
vector < psv > a; 
psv simplify(string s)
{
	string temp = "";
	vector <int> cnt;
	int i, tcnt = 0;
	for(i=0; i < s.size(); i++)
	{
		if(i==0 || s[i]!= s[i-1])
		{
			if(i)
				cnt.push_back(tcnt);
			temp += s[i];
			tcnt = 1;
		}
		else
			tcnt ++;
	}

	cnt.push_back(tcnt);

	return mp(temp, cnt);
}

void solve()
{
	a.clear();

	int n;
	int i, j, res = 0;
	cin >> n;
	string temp;
	for(i =0; i < n; i ++)
	{
		cin >> temp;
		a.push_back(simplify(temp));
	}
	vector <int> cool[128];

	for(i = 0; i < a.size(); i ++)
	{
		if (a[i].first != a[0].first)
		{
			printf ("Fegla Won\n");
			return;
		}
		
		for(j = 0; j < a[i].second.size(); j++)
			cool[j].push_back(a[i].second[j]);
	}

	for(i = 0; i < a[0].first.size(); i++)
	{
		sort(cool[i].begin(), cool[i].end());

		for(j = 0; j < cool[i].size(); j++)
			res += abs(cool[i][j] - cool[i][cool[i].size()/2]); 

	}

	printf ("%d\n", res);	
}
int main ()
{

	int tt;
	scanf ("%d", &tt);

	int i;
	for(i = 0; i < tt; i ++)
	{
		printf ("Case #%d: ", i+1);
		solve();
	}

	return 0;
}