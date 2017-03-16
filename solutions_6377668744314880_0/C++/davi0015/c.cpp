#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(I,N) for (int I=0; I<N; I++)
#define fornd(I,N) for (int I=N-1; I>=0; I--)
#define forab(I,A,B) for (int I=A; I<=B; I++)
#define forabd(I,A,B) for (int I=B; I>=A; I--)
#define FOREACH(I,A) for (__typeof__(A)::iterator I=A.begin(); I<A.end(); I++)
#define pb push_back
#define mp make_pair

typedef long long int ll;

struct Point{
  ll x, y;

  Point() {
    x = 0; y = 0;
  }

  Point(ll _x, ll _y) {
    x = _x; y = _y;
  }
};


ll getCrossProduct(Point p1, Point p2, Point p3) {
  return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}

int getMin(int index, vector<Point>& pts) {
  int N = pts.size();

  int minCut = N;
  forn(i, N) {
    if(i != index) {
      int nPos = 0, nNeg = 0;
      forn(j, N) {
        if(j != i && j != index) {
          ll temp = getCrossProduct(pts[index], pts[i], pts[j]);
          if(temp > 0) {
            nPos++;
          }
          else if(temp < 0) {
            nNeg++;
          }
        }
      }
      if(minCut >nPos) {
        minCut = nPos;
      }
      if(minCut > nNeg) {
        minCut = nNeg;
      }
    }
  }
  return minCut;
}

int main() {
  int T;
  cin >> T;

  forn(i, T) {
    int N;
    cin >> N;

    vector<Point> pts(N);
    ll x, y;
    forn(j, N) {
      cin >> x >> y;
      pts[j] = Point(x, y);
    }

    cout << "Case #" << i + 1 << ":" << endl;
    forn(j, N) {
      cout << getMin(j, pts) << endl;
    }
  }
}
