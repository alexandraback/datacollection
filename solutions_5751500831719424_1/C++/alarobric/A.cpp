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
	//Debug("AHHHHH" << N);

	array<pair<char, array<int, 101>>, 101> characters;
	string str;
	int numCharacters;

	cin >> str;
	int n = 0;	//string number
	int i = 0;	//index to character number
	int j = 0;	//index to character in string
	while(true)
	{
		char c = str[j];
		characters[i].first = c;
		auto pos = str.find_first_not_of(c, j);
		if (pos == string::npos)
		{
			characters[i].second[n] = str.size() - j;
			numCharacters = i+1;
			break;
		}
		else
			characters[i].second[n] = pos - j;
		j = pos;
		i++;
	}
	bool fail = false;
	for(n=1; n<N; n++)
	{
		cin >> str;
		int i = 0;	//index to character number
		int j = 0;	//index to character in string
		while(true)
		{
			char c = str[j];
			if (characters[i].first != c)
				fail = true;
			auto pos = str.find_first_not_of(c, j);
			if (pos == string::npos)
			{
				characters[i].second[n] = str.size() - j;
				break;
			}
			else
				characters[i].second[n] = pos - j;
			j = pos;
			i++;
		}
	}

	if (fail)
		return "Fegla Won";

	//the strings are possible, just work out how many moves
	int numMoves = 0;

	FOR(i,numCharacters)
	{
		//Debug(N);
		sort(characters[i].second.begin(), characters[i].second.begin()+N);
		int mid = N/2;
		if (N%2 == 0)
			mid = (characters[i].second[mid-1] + characters[i].second[mid]) / 2;
		else
			mid = characters[i].second[mid];

		FOR(j,N)
		{
			if (characters[i].second[j] == 0)
				return "Fegla Won";
			numMoves += abs(mid - characters[i].second[j]);
		}
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