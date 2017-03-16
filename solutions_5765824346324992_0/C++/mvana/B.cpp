/* Copyright (c) 2015 Martin Váňa */

/* http://www.cplusplus.com/reference/ */
/* C Library */
// #include <cassert>           // Diagnostics Library
#include <cctype>            // Character handling functions
// #include <cfenv>             // Floating-point environment
#include <cfloat>            // Characteristics of floating-point types
// #include <cinttypes>         // C integer types - C++11 feature
#include <climits>           // Sizes of integral types
#include <cmath>             // C numerics library
// #include <cstdint>           // Integer types
#include <cstdio>            // C library to perform Input/Output operations
#include <cstdlib>           // C Standard General Utilities Library
#include <cstring>           // C Strings

/* Containers */
#include <array>             // Array header
#include <bitset>            // Bitset header
#include <deque>             // Deque header
// #include <forward_list>      // Forward list - C++11 feature
#include <list>              // List header
#include <map>               // Map header
#include <queue>             // Queue header
#include <set>               // Set header
#include <stack>             // Stack
#include <unordered_map>     // Unordered map header - C++11 feature
// #include <unordered_set>     // Unordered set header - C++11 feature
#include <vector>            // Vector header

/* Input/Output Stream Library */
// #include <fstream>           // File streams
#include <iostream>          // Standard Input / Output Streams Library
#include <sstream>           // String streams

/* Miscellaneous headers */
#include <algorithm>         // Standard Template Library: Algorithms
#include <complex>           // Complex numbers library
// #include <exception>         // Standard exceptions
// #include <functional>        // Function objects
// #include <initializer_list>  // Initializer list - C++11 feature
#include <iterator>          // Iterator definitions
// #include <limits>            // Numeric limits
// #include <numeric>           // Generalized numeric operations
// #include <random>            // Random - C++11 feature
// #include <ratio>             // Ratio header - C++11 feature
// #include <regex>             // Regular Expressions - C++11 feature
// #include <stdexcept>         // Exception classes
#include <string>            // Strings
// #include <tuple>             // Tuple library - C++11 feature
// #include <typeindex>         // Type index - C++11 feature
// #include <typeinfo>          // Type information
// #include <type_traits>       // Type traits - C++11 feature
// #include <utility>           // Utility components
// #include <valarray>          // Library for arrays of numeric values

using namespace std;

// Debug printing
#ifdef DEBUG
#define DBG(args...)                printf("DBG> ");printf(args);
#else
#define DBG(args...)                // Just strip off all debug tokens
#endif

// Printing
#define PR(args...)                 printf(args)

// Useful constants
#define STR_BUF                     256
#define INF                         INT_MAX
#define EPS                         1e-15
#define PI                          3.1415926535897932384626433832795

// Input macros
#define S(n)                        scanf("%d",&n)
#define SC(n)                       scanf("%c",&n)
#define SL(n)                       scanf("%lld",&n)
#define SF(n)                       scanf("%lf",&n)
#define SS(n)                       scanf("%s",n)

// For loops
#define F(i,L,U)                    for((i)=(L);(i)<(U);(i)++)
#define FE(i,L,U)                   for((i)=(L);(i)<=(U);(i)++)
#define RF(i,L,U)                   for((i)=(U);(i)>(L);(i)--)
#define RFE(i,L,U)                  for((i)=(U);(i)>=(L);(i)--)

// Containers
#define FOREACH(v,c)                for(v=(c).begin();v!=(c).end();++v)

// Checking bounds
#define IN(i,l,r)                   ((l)<(i)&&(i)<(r))
#define LINR(i,l,r)                 ((l)<=(i)&&(i)<=(r))
#define LIN(i,l,r)                  ((l)<=(i)&&(i)<(r))
#define INR(i,l,r)                  ((l)<(i)&&(i)<=(r))

// Bit operations
#define OR(a,b)                     ((a)|(b))
#define AND(a,b)                    ((a)&(b))
#define XOR(a,b)                    ((a)^(b))
#define BIT(x,i)                    ((x)&(1<<(i)))       //select the bit of position i of x
#define LBIT(x)                     ((x)&((x)^((x)-1)))  //get the lowest bit of x

