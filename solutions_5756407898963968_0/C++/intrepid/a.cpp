/* Round 1C
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

typedef set<int> Row;

Row getRow(int row_no)
{
	Row return_value;
	
	int throw_away_before = 4 * ( row_no - 1 );
	int throw_away_after = 4 * ( 4 - row_no );
	
	assert( throw_away_before + throw_away_after == 12 );
	
	int scratch;
	for (int i=0; i<throw_away_before; ++i) cin >> scratch;
	for (int i=0; i<4; ++i)
	{
		cin >> scratch;
		return_value.insert(scratch);
	}
	for (int i=0; i<throw_away_after; ++i) cin >> scratch;
	
	return return_value;
}

bool doTest()
{
	int first_row_no;	
	cin >> first_row_no;
	assert( first_row_no > 0 && first_row_no < 5 );
	
	Row first_row_contents = getRow(first_row_no);
	if ( ! cin.good() ) return false;
	
	int second_row_no;
	cin >> second_row_no;
	assert( second_row_no > 0 && second_row_no < 5 );
	
	Row second_row_contents = getRow(second_row_no);
	if ( ! cin.good() ) return false;
	
	Row row_intersection;
	set_intersection(
		first_row_contents.begin(), first_row_contents.end(),
		second_row_contents.begin(), second_row_contents.end(),
		inserter(row_intersection, row_intersection.begin())
	);
	
	size_t num_possible = row_intersection.size();
	if ( num_possible == 0 )
	{
		cout << "Volunteer cheated!";
	}
	else if ( num_possible == 1 )
	{
		cout << *row_intersection.begin();
	}
	else
	{
		cout << "Bad magician!";
	}
	
	return true;
}

int main(int /*argc*/, char **/*argv[]*/)
{
	cout << scientific << setprecision(6);
	int runs;
	cin >> runs;
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
