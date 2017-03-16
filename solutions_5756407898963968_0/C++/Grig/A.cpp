#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <thread>
#include <mutex>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// globals
typedef string result_type;
const bool use_multi = false;
//


template<class T>
void read( T& container )
{
	for( typename T::value_type& x : container )
		cin >> x;
}

template<class T>
void print( T& container, const string& separator = " " )
{
	for( typename T::value_type& x : container )
		cout << x << separator;
}

void open_files( const char* in, const char* out )
{
	freopen( in, "r", stdin );
	freopen( out, "w", stdout );
}

struct solver
{
	// solution code here

   int input[ 2 ][ 4 ][ 4 ];
   int ans[ 2 ];

	solver() {}

	void read()
	{
      int t, i, j;
      for( t = 0; t < 2; ++t )
      {
         cin >> ans[ t ];
         --ans[ t ];
         for( i = 0; i < 4; ++i )
            for( j = 0; j < 4; ++j )
               cin >> input[ t ][ i ][ j ];
      }
	}

	result_type solve()
	{
      int i, j;
      int cnt = 0, num;
      for( i = 0; i < 4; ++i )
         for( j = 0; j < 4; ++j )
            if( input[ 0 ][ ans[ 0 ]][ i ] == input[ 1 ][ ans[ 1 ]][ j ] )
            {
               ++cnt;
               num = input[ 0 ][ ans[ 0 ]][ i ];
            }
      if( cnt == 1 )
         return to_string( num );
      else if( cnt == 0 )
         return "Volunteer cheated!";
      else
         return "Bad magician!";
	}
};


mutex result_locker;
vector<result_type> results;
vector<thread> threads;
vector<solver> solvers; // change this for result type

void run( int test_num )
{
	result_type res = solvers[ test_num ].solve();
	result_locker.lock();
	results[ test_num ] = res;
	result_locker.unlock();
}

void print_result( int test_num )
{
	cout << "Case #" << test_num + 1 << ": "; // default
	// print code here
   cout << results[ test_num ] << endl;
}

void process() 
{ 
   open_files( "a-small-0.in", "a-small-0.out" );

	// preparations
	int test_count;
	cin >> test_count;
	threads.resize( test_count );
	results.resize( test_count );
	solvers.resize( test_count );

	// input
	for( int i = 0; i < test_count; ++i )
		solvers[ i ].read();

	// detach threads if necessary
	if( use_multi )
	{
		for( int i = 0; i < test_count; ++i )
			threads[ i ] = thread( run, i );
		for( int i = 0; i < test_count; ++i )
			threads[ i ].join();
	}
	else
	{
		for( int i = 0; i < test_count; ++i )
			run( i );
	}
	for( int i = 0; i < test_count; ++i )
		print_result( i );
}

int main() { process(); return 0; }