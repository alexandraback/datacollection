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
//ostream & out = cout;
ofstream out( "a.out" );

int main() {
    int ntests;
    in >> ntests;
    for (int test = 1; test <= ntests; ++test) {
        int n;
        in >> n;
        vs str(n);
        for (int i = 0; i < n; ++i) 
            in >> str[i];
        string pat = str[0];
        pat.erase(unique(all(pat)), pat.end());
        vvi v(n);
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            string cur = str[i];
            cur.erase(unique(all(cur)), cur.end());
            if (cur != pat) {
                valid = false;
                break;
            }
            int cnt = 1;
            for (int j = 1; j < str[i].size(); ++j) {
                if (str[i][j] != str[i][j-1]) {
                    v[i].push_back(cnt);
                    cnt = 1;
                } else
                    ++cnt;
            }
            v[i].push_back(cnt);
        }
        int res = 0;
        if (valid) {        
            for (int j = 0; j < pat.size(); ++j) {
                int sum = 0;
                for (int i = 0; i < n; ++i) {
                    sum += v[i][j];
                }
                int avg = round(1. * sum / n);
                for (int i = 0; i < n; ++i) {
                    res += abs(avg - v[i][j]);
                }
            }
        }
        out << "Case #" << test << ": ";
        if (valid)
            out << res;
        else
            out << "Fegla Won";
        out << "\n";
    }
    return 0;
}