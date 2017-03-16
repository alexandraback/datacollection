/* 2015 Round 1A
 * Problem B
 * intrepid
 */
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>
#include <numeric>
#include <memory>
#include <limits>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;

default_random_engine generator(system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> distribution(1,100);
auto myRand = bind(distribution, generator);

typedef vector<int64_t> TimesVec;
typedef vector<int64_t> BarberVec;

int64_t NumCuts(const TimesVec& M, int64_t t)
{
	int64_t n = M.size();
	for (auto m : M)
	{
		assert( n > 0 );
		n += t / m;
	}
	return n;
}

BarberVec BarbersFinished(const TimesVec& M, int64_t t)
{
	BarberVec barbers;
	for (int64_t i=0; i<(int64_t)M.size(); ++i)
	{
		if ( t % M[i] == 0 )
			barbers.push_back(i+1);
	}
	return barbers;
}

bool doTest()
{
	int64_t B, N;
	cin >> B >> N;
	TimesVec M;
	int64_t m;
	int64_t m_max = 0;
	for (int64_t i=0; i<B; ++i)
	{
		cin >> m;
		if ( m > m_max )
			m_max = m;
		M.push_back(m);
	}
	if ( N <= B )
	{
		cout << N;
		return true;
	}
	int64_t t_min = 0;
	int64_t t_max = m_max * N + 1;
	while (true)
	{
		int64_t t = t_min + ( t_max - t_min ) / 2;
		int64_t num_cuts = NumCuts(M, t);
		if ( num_cuts < N )
			t_min = t;
		else if ( num_cuts >= N )
			t_max = t;
		if ( t_max == t_min + 1 )
			break;
	}
	N -= NumCuts(M, t_min);
	assert( N > 0 );
	assert( N <= B );
	BarberVec barbers = BarbersFinished(M, t_max);
	assert( N <= (int64_t)barbers.size() );
	cout << barbers[N - 1];
	
	return true;
}

int main(int /*argc*/, char **/*argv[]*/)
{
	cout << scientific << setprecision(7);
	int runs;
	cin >> runs;
	if ( ! cin.good() )
	{
		cerr << "Error reading runs!\n" << endl;
		return 0;
	}
	for (int run=1; run <= runs; ++run) {
		cout << "Case #" << run << ": ";
		
		if ( !doTest() )
		{
			cerr << "Test case failed!" << endl;
			break;
		}
		
		cout << "\n";
	}
	if ( !cin.good() ) cerr << "Error reading!\n" << endl;
	
	return 0;
}
