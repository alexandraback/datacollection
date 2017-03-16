#include <string.h>
#include <stdint.h>
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())

#define for0n(i,n) for(i=0;i<n;i++)
#define for1n(i,n) for(i=1;i<=n;i++)
#define forn(i,j,n) for(i=j;i<n;i++)
#define ZERO(arr) for(int CNT=0;CNT<sizeof(arr);CNT++){arr[CNT]=0;}

const int MAX = 1000000;
const int inf = 2100000000;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;

int moveDir[4][2] = { {0, -1} , {1, 0} , {0, 1} , {-1, 0} }; // N, E, S, W
char dirName[4] = { 'N', 'E', 'S', 'W' };

//ofstream debug("debug.txt", fstream::trunc);

//
// Add variables here.
//
int nCases;
int c, i, j, k, l;
int ans;

uint32_t my32;
uint64_t modArr[3][3];

int debug = 0;

int euclid(int a, int b) {
  if (b > a) { int t = a; a = b; b = t; }
  while (b != 0) {
      int m = a % b;
      a = b;
      b = m;
  }
  return a;
}


int main (int argc, char **argv)
{
  if (argc < 2) {
    printf("Specify input file\n");
    return -1;
  }

  ifstream inFile(argv[1]);
  ofstream outFile("output.txt", fstream::trunc);

  inFile >> nCases;
  cerr << nCases << " cases." << endl;
  for0n(c,nCases) {
    ans = 0;
    int B, N;
    int M[100000];
    int Mp[100000];
    int lcm = 1;
    inFile >> B >> N;
    for0n(i, B) {
      inFile >> M[i];
      lcm = (lcm * M[i])/euclid(lcm, M[i]);
    }
    //cerr << lcm << endl;

    int cyctot = 0;
    for0n(i, B) {
      Mp[i] = lcm / M[i];
      cyctot += Mp[i];
    }
    //cerr << cyctot << endl;

    N--;
    N = N % cyctot;
    N++;
    
    //cerr << N << endl;; 

    list<pii> eq;
    list<pii>::iterator eqit;
    uint64_t tnow = 0;
    for0n(i, B) {
      eq.push_back(make_pair(i, 0));
    }
    for0n(i, N) {
      if (debug) {
        for (eqit = eq.begin(); eqit != eq.end(); eqit++) {
          cerr << ((*eqit).first) + 1 << " ";
        }
        cerr << endl;
      }
      pii bp = eq.front();
      eq.pop_front();
      ans = bp.first + 1;
      tnow = bp.second;
      bp.second = tnow += M[bp.first]; // Add in haircut time for this guy

      // Reinsert
      for (eqit = eq.begin(); eqit != eq.end(); eqit++) {
        if ((*eqit).second == bp.second) {
          if ((*eqit).first > bp.first) {
            eq.insert(eqit, bp);
            break;
          }
        }
        if ((*eqit).second > bp.second) {
          eq.insert(eqit, bp);
          break;
        }
      }
      if (eqit == eq.end()) {
        eq.push_back(bp);
      }
    }

    cout << "Case #" << c + 1 << ": " << ans << endl;
  }

  outFile.close();
  return 0;
}
