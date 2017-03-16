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
#include <sstream>
#include <cstring>
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
#define forIter(I,C) for( auto I : (C) )
#define forNF(I,S,C) for( int I=(S); I<int(C); ++I )
#define forN(I,C) forNF(I,0,C)
#define forEach(I,C) forN(I,(C).size())
typedef long long i64; typedef unsigned long long u64; typedef unsigned u32;
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<string> VS;
typedef vector<u32> VU;

size_t line_number;
void check_space(const string& s) { for ( auto c : s ) assert(isspace(c&255)); }
void input_error() {
    cerr << "Input failed at line " << line_number << endl; exit(1);
}
string get_str(istream& in) {
    string ret; ++line_number; if ( !getline(in, ret) ) input_error(); return ret;
}
istream& skip_endl(istream& in) { check_space(get_str(in)); return in; }
istream& skip_eof(istream& in) { string s;
    while ( ++line_number, getline(in, s) ) check_space(s);
    if ( !in.eof() ) input_error(); return in;
}

map<string, int> str_index;
int get_index(const string& s) {
    return str_index.insert(make_pair(s, str_index.size())).first->second;
}
inline int get_str_index(istream& in) { return get_index(get_str(in)); }


/////////////////////////////////////////////////////////////////////////////

const int INF = 999999999;

const u32 MAX_B = 1024;
u32 N, B;
u32 mm[MAX_B];

u64 calc(u64 t)
{
    u64 k = 0;
    forN ( b, B ) {
        u64 c = t/mm[b]+1;
        k += c;
        if ( k > N ) break;
    }
    return k;
}


int num_cases = 1, part_cases = 0;
int main(int argc, const char** argv)
{
    cin >> num_cases >> skip_endl;
    if ( argc == 2 ) {
        part_cases = atoi(argv[1]);
    }
    forN ( nc, num_cases ) {
        // parse input
        cin >> B >> N >> skip_endl;
        forN ( b, B ) cin >> mm[b];
        cin >> skip_endl;
        
        // error check
        if ( !cin ) input_error();
        // main code

        u64 tt[1024];
        forN ( i, B ) tt[i] = 0;
        if ( N > 2*B ) {
            u32 K = N-2*B;
            u64 a = 0, b = u64(N)*1000000;
            while ( a+1 < b ) {
                u64 m = (a+b)/2;
                if ( calc(m) > K ) {
                    b = m;
                }
                else {
                    a = m;
                }
            }
            K = 0;
            forN ( b, B ) {
                u64 c = a/mm[b]+1;
                tt[b] = c*mm[b];
                K += c;
            }
            N -= K;
        }
        u32 result = 0;
        forN ( i, N ) {
            u32 b = 0;
            u64 t = tt[0];
            forNF ( j, 1, B ) {
                if ( tt[j] < t ) {
                    b = j;
                    t = tt[j];
                }
            }
            result = b;
            tt[b] += mm[b];
        }

        // output
        cout << "Case #"<<nc+1<<": ";
        cout << (result+1);
        cout << endl;
    }
    cin >> skip_eof;
}
