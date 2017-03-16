//#define MYDEBUG
#define _CRT_SECURE_NO_WARNINGS
#define TASK "A-small-attempt0"
#pragma comment(linker, "/STACK:536870912")
#include <cstdio>
#include <iostream>
#include <iomanip> 
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <cassert>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <random>

const int MOD = 1000000007;
const int INF = 1000000001;
const int MAXN = 100010;
const long double EPS = 1e-8;
const int HASH_POW = 29;
const long double PI = acos(-1.0);

using namespace std;

void my_return(int code)
{
#ifdef MYDEBUG
	cout << "\nTime = " << fixed << setprecision(3) << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
	exit(code);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	mt19937 mt_rand(time(0));
#ifdef MYDEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(TASK".in", "rt", stdin);
	freopen(TASK".out", "wt", stdout);
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/
#endif

	int CASE;
	cin >> CASE;
	for (int it = 1; it <= CASE; ++it)
	{
		int n, cnt[26];
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> cnt[i];

		cout << "Case #" << it << ":";
		
		vector <char> ord;
		while (true)
		{
			int mx = 0, pos = -1;
			for (int i = 0; i < n; ++i)
			{
				if (cnt[i] > mx)
				{
					mx = cnt[i];
					pos = i;
				}
			}
			if (pos == -1)
				break;
			ord.push_back('A' + pos);
			--cnt[pos];
		}

		int ptr = 0;
		if (ord.size() % 2 == 1)
		{
			cout << ' ' << ord[0];
			ptr = 1;
		}
		while (ptr < ord.size())
		{
			cout << ' ' << ord[ptr] << ord[ptr + 1];
			ptr += 2;
		}

		cout << endl;
	}

	my_return(0);
}