#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define EPSILON 0.000000001

typedef struct point {
  int X, Y;
} Point;

float abs(float a) {
  if(a < 0) return -a;
  return a;
}

int main() {
  int T, N;
  int caso = 1;
  vector<Point> pontos;

  pontos.reserve(3000);
  cin >> T;
  while(caso <= T) {
    cin >> N;
    pontos.resize(N);
    for(int i = 0; i < N; i++) {
      cin >> pontos[i].X >> pontos[i].Y;
    }
    printf("Case #%d:\n", caso);

    for(int i = 0; i < N; i++) {
      int minPoints = N;

      for(int j = 0; j < N; j++) {
        if(j != i) {
          int pos = 0, neg = 0;
          long long int dy = pontos[j].Y-pontos[i].Y;
          long long int dx = pontos[j].X-pontos[i].X;
          for(int k = 0; k < N; k++) {
            if(k != i && k != j) {
                //cout << "aqui: " << i << " " << j << " " << k << endl;
              long long int res = dx*(pontos[k].Y-pontos[i].Y)-dy*(pontos[k].X-pontos[i].X);
              if(res < 0) {
                neg++;
              } else if(res > 0) {
                pos++;
              }
            }
          }
          int minim;

          //cout << "(" << i << "," << j << "," << ") -> "  << neg << " " << pos << endl;
          if(neg < pos) minim = neg;
          else minim = pos;
          if(minim < minPoints) minPoints = minim;
        }
      }
      printf("%d\n", minPoints);
    }

    caso++;
  }



  return 0;
}

