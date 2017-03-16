#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define debug_flag true
#else
	#define debug_flag false
#endif

#define dbg(args...) { if (debug_flag) { _print(_split(#args, ',').begin(), args); cerr << endl; } else { void(0);} }

vector<string> _split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return v;
}

void _print(vector<string>::iterator) {}
template<typename T, typename... Args>
void _print(vector<string>::iterator it, T a, Args... args) {
    string name = it -> substr((*it)[0] == ' ', it -> length());
    if (isalpha(name[0]))
	    cerr << name  << " = " << a << " ";
	else
	    cerr << name << " ";
	_print(++it, args...);
}

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42;
#endif

typedef long long int int64;

void solve(int test)
{
	int n;
	scanf("%d", &n);
	vector<pair<int, char> > list(n);
	for (int i = 0; i < n; i++)
	{
		int cnt;
		scanf("%d", &cnt);
		list[i] = make_pair(cnt, (char)('A' + i));
	}
	sort(list.rbegin(), list.rend());

	printf("Case #%d:", test);
	while (list[0].first > list[1].first)
	{
		printf(" %c", list[0].second);
		list[0].first--;
	}

	for (int i = 2; i < (int)list.size(); i++)
	{
		for (int j = 0; j < (int)list[i].first; j++)
			printf(" %c", list[i].second);
	}

	for (int i = 0; i < list[0].first; i++)
		printf(" %c%c", list[0].second, list[1].second);

	printf("\n");
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

    int tests;
    scanf("%d", &tests);
    for (int test = 0; test < tests; test++)
    {
        dbg(test);
        solve(test + 1);
    }

	return 0;
}
