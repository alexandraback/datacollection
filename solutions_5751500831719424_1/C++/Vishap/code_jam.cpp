/* Check cf5-opt.vim defs.
VIM: let g:lcppflags="-std=c++11 -O2 -pthread"
VIM: let g:wcppflags="/O2 /EHsc /DWIN32"
VIM: let g:cppflags=g:Iboost.g:Itbb
VIM: let g:ldflags=g:Lboost.g:Ltbb.g:tbbmalloc.g:tbbmproxy
VIM: let g:ldlibpath=g:Bboost.g:Btbb
VIM: let g:argv=""
*/

#include <assert.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <string>
#include <memory>
#include <functional>
#include <algorithm>
#include <utility>
#include <limits>
#include <math.h>

typedef long long i64;
typedef std::vector<i64> vec;
void check( bool b ) { 	if ( !b ) 
	std::cerr << "error" << std::endl; }
#define FOR(i,l) for ( i64 i =0, ie = i64(l); i<ie; ++i )
/*
	Read n values into v
*/
template <class V>
void readv( V& v, int n )
{
	v.reserve(n);
	for ( int i = 0; i < n; ++i )
	{
		typename V::value_type e;
		std::cin >> e;
		check( !std::cin.fail() );
		v.push_back(e);
	}
}


std::string solve_puzzle()
{
	int n;
	std::cin >> n;

	std::vector<std::string> v;
	readv( v, n);

	std::vector<int> i(n,0);
	std::vector<int> r(n,0);

	int m = 0;
	while ( true )
	{
		if ( i[0] < v[0].size() )
		{
			int c = v[0][i[0]];
			FOR( j, n )
			{
				r[j] = 0;
				while ( i[j]<v[j].size() && c == v[j][i[j]] )
				{
					i[j]++;
					r[j]++;
				}
				if ( r[j] == 0 )
					return "Fegla Won";
			}
		}
		else
		{
			FOR( j, n )
			{
				if ( i[j]<v[j].size() )
					return "Fegla Won";
			}
			break;
		}

		std::sort(r.begin(),r.end());
		int am = 1000000;
		for ( int a = r.front(); a <= r.back(); a++ )
		{
			int s = 0;
			FOR(b,n)
			{
				s += abs(r[b]-a);
			}
			am = std::min(s,am);
		}
		m += am;
	}

	std::stringstream ss;
	ss << m;
	return ss.str();
}

#undef int
int main ( void )
{try{
	srand((unsigned)time(NULL));
	int puzzle_count;

	std::cin >>	puzzle_count;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	for ( int i = 1; i <= puzzle_count; i++ )
	{
		std::cout << "Case #" << i << ": ";
		auto r = solve_puzzle();
		std::cout << r << std::endl;
	}

	return 0;
}
catch ( const std::exception& e )
{
	std::cerr << std::endl
			<< "std::exception(\"" << e.what() << "\")." << std::endl;
	return 2;
}
catch ( ... )
{
	std::cerr  << std::endl
			<< "unknown exception." << std::endl;
	return 1;
}}
