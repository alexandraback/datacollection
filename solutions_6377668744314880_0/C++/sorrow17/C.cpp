#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>

#define MAXN 3000

using namespace std;
typedef double TYPE;
#define Abs(x) (((x)>0)?(x):(-x))
#define Sgn(x) (((x)<0)?(-1):(1))
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))

#define Epsilon 1e-4
#define Infinity 1e+6

struct POINT{
  TYPE x;
  TYPE y;
  TYPE z;
  POINT() : x(0), y(0), z(0){};
  POINT(TYPE _x, TYPE _y, TYPE _z) : x(_x), y(_y), z(_z){};
};

inline TYPE Cross(const POINT& a, const POINT& b){
  return a.x*b.y - a.y*b.x;
}

int T = 0;
TYPE X[MAXN],Y[MAXN];
POINT P[MAXN];
tuple<int, TYPE> Angle[MAXN];

void solve(ifstream& fin,ofstream& fout){
  int T = 0;

  fin >> T;
  for (size_t t = 0; t < T; t++) {
    fout << "Case #" << t+1 << ":"<< endl;
    int N = 0;
    fin >> N;
    for (size_t i = 0; i < N; i++) {
      fin >> X[i] >> Y[i];
      P[i].x = X[i];
      P[i].y = Y[i];
    }
    for (size_t i = 0; i < N; i++) {
      int ans = N;
      for (size_t j = 0; j < N; j++) {
        if (i == j) continue;
        POINT o(P[j].x - P[i].x, P[j].y - P[i].y, 0);
        int suml = 0;
        int sumr = 0;
        int summ = 0;
        for (size_t k = 0; k < N; k++) {
          POINT tmp = POINT(P[k].x - P[i].x, P[k].y - P[i].y, 0);
          if (Cross(o, tmp) > Epsilon) suml++;
          if (Cross(o, tmp) < -Epsilon) sumr++;
        }
        int tmp_ans = Min(suml, sumr);
        if (tmp_ans < ans) ans = tmp_ans;
      }
      fout << ans << endl;
    }
  }
}