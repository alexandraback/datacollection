#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

using namespace std;

#define ll          long long
#define VI          vector<int>
#define ALL(a)      (a).begin(), (a).end()
#define SORT(a)     sort( ALL(a) )
#define PB          push_back
#define FOR(i,a,b)  for( int i = (a); i < (int)(b); i++ )
#define dump_(x)     cerr << #x << " = " << (x) << " ";
#define dump(x)     cerr << #x << " = " << (x) << endl
#define dump_vec(x) FOR(zZz,0,x.size()) cout << x[zZz] << " "; cout << endl


template< typename type > type readOne()
{
  type res;
  char inp[5000];
  char* dum = fgets( inp, sizeof( inp ), stdin );
  stringstream ss( dum );
  ss >> res;
  return res;
}

template< typename type > vector<type> readMulti()
{
  vector<type> res;
  char inp[5000];
  char* dum = fgets( inp, sizeof( inp ), stdin );
  stringstream ss( dum );
  for ( type t; ss >> t; )
    res.push_back( t );
  return res;
}

//
//
// LET'S START
//
//

string doit(int N, vector<int> P) {
    stringstream ss;
    while (true) {
	int maxi = -1;
	int mini = -1;
	int max = -1;
	int min = 10000;
	int sum = 0;
	int kind = 0;
	for (int i = 0; i < N; i++) {
	    if (P[i] == 0) continue;
	    sum += P[i];
	    if (P[i] > 0)
		kind++;
	    if (P[i] > max) {
		max = P[i];
		maxi = i;
	    }
	    if (P[i] < min) {
		min = P[i];
		mini = i;
	    }
	}
	if (sum == 1) {
	    cerr << "WRONG!!!\n";
	    break;
	}
	if (sum == 0) {
	    break;
	}
	//	dump(max);
	//	dump(min);
	if (max > min) {
	    if (ss.str().size() > 0)
		ss << ' ';
	    ss << (char)('A' + maxi);
	    P[maxi]--;
	}
	else {
	    if (kind > 2) {
		P[mini] = 0;
		for (int j = 0; j < min; j++) {
		    if (ss.str().size() > 0)
			ss << ' ';
		    ss << (char)('A' + mini);
		}
	    }
	    else {
		vector<int> rems;
		for (int j = 0; j < N; j++) {
		    if (P[j] > 0)
			rems.push_back(j);
		}
		if (rems.size() != 2) {
		    cerr << "WRONG!!!!!\n";
		}
		for (int j = 0; j < max; j++) {
		    if (ss.str().size() > 0)
			ss << ' ';
		    ss << (char)('A' + rems[0]) << (char)('A' + rems[1]);
		}
		break;
	    }
	}
    }

    //
    
    return ss.str();
}

string doCase()
{
  //
  // DOIT!
  //
  int N = readOne<int>();
  vector<int> P = readMulti<int>();
  return doit(N, P);
}

int main()
{
  int cases = readOne<int>();
  for (int caseno = 1; caseno <= cases; caseno++)
    cout << "Case #" << caseno << ": " << doCase() << endl;
  return 0;
}

