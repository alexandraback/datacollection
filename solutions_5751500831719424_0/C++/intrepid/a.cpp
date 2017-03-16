/* CodeJam 2014
 * Round 1B
 * Problem A
 * intrepid
 */
#include <cassert>
#include <iostream>
#include <sstream>
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

struct StringState
{
	StringState() :
		value(),
		pos(0),
		at_pos(0),
		run_len(0)
	{
	}
	
	string value;
	size_t pos;
	char at_pos;
	size_t run_len;
	size_t length;
};

typedef vector<StringState> Strings;

int get_run(StringState& ss)
{
	char a = ss.at_pos;
	size_t i = ss.pos;
	while ( i < ss.length && ss.value[i] == a) ++i;
	
	int runLength = i - ss.pos;
	ss.pos = i;
	ss.at_pos = (( i < ss.length ) ? ss.value[i] : 0);
	return runLength;
}

bool doTest()
{
	int N;
	cin >> N;
	
	Strings strings(N);
	std::string input;
	for (int i=0; i<N; ++i)
	{
		cin >> input;
		strings[i].at_pos = input[0];
		strings[i].length = input.size();
		strings[i].value = move(input);
	}
	if ( ! cin.good() )
		return false;
	
	bool finished = false;
	bool possible = true;
	int num_moves = 0;
	vector<int> lengths(N);
	while ( ! finished )
	{
		char target = strings[0].at_pos;
		bool is_end = ( target == 0 );
		for (int i=0; i<N; ++i)
		{
			StringState& ss = strings[i];
			if ( ss.at_pos != target )
			{
				possible = false;
				break;
			}
			lengths[i] = get_run(ss);
		}
		if ( is_end ) break;
		sort(lengths.begin(), lengths.end());
		int med = lengths[N/2];
		int dist = 0;
		for ( int length : lengths )
			dist += ( (length < med) ? (med - length) : (length - med) );
		num_moves += dist;
	}
	
	if ( possible )
		cout << num_moves;
	else
		cout << "Fegla Won";
	
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
