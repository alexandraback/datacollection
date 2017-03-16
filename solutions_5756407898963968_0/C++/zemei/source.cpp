/*
 * Tibor Mezei (zemei)
 * Google Code Jam 2014
 * Standard: C++11 with GCC-4.8.2
*/

#include <deque>
#include <list>
#include <tuple>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>
#include <complex>
#include <iostream>
#include <fstream>
#include <regex>
#include <string>

#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;


// Prime number tester
bool isPrime(uint64_t x) {
  if (x<2) return false;
  for (uint64_t i=2; i*i<=x; ++i)
    if (x%i==0) return false;
  return true;
}


int main(int argc, char **argv) {

  ifstream fi;		// input file
  ofstream fo;		// output file
  int numCases;	    // number of cases

  if (argc!=2) { 
    printf("No input!\n"); 
    return -1; 
  }

  fi.open(argv[1]);
  fo.open("output.txt");


  fi >> numCases;

  for (int cases=1; cases<=numCases; ++cases) {
    // -----------------------------------------------------------------------------
    int aa;
    vector<int> a;
    fi >> aa;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
        int v;
        fi >> v;
        if (i + 1 == aa)
            a.push_back(v);
        }
    }
    int bb;
    vector<int> b;
    fi >> bb;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
        int v;
        fi >> v;
        if (i + 1 == bb)
            b.push_back(v);
        }
    }
    vector<int> c(16);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    c.resize(it - c.begin());
    // ------------------------------------------------------------------------------
    fo << "Case #" << cases << ": ";
    if (c.size() == 0)
        fo << "Volunteer cheated!";
    else if (c.size() == 1)
        fo << c[0];
    else
        fo << "Bad magician!";
    fo << endl;
  }

  fi.close();
  fo.close();
  return 0;
}


