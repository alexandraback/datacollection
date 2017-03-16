#include <assert.h>

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>

#include <string>

#include <vector>
#include <list>

#include <bitset>
#include <valarray>

#include <algorithm>
#include <cmath>

#include <assert.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstddef>  // std::size_t
#include "cstdio"
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <fstream>
// #include <gmpxx.h>
#include <iomanip>
#include <iostream>
#include <list>
#include "map"
#include <math.h>
#include "numeric"
#include "queue"
#include "set"
#include <string>         // std::string
#include <sys/stat.h>
#include <sys/types.h>
#include "utility"
#include <valarray>
#include <vector>
#include <functional>

using namespace std;

inline bool fexists (const string& fname){  struct stat buffer;  return (stat (fname.c_str(), &buffer) == 0); }

long int N; // , M, X, Y; 
// int a, b, c;
int i, j, k;
// int x, y, z;

typedef pair<char, short> P; 
typedef vector < P > S;

vector < S > v;

     int count( const vector<int>& m, int r)
       {
	  const int S = m.size();
	  int d = 0;
	  for( int i = 0; i < S; i++ )
	     d += abs(m[i] - r);
#ifndef NDEBUG    
    cerr << "count: " << r << " => " << d << endl;
#endif  
	  return d;
       }
     
int getmin( vector<int>& m, int s)
       {
	  const int S = m.size();
	  
	  int a = s / S;
	  int d = count(m, a); int dp, dm;
	  
	  while( (dp = count(m, a+1)) < d) { d = dp; a++; } ;
	  while( (dm = count(m, a-1)) < d) { d = dm; a--; } ;
//	  int dm= count(m, a-1);
// 	  if( dp < d )
// 	  
	  return d;
       }

     

