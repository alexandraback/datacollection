#include <iostream>
#include <cstdio>
#include <cmath>

#include <string>
#include <vector>
#include <set>
#include <map>

#include <algorithm>

using namespace std;

#define ull long long
#define pb push_back 

#define vT int
#define vit  vector<vT>::iterator 
#define vitr vector<vT>::reverse_iterator 


string myUnique(string ss)
{
   vector<char> v(ss.begin(), ss.end());
   vector<char>::iterator it= unique(v.begin(), v.end());
   v.resize(distance(v.begin(), it));

   string s(v.begin(), v.end());
   return s;
}

int myCount(string &s, const char cc)
{
   int ret= 0;
   while(!s.empty())
   {
      const int l= s.size();
      char c= s[l-1];
      if(c == cc)
      {
	 ret++;
	 s.resize(l-1);
      }
      else
      {
	 break;
      }
   }

   return ret;
}


int main()
{
   int T;
   cin >> T;

   vector<string> vs, vs2;
   set<string> ss;
   string s, su;
   for(int j=0; j!=T; j++)
   {
      int N;
      vs.clear();
      vs2.clear();
      ss.clear();
      cin >> N;
      for(int k=0; k!=N; k++)
      {
	 cin >> s;
	 vs.pb(s);
	 su= myUnique(s);
	 ss.insert(su);
      }
      if(ss.size() > 1)
      {
	 cout << "Case #" << (j+ 1)<< ": " << "Fegla Won";
	 cout << endl;
	 continue;
      }

      int ret= 0;
   // su, vs vs[]
      const int len= su.size();
      map<int, int> mi;
      for(int k=len-1; k>=0; k--)
      {
	 const char c= su[k];
	 mi.clear();
	 for(int l=0; l!=N; l++)
	 {
	    string &ms= vs[l];
	    int ii= myCount(ms, c);
	    mi[ii]++;
	 }
      // cout << j << " " << mi.size() << endl;

	 int min= -1;
	 for(map<int,int>::iterator it1= mi.begin(); it1!=mi.end(); it1++)
	 {
	    const int k1= it1->first;
	 // const int v1= it1->second;
	    int temp= 0;

	    for(map<int,int>::iterator it2= mi.begin(); it2!=mi.end(); it2++)
	    {
	       const int k2= it2->first;
	       const int v2= it2->second;
	       temp+= abs(k1- k2)* v2;
	    }
	 // cout << k1 << " " << temp << " " << endl;

	    if(temp < min || min == -1) min= temp;
	 }
	 ret+= min;
      }

      cout << "Case #" << (j+ 1)<< ": " << ret;
      cout << endl;
   }

   return 0;
}
