#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#pragma warning( disable : 4244 4267 4018 4996 4800 )
//#pragma comment( linker, "/stack:10000000" )
using namespace std; 
typedef vector< int > vi; typedef vector< vector< int > > vvi; typedef vector< string > vs; typedef vector< double > vd;
typedef vector< vd > vvd; typedef long long ll; typedef vector< ll > vll; typedef vector< vll > vvll; typedef pair< int, int > pii;
#define all( v ) (v).begin( ), (v).end( )

ifstream in( "b.in" );
ofstream out( "b.out" );

int bit_count( int i ) {
    i = i - ((i >> 1) & 0x55555555 );
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    i = (i + (i >> 4)) & 0x0f0f0f0f;
    i = i + (i >> 8);
    i = i + (i >> 16);
    return i & 0x3f;
}

int main() {
    int ntests;
    in >> ntests;
    for (int test = 1; test <= ntests; ++test) {
        int r, c, n;
        in >> r >> c >> n;
        int total = r * c;
        int best = total * 2;
        for (int i = 0; i < (1 << total); ++i) {
            if (bit_count(i) != n)
                continue;
            int current = 0;
            for (int j = 0; j < total; ++j) if (i & (1 << j)) {
                if (j % r != r - 1 && (i & (1 << (j + 1)))) {
                    ++current;
                }
                if (j / r != c - 1 && (i & (1 << (j + r)))) {
                    ++current;
                }
            }
            best = min(best, current);
        }
        out << "Case #" << test << ": " << best << "\n";
    }
    return 0;
}