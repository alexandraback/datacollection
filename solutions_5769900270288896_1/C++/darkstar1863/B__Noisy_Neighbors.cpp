#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <limits>
using namespace std;

// Types
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> ipair;
const double pi=acos(-1.0);
const double eps=1e-11;

// Generic
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))
#define MP(X,Y) make_pair(X,Y)
#define FORD(i, a, b) for(int i=(a); i<(b); i++)
#define FORS(i, a) for(int i=(0); i<SIZE(a); i++)
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
template<class T> inline T sqr(T x){return x*x;}

// Bit manipulation
template<class T> void setbit(T& v, int position)    { v |= (T)1 << position; }
template<class T> void unsetbit(T& v, int position)  { v &= ~((T)1 << position); }
template<class T> void togglebit(T& v, int position) { v ^= (T)1 << position; }
template<class T> bool isbit(T v, int position) { return (v & ((T)1 << position)) != 0; }
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}

// Input / Output
string ReadToEndLine(istream& s) { string sLine; getline(s, sLine); return sLine; }
char gStr[1024];
// sprintf_s(gStr, "%d", );

struct Runner
{
	Runner(istream& in, ostream& out) : mIn(in), mOut(out), mCase(0) {}
	void RunAll();
	void Run();
	istream& mIn; ostream& mOut;
	size_t mCase;
};

void Runner::RunAll()
{
    size_t caseCount;
    mIn >> caseCount;
    ReadToEndLine(mIn);
    for(size_t c=0; c<caseCount; ++c)
    {
        mCase = c + 1;
		cout << "Case " << mCase << ": ... ";
        Run();
		cout << "done" << endl;
    }
}

int count(bool seed, int R, int C, int N)
{
	int n0 = 0, n1=0, n2 = 0, n3 = 0, n4 = 0;
	FORD(r, 0, R)
	{
		FORD(c, 0, C)
		{
			bool sR = r % 2 == 0;
			bool sC = c % 2 == 0;
			bool s = sR == sC;
			if (s == seed)
			{
				++n0;
			}
			else
			{
				if (R == 1)
				{
					if (c == 0 || c == C - 1)
						++n1;
					else
						++n2;
				}
				else
				{
					if ((r == 0 && (c == 0 || c == C - 1)) || (r == R - 1 && (c == 0 || c == C - 1)))
						++n2;
					else if (r == 0 || r == R - 1 || c == 0 || c == C - 1)
						++n3;
					else
						++n4;
				}
			}
		}
	}

	int ret = 0;
	if (N == 0)
		return ret;

	int c0 = min(N, n0);
	ret += 0 * c0;
	N -= c0;
	if (N == 0)
		return ret;

	int c1 = min(N, n1);
	ret += 1 * c1;
	N -= c1;
	if (N == 0)
		return ret;

	int c2 = min(N, n2);
	ret += 2 * c2;
	N -= c2;
	if (N == 0)
		return ret;

	int c3 = min(N, n3);
	ret += 3 * c3;
	N -= c3;
	if (N == 0)
		return ret;

	int c4 = min(N, n4);
	ret += 4 * c4;
	N -= c4;

	return ret;
}

void Runner::Run()
{
	int R, C, N;
	mIn >> R >> C >> N;

	if (R > C)
		swap(R, C);

	int res = min(count(true, R, C, N), count(false, R, C, N));

	mOut << "Case #" << mCase << ": ";
	mOut << res;
	mOut << endl;
}


string pathToCpp = __FILE__;
#ifdef LOCAL
#include "local_IO.cpp"
#endif

void main(int argc, char *argv[])
{
	string pathToFiles = pathToCpp;
	pathToFiles.resize(pathToFiles.size() - 4);
	string pathToInput = pathToFiles + ".in.txt";
	if(argc >= 2)
	{
		pathToFiles = pathToInput = argv[1];
	}

	{
		ifstream sIn(pathToInput);
		ofstream sMy(pathToFiles + ".my.txt");
		Runner runner(sIn, sMy);
		runner.RunAll();
	}

#ifdef LOCAL
	check_Nto1(pathToFiles + ".ok.txt", pathToFiles + ".my.txt");
#endif

	getchar();
}
