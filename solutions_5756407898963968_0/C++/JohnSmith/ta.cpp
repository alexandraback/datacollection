//
// Qualification round 2014  problem A
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;

int main( int argc, char ** argv )
{
     unsigned int n;
     unsigned int i,j;

     cin >> n;

     for (i=1; i<=n; i++) {

	  set <unsigned int> s1;
	  set <unsigned int> s2;
	  unsigned int a1, a2;
	  unsigned int c1, c2, c3, c4;

	  cin >> a1;
	  for (j=1; j<=4; j++)
	  {
	       cin >> c1 >> c2 >> c3 >> c4;
	       if (j==a1)
	       {
		    s1.insert(c1);
		    s1.insert(c2);
		    s1.insert(c3);
		    s1.insert(c4);
	       }
	  }

	  cin >> a2;
	  for (j=1; j<=4; j++)
	  {
	       cin >> c1 >> c2 >> c3 >> c4 ;
	       if (j==a2)
	       {
		    s2.insert(c1);
		    s2.insert(c2);
		    s2.insert(c3);
		    s2.insert(c4);
	       }
	  }

	  set<unsigned int> s3;
	  set_intersection( s1.begin(), s1.end(),
			    s2.begin(), s2.end(),
			    inserter(s3,s3.begin()) );

	  cout << "Case #" << i << ": ";
	  if (s3.size() == 0)
	  {
	       cout << "Volunteer cheated!" << endl;
	  }
	  else if (s3.size() == 1)
	  {
	       cout << *s3.begin() << endl;
	  }
	  else
	  {
	       cout << "Bad magician!" << endl;
	  }
     }

     return 0;
}

