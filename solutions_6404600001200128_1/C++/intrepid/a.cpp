/* 2015 Round 1A
 * Problem A
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

typedef vector<int> PlateVec;

bool doTest()
{
	int N;
	cin >> N;
	if ( N == 0 || N == 1 )
	{
		cout << "0 0";
		return true;
	}
	PlateVec plate;
	int p;
	for (int i=0; i<N; ++i)
	{
		cin >> p;
		plate.push_back(p);
	}
	int min_eat = 0;
	int const_rate = 0;
	for (int i=0; i<(N-1); ++i)
	{
		int diff = plate[i] - plate[i+1];
		if ( diff > 0 )
			min_eat += diff;
		if ( diff > const_rate )
			const_rate = diff;
	}
	int const_eat = 0;
	for (int i=0; i<(N-1); ++i)
	{
		int total_eaten = min(const_rate,plate[i]);
		const_eat += total_eaten;
	}
	cout << min_eat << " " << const_eat;
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
