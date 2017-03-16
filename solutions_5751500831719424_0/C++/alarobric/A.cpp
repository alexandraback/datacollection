//Google Codejam
//2014 Round 1B
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
typedef vector<vector<int>> vvi;
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

string Solve(int i_case)
{
	int N;
	cin >> N;

	string str1, str2;
	cin >> str1;
	cin >> str2;

	size_t i = 0;	//index into string 1
	size_t j = 0;	//index into string 2
	size_t numMoves = 0;
	while(true)
	{
		char c = str1[i];
		char d = str2[j];
		if (c != d)
			return "Fegla Won";
		size_t a = str1.find_first_not_of(c, i);
		size_t b = str2.find_first_not_of(d, j);

		if ((a == string::npos && b != string::npos) || a != string::npos && b == string::npos)
			return "Fegla Won";

		if (a == string::npos && b == string::npos)
		{
			numMoves += abs(int(str1.size() - i) - int(str2.size() - j));
			break;
		}
		else
			numMoves += abs(int(a-i) - int(b-j));
		i=a;
		j=b;
	}
	
	std::ostringstream out;
	out << numMoves;
	return out.str();
}

int main()
{
	std::cerr << "GCJ 2014 Round 1B-A" << std::endl;
	int numCases;
	std::cin >> numCases;
	for (int i=1; i<=numCases; i++)
	{
		std::cout << "Case #" << i << ": " << Solve(i) << std::endl;
	}
	return 0;
}