int main(int ac, char** av)
{
  std::ifstream f;
  std::ofstream g;

  if ( ac >= 2 )
  {
    assert( fexists(string(av[1])) );
    f.open(av[1], ios::in);
#ifndef NDEBUG    
    cerr << "INPUT from: " << av[1] << endl;
#endif  
    assert( f.is_open() );

    if( ac >= 3 )
    {
//      assert( fexists(string(av[2])) );
      g.open(av[2], ios::out | ios::trunc);
#ifndef NDEBUG    
      cerr << "OUTPUT to: " << av[2] << endl;
#endif  
      assert( g.is_open() );
    }
    
  } else
  {
    string n(av[0]); // n += ".in";
    
    if( fexists(n + ".in") )
    {
      string nn = n + ".in";
      string nnn = n + ".out";
#ifndef NDEBUG    
      cerr << "INPUT from: " << nn << endl;
      cerr << "OUTPUT to: " << nnn << endl;
#endif  
      f.open(nn.c_str(), ios::in);
      assert( f.is_open() );

      g.open(nnn.c_str(), ios::out | ios::trunc);
      assert( g.is_open() );
    }
  }

#ifndef NDEBUG
  if (!f.is_open())
    cerr << "INPUT from console input stream..." << endl;
  
  if (!g.is_open())
    cerr << "OUTPUT to console output stream..." << endl;
#endif  
  
  istream &in = (f.is_open()) ? f : cin;
  ostream &out = (g.is_open()) ? g : cout;
  
  ////////////////////////////////////////////////////////////////////////////
  
  long int T;  string str; 

  in >> T; getline(in, str); assert( 1 <= T && T <= 100 );

  for (int testcase = 1; testcase <= T; testcase++ )
  {
    out << "Case #" << testcase << ": "; // ' '?!

    in >> N; getline(in, str); assert( 1 <= N && N <= 100 );

    v.clear(); v.resize(N); // list<?> // ?????????????

    int s = 0;
    for (k = 0; k < N ; k++ ) 
    {
      string a; 
//      in >> a; assert( 0 <= a && a <= N ); // ?!
      getline(in, a);
       assert( 1 <= a.size() && a.size() <= 100 ); // ?!

#ifndef NDEBUG
       cerr << "a: " << a << endl;
#endif
      S w; // (a.size());
      char c = a[0]; short n = 1; i = 1; // j = 0;
      while (i < a.size() )
	 {
	    if (a[i] == c ) n++;
	    else
	      {
		 w.push_back( make_pair(c, n) );
		 c = a[i]; n = 1;
	      }
	    i++;
	 }
       
       w.push_back(  make_pair(c, n) );
       
       

      //	v.resize(?);
      w.shrink_to_fit();
      if( w.size() > s ) s = w.size(); 
      // sort(v.begin(), v.end()); // ?

      v[k] = w;       //  v.push_front(a); // list! // ???
    }

    assert( v.size() == N  );
     int _m;
     
#ifndef NDEBUG    
/*    cerr << endl;
	  cerr << "w(max): "; //  << v[k] << endl;
	  for( i = 0; i < S; i++ )
	    cerr << "[" << w[i].first << "^" << w[i].second <<"]";
	  cerr << endl;
*/    cerr << endl;
    for( k = 0; k < N; k++ )
       {
	  cerr << "v[" << k << "]: "; //  << v[k] << endl;
	  for( i = 0; i < v[k].size() ; i++ )
	    cerr << "[" << v[k][i].first << "^" << v[k][i].second <<"]";
	  cerr << endl;
       }     
#endif

     const int S = v[0].size();
     vector < vector<int> > mmm(S, vector<int>(N,0));
      vector<int> sum(S,0);
     
     for ( j = 0; j < N; j++ )
       {
	  if( S !=  v[j].size() )
	    goto bad;
	  
//	  mmm[j].resize(N, 0);
	  
	  for( i = 0; i < S; i++ )
	    {
	       
	       if( v[j][i].first != v[0][i].first )
		 goto bad;
	       
	       mmm[i][j] = v[j][i].second;
	       sum[i] += mmm[i][j];
	    }  
       }
     
     
     _m = 0;
     
     for ( j = 0; j < S; j++ )
	  _m += getmin( mmm[j], sum[j]);
     
     out << _m;
     
     goto nexttest;
     
//    vector <char> result(N, _F);
//    while (! v.empty())   a = v.front();    v.pop_front(); // list
//    while (! v.empty())   a = v.back();     v.pop_back();
//          vector<?>::iterator it = find( v.begin(), v.end(), a); assert( it != v.end()); assert( (*it) == a );
//          a.erase(it);
//          for( vector<?>::iterator it = v.begin(); it != v.end(); it ++ ) a = *it;
//          assert( find( v.begin(), v.end(), a ) != v.end() );


    // we are finished...
    // check?!
//    for ( i = 0; i < N; i++ )
//      out << ' ' << ((result[i] != _F) ? result[i] : UF );
bad: 
	  out << "Fegla Won";

nexttest:
    // cleanup
//    while (!todo.empty())
//    {
//      assert( todo.back()->_u.size() > 0 );
//      if (todo.back() != NULL)
//        delete (todo.back());
//      todo.pop_back();
//    }


    out << endl;
  }; // main loop !!!
  
  ////////////////////////////////////////////////////////

  if (f.is_open()) f.close();
  if (g.is_open()) g.close();
  
  return 0;
}


/*
// typedef pair<short,char> S;
// const char _F = '?';
struct  Row
{ 
  vector<short> _u;   //  bitset<2000>
  short _m; // -1 means undefined or unset

  Row() : _u(), _m(-1) {};

  Row(vector<short> uu, short mm = -1 ):_u(uu), _m(mm)
  {
  }

  Row(int T): _u(), _m(-1)
  {
    _u.reserve(T);
  }

  inline void init(vector<short> uu, short mm = -1 )
  {
    _u = uu; _m = mm;
  }
};
// typedef vector<Row*> Col;
inline ostream & operator<< (ostream &o, const Row &e)
{
  o << "[ ";
  for( int i = 0; i < e._u.size(); ++i)
    o << e._u[i] << " ";

  return o << "| " << e._m << " ]";
}
*/

/*

typedef pair<short,int> S; 

bool Scmp (const S& i, const S& j) 
{
    return (i.first < j.first); 
}
sort(V.begin(), V.end(), Scmp);


*/
