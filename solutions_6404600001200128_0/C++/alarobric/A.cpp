//Google Codejam
//2015 Round 1A
//Alan Richards - alarobric

//Problem A
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <array>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

#define FOR(i, n) for(ull i=0; i<n; i++)
#define FOREACH(c, iter) for(auto iter=c.begin(); iter!=c.end(); iter++)

#ifdef DEBUG
#define Debug(x) std::cerr << x << endl
#else
#define Debug(x)
#endif

typedef unsigned long long ull;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;

template <class T>
string ContainerPrint(T a)
{
	stringstream ss;
	FOREACH(a, iter)
		ss << *iter << " ";
	return ss.str();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define MAXN 1000

string Solve(int i_case)
{
	int N;
	std::cin >> N;
	std::array<int, MAXN> m;
	FOR(i, N) std::cin >> m[i];

	//10 5 15 5
	int method1 = 0;
	int maxrate = 0;
	for(int i=1; i<N; ++i)
	{
		method1 += max(0, m[i-1]-m[i]);
		maxrate = max(maxrate, m[i-1]-m[i]);
	}
	Debug(maxrate);

	int method2 = 0;
	for(int i=0; i<N-1; ++i)
	{
		method2 += min(m[i], maxrate);
	}
	
	stringstream result;
	result << method1 << " " << method2;
	return result.str();
}

int main()
{
	std::cerr << "GCJ 2015 Round 1A-A" << std::endl;
	int numCases;
	std::cin >> numCases;
	for (int i=1; i<=numCases; i++)
	{
		std::cout << "Case #" << i << ": " << Solve(i) << std::endl;
	}
	return 0;
}