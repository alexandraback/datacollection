//
// Round 1a 2015  problem C
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <gmpxx.h>

#include <cstdlib>
#include <math.h>

using namespace std;

int64_t tri( pair<int,int> p1,
	     pair<int,int> p2,
	     pair<int,int> p3 )
{
     int64_t dx1 = p2.first  - p1.first;
     int64_t dy1 = p2.second - p1.second;
     int64_t dx2 = p2.first  - p3.first;
     int64_t dy2 = p2.second - p3.second;

     return dx1*dy2 - dy1*dx2;
}

uint64_t dist( pair<int,int> p1,
	       pair<int,int> p2 )
{
     int64_t dx = p1.first - p2.first;
     int64_t dy = p1.second - p2.second;

     return dx*dx+dy*dy;
}

vector<unsigned int> boundary( vector<pair<int,int> > &v )
{
     if (0)
     {
	  cerr << "Boundary of " << endl;
	  for (auto p : v)
	  {
	       cerr << setw(5) << p.first << "," << setw(5) << p.second << endl;
	  }
     }
     unsigned int i0=0;
     for (auto i=1u; i<v.size(); i++)
     {
	  if (v.at(i).first > v.at(i0).first ||
	      (v.at(i).first == v.at(i0).first &&
	       v.at(i).second > v.at(i0).second))
	  {
	       i0 = i;
	  }
     }

     vector<unsigned int> a;
     unsigned int i=i0;
     do {
	  a.push_back(i);

	  auto pi = v.at(i);

	  unsigned int jj = (i==0) ? 1 : 0;
	  set<unsigned int> s;
	  s.insert(jj);
	  auto pjj = v.at(jj);
	  for (auto j=0u; j<v.size(); j++)
	  {
	       if (j != i && j != jj)
	       {
		    auto pj = v.at(j);
		    int64_t t = tri( pi, pj, pjj );

		    if (t < 0)
		    {
			 s.clear();
			 s.insert(j);
			 jj = j;
			 pjj = pj;
		    }
		    else if (t == 0)
		    {
			 s.insert(j);
		    }
	       }
	  }
	  
	  if (s.size() < 1)
	  {
	       cerr << "Failed to find next point" << endl;
	       abort();
	  }
	  //cerr << "s.size() = " <<s.size() << endl;
	  while (s.size() != 1)
	  {
	       //for (auto u : s) cerr << u << " " ; cerr << endl;
	       vector<unsigned int> ww;
	       for (auto u : s) ww.push_back(u);
	       unsigned int k = 0;
	       int64_t d = dist( pi, v.at(ww.at(k)));
	       for (auto kk=1u; kk<ww.size(); kk++)
	       {
		    int64_t dd = dist( pi, v.at(ww.at(kk)));
		    if (dd < d) { dd = d; k = kk; }
	       }
	       a.push_back(ww.at(k));
	       s.erase(ww.at(k));
	  }
			 
	  if (s.size() == 1)
	  {
	       i = *s.begin();
	  }

     } while (i != i0);

     return a;
}

vector<unsigned int> solve( vector<pair<int,int> >v)
{
     if (v.size() <= 3)
     {
	  vector<unsigned int> a;
	  for (auto i=0u; i<v.size(); i++) a.push_back(0);
	  return a;
     }

     if (0)
     {
	  vector<unsigned int> b = boundary(v);

	  for (auto i : b) 
	  {
	       cout << setw(6) << v.at(i).first << " ";
	       cout << setw(6) << v.at(i).second << " ";
	       cout << endl;
	  }
     }
     
     if (1)
     {	  
	  vector<unsigned int> a;
	  for (auto i=0u; i<v.size(); i++)
	  {
	       //cerr << "Solving for i " << i << endl;
	       unsigned int r=3;
	       unsigned int nn = v.size()-1;
	       for (unsigned int m=0; m<(1<<nn); m++)
	       {
		    //cerr << "Solving i = " << i << "  m = " << m << endl;
		    vector<unsigned int> k;
		    k.push_back(i);
		    for (auto j=0u; j<nn; j++)
		    {
			 if (m&(1<<j))
			 {
			      if (j < i)
			      {
				   k.push_back(j);
			      }
			      else
			      {
				   k.push_back(j+1);
			      }
			 }
		    }
		    //for (auto u : k) cerr<< u<< " " ; cerr << endl;
		    if (k.size() > r)
		    {
			 vector<pair<int,int> >w;
			 for (auto &u : k) w.push_back(v.at(u));
			 auto b = boundary(w);
			 for (auto u : b)
			 {
			      if (u == 0)
			      {
				   r = k.size();
			      }
			 }
		    }
	       }
	       a.push_back(v.size()-r);
	  }
	  return a;
     }

     vector<unsigned int> b;
     return b;
}

int main( int argc, char ** argv )
{
     unsigned int i;
     unsigned int t;

     cin >> t;

     for (i=1; i<=t; i++) {
	  unsigned int r;

	  cin >> r;

	  vector<pair<int,int> > v(r);
	  for (auto &p : v ) cin >> p.first >> p.second ;

	  auto e = solve(v);

	  cout << "Case #" << i << ":" << endl;
	  for (auto &x : e) cout << x << endl;
     }

     return 0;
}