// Some common useful functions
#define SIGN(x)                     ((x)>0)-((x)<0)
#define ABS(x)                      ((x)<0?(-(x)):(x))
#define MIN(a,b)                    (((a)<(b))?(a):(b))
#define MAX(a,b)                    (((a)>(b))?(a):(b))
#define REMAX(a,b)                  (a)=MAX((a),(b))      // set a to the maximum of a and b
#define REMIN(a,b)                  (a)=MIN((a),(b));
#define CB(n,b)                     (((n)>>(b))&1)
#define C2I(c)                      (c-'0')               // char to int
#define DROUND(num)                 (int)floor((num)+0.5) // Rounds num to int (int)num+(<.5 to 0, > .5 to 1)
#define IS_ODD(n)                   ((n)%2!=0)

// Variable definitions
#define DI(n)                       int n
#define DD(n)                       double n
#define DS(s,N)                     char s[N]
#define DIS(n)                      DI(n);S(n)

// Contest
#define TESTS                       DIS(_tc_no_);while(_tc_no_--)
#define CASES                       DIS(cases);DI(_case_);FE(_case_,1,cases)
#define LINE(line)                  fgets(line,sizeof(line),stdin)
#define LINE_BY_LINE(line)          while(LINE(line))
#define DEF_SEP_LINE                DI(_fline_);_fline_=1;   // separate test cases with blank line
#define SEP_LINE                    (_fline_==1)?_fline_=0:PR("\n")

// Arrays
#define CLR(a)                      memset(a,0,sizeof(a))  // set elements of array to some value
#define PRAI(i,a,L,R)               F(i,L,R){PR("%d ",a[i]);}PR("\n")
#define PRAF(i,a,L,R)               F(i,L,R){PR("%lf ",a[i]);}PR("\n")
#define PRAS(i,a,L,R)               F(i,L,R){PR("%s ",a[i]);}PR("\n")

// Colections
#define ALL(c)                      (c).begin(), (c).end()
#define PB                          push_back

// Data types
#define LL                          long long
#define ULL                         unsigned long long
#define UI                          unsigned int
#define US                          unsigned short
#define II                          pair<int, int>
#define VII                         vector<II>
#define VI                          vector<int>

// Directions
const int D4[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int D8[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

// Problem complex structures and algorithms

// Problem specific data

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const vector<LL> &l, const vector<LL> &r)// 0 - Bk number, 1 - time, 2 - rtime
  {
      if (l[1] == r[1]){
          return l[0] > r[0];
      }
      return l[1] > r[1];
  }
};

LL gcd(LL a, LL b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

LL lcm(LL a, LL b)
{
    LL temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int btimes[1020];

int main( int argc, char *argv[] )
{
    int i,j,k, B,N,tmp,l;




    CASES
    {
        priority_queue<vector<LL>, vector<vector<LL>>, mycomparison> pq;

        S(B);S(N);
        F(i,0,B)
        {
            S(btimes[i]);
        }

        l = accumulate(btimes, btimes + B, 1, lcm);
        tmp = 0;
        F(i,0,B)
        {
            tmp += l/btimes[i];
        }

        DBG("N=%d lcm=%d Nmood %d nas %d\n",N,(int)l, N%((int)tmp + 1), tmp);

        N %= tmp;
        if (N == 0){
            N = tmp;
        }

        F(i,0,B)
        {
            vector<LL> v;
            v.PB(i);// number
            v.PB(0);// time
            v.PB(btimes[i]);// rtime
            pq.push(v);
        }

        tmp = 0;

        F(i,0,N)
        {
            vector<LL> v = pq.top();
            pq.pop();
            v[1] += v[2];
            tmp = (int) v[0];
            pq.push(v);
        }

        PR("Case #%d: %d\n",_case_,tmp + 1);
    }

    exit( EXIT_SUCCESS );
}
