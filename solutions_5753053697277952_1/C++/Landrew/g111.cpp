#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <stdio.h>
#include <sstream>
#include <string>

#include <math.h>

using namespace std;

ofstream fout("OUT111.txt");
ifstream fin ("INP111.txt");

int main() {

  int TT;
  fin >> TT;

  for (int tt=0;tt<TT; tt++)
  {
    int n;
	fin >> n;
	vector <int> num;
	int su = 0;
	for (int i=0; i<n; i++)
	{
       int te;
	   fin >> te;
	   num.push_back(te);
	   su += te;
	}

	fout << "Case #" << tt+1 << ": ";

    while (su > 0)
	{
      int bes = -1;
	  for (int i=0; i<n; i++)
		  bes = max(num[i], bes);

	  string ou = "";
	  bool fdone = false;
	  for (int i=0; i<n && !fdone; i++)
	  {
        if (num[i] == bes)
		{
          num[i]--;
		  fdone = true;
		  char c = 'A' + i;
		  ou = ou + c;
		  su--;
		}
	  }

	  if (su != 2)
	  {
	  bool tdone = false;
	  for (int i=0; i<n && !tdone; i++)
	  {
        if (num[i] == bes)
		{
          num[i]--;
		  tdone = true;
		  char c = 'A' + i;
		  ou = ou + c;
		  su--;
		}
	  }
	  }
	  fout << ou << " ";
	}

    fout << endl;

  }

   return 0;
}
