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
void input_error(const char* msg = 0) {
    cerr << "Input failed at line " << line_number;
    if ( msg ) cerr << ": " << msg;
    cerr << endl; exit(1);
}
void check_space(const string& s) {
    for ( auto c : s ) {
#ifdef HOME_RUN
        if ( !isspace(c&255) ) input_error("not a space");
        assert(isspace(c&255));
#endif
    }
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

const u32 MAX_N = 4096;
u32 N;

/////////////////////////////////////////////////////////////////////////////
typedef i64 Coord;
typedef pair<Coord, Coord> Point;
typedef vector<Point> VP;
int _;
#define x first
#define y second

// Point operators
inline Point operator+(Point p1, Point p2)
{
    return Point(p1.x+p2.x, p1.y+p2.y);
}
inline Point operator-(Point p1, Point p2)
{
    return Point(p1.x-p2.x, p1.y-p2.y);
}
inline Point operator-(Point p)
{
    return Point(-p.x, -p.y);
}
inline Point operator*(Point p, Coord n)
{
    return Point(p.x*n, p.y*n);
}
inline Point operator/(Point p, Coord n)
{
    return Point(p.x/n, p.y/n);
}
inline Coord operator*(Point v1, Point v2)
{
    return v1.x*v2.x+v1.y*v2.y;
}
inline Coord operator/(Point v1, Point v2)
{
    return v1.x*v2.y-v1.y*v2.x;
}

// fast convex hull
struct ByArg // sort by angle around center point o
{
    ByArg(Point o_) : o(o_) {}
    Point o;
    inline bool operator()(Point a, Point b) const
    {
        a = a-o; b = b-o;
        if ( a/b ) return a/b < 0;
        return a*a < b*b;
    }
};
VP convexhull(VP p)
{
     VP ret;
     if ( !p.empty() ) {
         swap(p[0], *min_element(ALL(p)));
         sort(ALL(p), ByArg(p[0]));
         for ( size_t i = 0; i < p.size(); ++i ) {
             while ( ret.size() > 1 ) {
                 const Point& r = *(ret.end()-2);
                 if ( (ret.back()-r)/(p[i]-r) < 0 )
                     break;
                 ret.pop_back();
             }
             ret.push_back(p[i]);
         }
     }
     return ret;
}

int rr[MAX_N];
VP pp, cc;

int calc(int s)
{
    if ( N <= 1 ) return 0;
    int r = N;
    forN ( i, N ) {
        int c1 = 0, c2 = 0;
        if ( i == s ) continue;
        forN ( j, N ) {
            if ( j == i || j == s ) continue;
            Coord d = (pp[j]-pp[s])/(pp[i]-pp[s]);
            if ( d < 0 ) ++c1;
            if ( d > 0 ) ++c2;
        }
        r = min(r, min(c1, c2));
    }
    return r;
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
        cin >> N >> skip_endl;
        pp.resize(N);
        forN ( b, N ) cin >> pp[b].x >> pp[b].y >> skip_endl;
        //cin >> skip_endl;
        
        // error check
        if ( !cin ) input_error();
        // main code

        cc = convexhull(pp);
        //TR(pp|cc);

        forN ( i, N ) rr[i] = calc(i);

        // output
        cout << "Case #"<<nc+1<<":\n";
        forN ( i, N ) cout << rr[i] << endl;
        //cout << endl;
    }
    cin >> skip_eof;
}
