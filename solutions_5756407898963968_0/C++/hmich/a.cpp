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

#ifdef LOCAL
ifstream in( "a.in" );
#else
istream & in = cin;
#endif
ofstream out( "a.out" );

void read(int & r, vi & row, vi & col) {
    in >> r;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            int t;
            in >> t;
            row[t] = i;
            col[t] = j;
        }
    }    
}

int main() {
    int ntests;
    in >> ntests;
    for (int test = 1; test <= ntests; ++test) {
        int r1, r2;
        vi row1, col1, row2, col2;
        row1 = col1 = row2 = col2 = vi(17);
        read(r1, row1, col1);
        read(r2, row2, col2);
        int last = -1;
        for (int i = 1; i <= 16; ++i) {
            if (row1[i] == r1 && row2[i] == r2) {
                if (last == -1)
                    last = i;
                else if (last > 0)
                    last = -2;
            }
        }
        out << "Case #" << test << ": ";
        if (last == -1)
            out << "Volunteer cheated!";
        else if (last == -2)
            out << "Bad magician!";
        else
            out << last;
        out << "\n";
    }
    return 0;
}