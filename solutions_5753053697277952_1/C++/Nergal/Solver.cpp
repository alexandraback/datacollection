#include <memory>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <math.h>  
#include <cmath>  
#include <bitset>

#include "bigint-2010.04.30/BigInteger.hh"

using namespace std;

#define all(a) (a).begin(), (a).end()
#define FOR(i, a, b) for (long i(a), _b(b); i < _b; ++i)
const double pi = 2 * acos(0.0);
// greatest common divisor
template<class T> T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
// square
template<class T> T sqr(T a) { return (a)* (a); }

typedef pair<char, int> party;

struct cmpParty
{
	bool operator()(const party& a, const party &b)
	{
		return a.second > b.second;
	}
};


BigInteger absBigInt(const BigInteger &bg)
{
	if (bg < 0)
		return bg*BigInteger(-1);
	return bg;
}


class TestCaseSolver
{
public:
	TestCaseSolver() {}

	~TestCaseSolver() {
	}

	// to read/init the test case
	void readTestCase(std::istream &istr)
	{
		int N;
		istr >> N;
		totalSenators = 0;
		senators.resize(N);
		FOR(i, 0, N)
		{
			int p;
			istr >> p;
			totalSenators += p;
			senators[i] = make_pair('A'+i, p);
		}

		
	}


	// to solve the test case and output the value to ostr
	std::string solveTestCase()
	{
		stringstream ss;

		
		while (totalSenators>0)
		{
			sort(all(senators), cmpParty());
			//cannot have only one party remaining...
			party &p1 = senators[0];
			party &p2 = senators[1];
			if (p1.second > p2.second+1 || (( p1.second == p2.second + 1) && (totalSenators-2)/2 >= p2.second))
			{
				ss << p1.first << p1.first << " ";
				p1.second -= 2;
				totalSenators -= 2;
			}
			else if (p1.second == p2.second + 1)
			{
				p1.second -= 1;
				--totalSenators;
				ss << p1.first<< " ";
			}
			else // same number >0
			{
				// check number of remaining senators
				if ((totalSenators) > p2.first * 2 || totalSenators == (p1.second + p2.second))
				{
					p1.second -= 1;
					p2.second -= 1;
					totalSenators -= 2;
					ss << p1.first << p2.first << " ";
				}
				else // a third party could have absolute majority, only remove one senator
				{
					p1.second -= 1;
					totalSenators -= 1;
					ss << p1.first << " ";
				}
				
			}
		}
		
		return ss.str();
	}

	vector<party> senators;
	long totalSenators;
};



int main(int argc, char* argv[])
{
	std::ios_base::sync_with_stdio(false);

	std::string inputFile("C:\\Users\\David\\Downloads\\A-large (2).in");
	std::string outputFile("C:\\GoogleJam\\A.out");

	ofstream out;
	ifstream in;

	//in.open(argv[1]);
	//out.open(argv[2]);
	in.open(inputFile);
	out.open(outputFile);

	unsigned int nbTestCases;
	in >> nbTestCases;

	for (unsigned int curTest = 1; curTest <= nbTestCases; ++curTest)
	{
		TestCaseSolver testcaseSolver;

		testcaseSolver.readTestCase(in);
		std::string answer = testcaseSolver.solveTestCase();
		out << "Case #" << curTest << ": " << answer << '\n';
		cout << "Case #" << curTest << ": " << answer << endl;

	}
	out << flush;

	return 0;
}