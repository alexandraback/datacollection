#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
//#include <gmp.h>
#ifdef HOME_RUN
# include <debug.hpp>
# include <dump.hpp>
# include <cassert>
#else
# define TR(x) do{}while(0)
# ifdef assert
#  indef assert
# endif
# define assert(x) do{}while(0)
#endif
using namespace std;

#define ALL(C) (C).begin(), (C).end()
#define forIter(I,C) for(auto I=(C).begin(); I!=(C).end(); ++I)
#define forNF(I,S,C) for(int I=(S); I<int(C); ++I)
#define forN(I,C) forNF(I,0,C)
#define forEach(I,C) forN(I,(C).size())
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef long long i64;
typedef unsigned long long u64;

inline istream& skip_endl(istream& in)
{
    string s;
    getline(in, s);
    forIter( i, s ) assert(isspace(*i&0xff));
    return in;
}

inline string get_str()
{
    string ret;
    getline(cin, ret);
    return ret;
}

map<string, int> str_index;
int get_index(const string& s)
{
    return str_index.insert(make_pair(s, str_index.size())).first->second;
}
int get_str_index()
{
    return get_index(get_str());
}


int b[4][44];

int num_cases = 1, part_cases = 0;
int main(int argc, const char** argv)
{
    cin >> num_cases >> skip_endl;
    if ( argc == 2 ) part_cases = atoi(argv[1]);
    forN ( nc, num_cases ) {
	// parse input
	int r1, r2;
	cin >> r1 >> skip_endl;
	forN ( r, 4 ) {
	    forN ( c, 4 ) cin >> b[r][c];
	    cin >> skip_endl;
	}
	int b1 = 0;
	forN ( c, 4 ) b1 |= 1<<(b[r1-1][c]-1);
	cin >> r2 >> skip_endl;
	forN ( r, 4 ) {
	    forN ( c, 4 ) cin >> b[r][c];
	    cin >> skip_endl;
	}
	int b2 = 0;
	forN ( c, 4 ) b2 |= 1<<(b[r2-1][c]-1);
	   
	// error check
        if ( !cin ) {
            cout << "Error parsing input" << endl;
            return 1;
        }
        // main code

	const char* err = 0;
	int result = 0;
	int bb = b1&b2;
	if ( bb == 0 ) err = "Volunteer cheated!";
	else if ( bb&(bb-1) ) err = "Bad magician!";
	else result = __builtin_ctz(bb)+1;

        // output
        cout << "Case #"<<nc+1<<": ";
	if ( result )
	    cout << result;
	else
	    cout << err;
        cout << endl;
    }
}
