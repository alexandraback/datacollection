/* Check cf5-opt.vim defs.
VIM: let g:lcppflags="-std=c++11 -O2 -pthread"
VIM: let g:wcppflags="/O2 /EHsc /DWIN32"
VIM: let g:cppflags=g:Iboost.g:Itbb
VIM: let g:ldflags=g:Lboost.g:Ltbb.g:tbbmalloc.g:tbbmproxy
VIM: let g:ldlibpath=g:Bboost.g:Btbb
VIM: let g:argv=" < tic_tac_toy_tomek.sample_input"
*/
#include <iostream>
#include <exception>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

typedef std::vector<int> arrangement_type;
struct puzzle_type
{
	arrangement_type arr1;
	arrangement_type arr2;
	int ans1;
	int ans2;
};

void read_puzzle( puzzle_type& puzzle )
{
	puzzle.arr1.clear();
	puzzle.arr2.clear();
	//
	// arrangement 1
	//
	std::cin >> puzzle.ans1;
	for ( int i = 0; i < 16; ++i )
	{
		int c;
		std::cin >> c;
		puzzle.arr1.push_back(c);
	}
	//
	// arrangement 2
	//
	std::cin >> puzzle.ans2;
	for ( int i = 0; i < 16; ++i )
	{
		int c;
		std::cin >> c;
		puzzle.arr2.push_back(c);
	}
}

int solve_puzzle( puzzle_type& puzzle )
{
	arrangement_type::iterator r1b = puzzle.arr1.begin() + (puzzle.ans1-1)*4;
	arrangement_type::iterator r1e = r1b+4;
	std::sort(r1b,r1e);

	arrangement_type::iterator r2b = puzzle.arr2.begin() + (puzzle.ans2-1)*4;
	arrangement_type::iterator r2e = r2b+4;
	std::sort(r2b,r2e);

	int ans;
	int cnt = 0;
	while ( r1b != r1e && r2b != r2e )
	{
		if ( *r1b < *r2b )
			++r1b;
		else if ( *r1b > *r2b )
			++r2b;
		else //if ( *r1b == *r2b )
		{
			ans = *r1b;
			cnt++;
			++r1b;
			++r2b;
		}
	}

	if ( cnt > 1 )
		return -1;
	else if ( cnt == 0 )
		return -2;
	else
		return ans;
}

const char * msg [] = {
		"Bad magician!",
		"Volunteer cheated!"
};

int main ( void )
{try{

	int puzzle_count;
	puzzle_type puzzle;

	std::cin >>	puzzle_count;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	for ( int i = 0; i < puzzle_count; i++ )
	{
		read_puzzle(puzzle);
		int s = solve_puzzle(puzzle);
		if ( s >= 0 )
			std::cout << "Case #" << (i+1) << ": " << s << std::endl;
		else
			std::cout << "Case #" << (i+1) << ": " << msg[-s-1] << std::endl;
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

