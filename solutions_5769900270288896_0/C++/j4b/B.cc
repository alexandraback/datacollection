#include <iostream>
#include <vector>

using namespace std;

int firstPerm(int n) {
  unsigned int r = 0;
  for (int i = 0; i < n; i++) {
    r |= (1 << i);
  }
  return r;
}

int nextPerm(unsigned int v) {
  unsigned int t = v | (v - 1);
  return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
}

bool occupied(unsigned int v, int r, int c, int i, int j) {
  return v & (1 << (i*c + j));
}

int noise(unsigned int v, int r, int c) {
  int noise = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      // check if there is a neighbour to the right
      if (j != c-1 && occupied(v, r, c, i, j) && occupied(v, r, c, i, j+1)) {
	  noise++;
      }

      // check if there is a neighbour to the bottom
      if (i != r-1 && occupied(v, r, c, i, j) && occupied(v, r, c, i+1, j)) {
	noise++;
      }
    }
  }
  return noise;
}

int solve(int r, int c, int n) {
  unsigned int v = firstPerm(n);
  int min_noise = INT_MAX;
  int rc = r*c;
  while (!((1 << (rc)) & v)) {
    min_noise = min(min_noise, noise(v, r, c));
    v = nextPerm(v);
  }
  return min_noise;
}

int main(int argc, char *argv[]) {
 
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int r, c, n;
    cin >> r >> c >> n;

    cout << "Case #" << i << ": " << solve(r, c, n) << endl;
  }
}
