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
const bool use_multi = true;
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
	solver() {}

   vector<string> v;
   int n;

	void read()
	{
      cin >> n;
      v.resize( n );
      for( auto& s : v )
         cin >> s;
	}

	result_type solve()
	{
      string pattern;
      pattern += v[ 0 ][ 0 ];

      vector<vector<int>> cnt( n );

      int i, j, t;
      int tmp = 1;
      for( i = 1; i < v[ 0 ].size(); ++i )
         if( v[ 0 ][ i ] != v[ 0 ][ i - 1 ] )
         {
            pattern += v[ 0 ][ i ];
            cnt[ 0 ].push_back( tmp );
            tmp = 1;
         }
         else
            ++tmp;
      cnt[ 0 ].push_back( tmp );

      for( i = 1; i < n; ++i )
      {
         j = 1;
         if( v[ i ][ 0 ] != pattern[ 0 ] )
            break;
         tmp = 1;
         for( t = 1; t < v[ i ].size(); ++t )
            if( v[ i ][ t ] != v[ i ][ t - 1 ] )
            {
               if( j == pattern.size())
                  break;
               if( v[ i ][ t ] != pattern[ j ] )
                  break;
               else
               {
                  cnt[ i ].push_back( tmp );
                  ++j;
                  tmp = 1;
               }
            }
            else
               ++tmp;

         cnt[ i ].push_back( tmp );

         if( t < v[ i ].size() || j != pattern.size() )
            break;
      }

      if( i < n )
         return "Fegla Won";

      int res = 0, half;
      int k = cnt[ 0 ].size();

      for( j = 0; j < k; ++j )
      {
         vector<int> tt;
         for( i = 0; i < n; ++i )
            tt.push_back( cnt[ i ][ j ] );
         sort( tt.begin(), tt.end());
         half = tt.size() / 2;
         for( i = 0; i < n; ++i )
            res += abs( tt[ i ] - tt[ half ] );
      }

		return to_string( res );
	}
};


mutex result_locker;
vector<result_type> results;
vector<thread> threads;
vector<solver> solvers;

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
   open_files( "a-small-2.in", "a-small-2.out" );

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