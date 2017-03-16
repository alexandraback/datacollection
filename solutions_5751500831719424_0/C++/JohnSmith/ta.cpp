//
// 2014 round 1b problem A
//
// John Smith
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef pair<unsigned int,unsigned int> pii;

string remove_duplicates( string s )
{
     string t;
     char c0 = '#';
     for (auto c : s)
     {
	  if (c != c0)
	  {
	       t += c;
	       c0 = c;
	  }
     }
     return t;
}

int abs( int x )
{
     if (x<0) return -x;
     return x;
}

int get_moves( vector<unsigned int> v )
{
     unsigned int lo = *min_element(v.begin(), v.end());
     unsigned int hi = *max_element(v.begin(), v.end());
     unsigned int j;

     unsigned int s0 = 1000000000;

     for (j=lo; j<=hi; j++)
     {
	  unsigned int s=0;
	  for (auto x : v)
	  {
	       s += abs((int)(j-x));
	  }
	  if (s < s0) s0=s;
     }

     return s0;
}

unsigned int count_chars( string s, unsigned int k )
{
     char c0 = '#';
     unsigned int n=0;
     k++;
     for (auto c : s)
     {
	  if (c != c0)
	  {
	       k--;
	       c0 = c;
	  }
	  if (k==0) n++;
     }
     return n;
}

int solve( vector<string> v )
{
     vector<string> w;
     for (auto s : v) w.push_back(remove_duplicates(s));

     for (unsigned int i=1; i<w.size(); i++)
     {
	  if (w.at(i) != w.at(0)) return -1;
     }

     unsigned int r = remove_duplicates(v.at(0)).size();

     unsigned int s=0;
     unsigned int i;
     for (i=0; i<r; i++)
     {
	  vector<unsigned int> w;
	  for (auto s : v)
	  {
	       w.push_back(count_chars(s,i));
	  }
	  
	  s += get_moves(w);
     }

     return s;     
}


int main( int argc, char ** argv )
{
     unsigned int n;
     unsigned int i;

     cin >> n;

     for (i=1; i<=n; i++) 
     {
	  unsigned int N;

	  cin >> N;
	  
	  vector<string> v(N);

	  for (auto &s : v) cin >> s;

	  int e1 = solve(v);

	  reverse(v.begin(), v.end());

	  int e2 = solve(v);

	  if (e1 != e2) {
	       cout << "Error!!" << endl;
	       return 1;
	  }

	  cout << "Case #" << i << ": ";
	  if (e1 == -1)
	  {
	       cout << "Fegla Won";
	  }
	  else
	  {
	       cout << e1;
	  }
	  cout << endl;
     }

     return 0;
}
