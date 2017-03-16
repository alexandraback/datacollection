#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

using namespace std;

#define pb push_back
#define sz(x) ((int) (x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define clr(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef long long ll;
typedef pair<ll,ll> pll;

struct x
{
	char _char;
	int count;
};

int dist(string i, string j)
{
	if (i == j)
		return 0;
	if (i.size() == 0 && j.size() != 0)
		return -1;
	if (i.size() != 0 && j.size() == 0)
		return -1;

	x ich[100];
	int ichN = 0;
	x jch[100];
	int jchN = 0;
	forn(a,100)
	{
		ich[a]._char = -1;
		ich[a].count = 0;
		jch[a]._char = -1;
		jch[a].count = 0;
	}

	int currentIndex = 0;
	for (int ic = 0; ic < i.size(); ic++)
	{
		if (ich[currentIndex]._char == -1)
		{
			ich[currentIndex]._char = i[ic];
			ich[currentIndex].count = 1;
			continue;
		}

		if (ich[currentIndex]._char == i[ic])
		{
			ich[currentIndex].count++;
		}
		else
		{
			currentIndex++;
			ich[currentIndex]._char = i[ic];
			ich[currentIndex].count = 1;
		}
	}
	currentIndex = 0;
	for (int jc = 0; jc < j.size(); jc++)
	{
		if (jch[currentIndex]._char == -1)
		{
			jch[currentIndex]._char = j[jc];
			jch[currentIndex].count = 1;
			continue;
		}

		if (jch[currentIndex]._char == j[jc])
		{
			jch[currentIndex].count++;
		}
		else
		{
			currentIndex++;
			jch[currentIndex]._char = j[jc];
			jch[currentIndex].count = 1;
		}
	}
	/*
	forn(ic, 100)
	{
		cout << ic << endl;
		if (ich[ic]._char != -1)
		{
			printf("i[%d] %c %d\n", ic, ich[ic]._char, ich[ic].count);
		}
		if (jch[ic]._char != -1)
		{
			printf("j[%d] %c %d\n", ic, jch[ic]._char, jch[ic].count);
		}
	}
	*/

	int d = 0;
	forn(z, 100)
	{
		if (ich[z]._char != jch[z]._char)
		{
			return -1;
		}

		if (ich[z]._char == -1)
		{
			break;
		}
		
		d += abs( ich[z].count - jch[z].count );
	}

	return d;
}


void getDesc(string i, x *desc)
{
	int currentIndex = 0;
	for (int ic = 0; ic < i.size(); ic++)
	{
		if (desc[currentIndex]._char == -1)
		{
			desc[currentIndex]._char = i[ic];
			desc[currentIndex].count = 1;
			continue;
		}

		if (desc[currentIndex]._char == i[ic])
		{
			desc[currentIndex].count++;
		}
		else
		{
			currentIndex++;
			desc[currentIndex]._char = i[ic];
			desc[currentIndex].count = 1;
		}
	}

	forn(ic, 100)
	{
		//cout << ic << endl;
		if (desc[ic]._char != -1)
		{
			//printf("i[%d] %c %d\n", ic, desc[ic]._char, desc[ic].count);
		}
	}
}

int distt(int l[100], int n)
{
	long min = 1000000000;

	forn(i, n)
	{
		long current = 0;
		forn(j, n)
		{
			if (i == j)
				continue;
			current += abs(l[j] - l[i]);
		}

		if (min > current)
			min = current;
	}

	return min;
}

void solve(int t)
{
	int n;
	string s[100];
	x desc[100][100];

	cin >> n;
	forn(i,n)
	{
		cin >> s[i];
		forn(j,100)
		{
			desc[i][j]._char = -1;
			desc[i][j].count = 0;
		}
	}

	long min = 1000000000;
	forn(i,n)
	{
		//cout << "all to " << s[i] << endl;
		getDesc(s[i], desc[i]);
	}

	forn(i, n)
	{
		forn(j, n)
		{
			forn(z,100)
			{
				if (desc[i][z]._char != desc[j][z]._char)
				{
					cout << "Case #" << t << ": Fegla Won" << endl;
					return;
				}
			}
		}
	}

	int result = 0;
	forn(z, 100)
	{
		if (desc[0][z]._char == -1)
			break;

		int l[100];

		forn(i, n)
		{
			l[i] = desc[i][z].count;
		}

		result += distt(l, n);

	}
		//int steps = 0;
		/*
		forn(j,n)
		{
			if (i == j)
				continue;

			int d = dist(s[i], s[j]);
			cout << "dist beetwen " << s[i] << " " << s[j] << " - " << d << endl;
			if (d == -1)
				goto not_possible;

			steps += d;
		}*/
		/*
		cout << "min " << min << endl;
		cout << "current" << steps << endl;

		if (min > steps)
			min = steps;
			*/

	cout << "Case #" << t << ": " << result << endl;
	return;
}

void main()
{
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		solve(i);
	}
}