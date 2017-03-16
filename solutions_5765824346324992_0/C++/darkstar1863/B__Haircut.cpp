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

void calc(vector<int64> &V, int64 &clientsGot, vector<int> &Barders, int64 mid)
{
	clientsGot = 0;
	Barders.clear();
	FORS(i, V)
	{
		clientsGot += mid / V[i];
		if (mid % V[i] == 0)
		{
			Barders.push_back(i);
		}
		else
			++clientsGot;
	}
}

void Runner::Run()
{
	int B;
	int64 N;
	mIn >> B >> N;
	vector<int64> V(B);
	FORS(i, V)
		mIn >> V[i];

	int64 l = 0, r = N * (*max_element(V.begin(), V.end()));
	int64 clientsGot;
	vector<int> Barbers;

	if (N == 1)
	{
		mOut << "Case #" << mCase << ": ";
		mOut << 1;
		mOut << endl;
		return;
	}

	while (l<r)
	{
		int64 mid = (l + r) / (int64)2;
		calc(V, clientsGot, Barbers, mid);

		int64 should = N - 1;

		if (clientsGot > should)
		{
			r = mid - 1;
		}
		else
		{
			if (clientsGot + SIZE(Barbers) <= should)
			{
				l = mid + 1;
			}
			else
			{
				if (Barbers.empty())
				{
					l = mid + 1;
				}
				else
				{
					l = r = mid;
				}
			}
		}
	}

	if (l == r)
		calc(V, clientsGot, Barbers, l);

	int index = (int)(N - 1 - clientsGot);

	mOut << "Case #" << mCase << ": ";
	mOut << Barbers[index] + 1;
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
