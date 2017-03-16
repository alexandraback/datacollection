#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>

#define st first
#define nd second

using namespace std;

typedef pair<long long, long long> pII;

// Geometry

pII origin;
void operator -= (pII &p1, const pII &p2) {
  p1.st -= p2.st;
  p1.nd -= p2.nd;
}

bool ccw(pII O, pII A, pII B) {
  A -= O, B -= O;
  return A.st * B.nd > A.nd * B.st;
}

pII geometry__origin;
bool cmp(pII A, pII B) {
  return ccw(geometry__origin, A, B);
}

bool online(pII A, pII B, pII C) {
  B -= A;
  C -= A;
  return B.st * C.nd == B.nd * C.st;
}

// Find convex hull of a set of points, 1-indexed
// geometry__n > 3
// result is store in a, n
// origin: https://sites.google.com/site/kc97ble/arithmetic/graham-cpp-2
pII geometry__a[1111];
int geometry__n;
void convex_hull() {
  sort(geometry__a + 1, geometry__a + geometry__n + 1);
  geometry__origin = geometry__a[1];

  sort(geometry__a + 2, geometry__a + geometry__n + 1, cmp);
  geometry__a[0] = geometry__a[geometry__n];
  geometry__a[geometry__n + 1] = geometry__a[1];
  int j = 1;
  for (int i = 1; i <= geometry__n + 1; i++) {
    while (j > 2 && !ccw(geometry__a[j - 2], geometry__a[j - 1], geometry__a[i])) j--;
    geometry__a[j++] = geometry__a[i];
  }
  geometry__n = j - 2;
}

// Bit operator
int __2(int x) {
  return 1 << x;
}

int getbit(int a, int i) {
  return 1 & (a >> i);
}

int countbit(int a, int n) {
  int count = 0;
  for (int i = 0; i < n; i++)
    if (getbit(a, i) == 1) count++;
  return count;
}

map<pII, int> m;
int result[111];
pII p[111];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int nTest;
  cin >> nTest;
  for (int test = 1; test <= nTest; test++) {
    m.clear();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> p[i].st >> p[i].nd;
      m[p[i]] = i;
      result[i] = 1000000;
    }

    for (int status = 0; status < __2(n); status++) {
      int deleted = countbit(status, n);

      geometry__n = 0;
      for (int i = 0; i < n; i++) {
        if (getbit(status, i) ==  1)
          continue;

        geometry__n++;
        geometry__a[geometry__n] = p[i];
      }

      // Find convex hull
      if (geometry__n > 3)
        convex_hull();

      geometry__n++;
      geometry__a[geometry__n] = geometry__a[1];

      for (int i = 0; i < n; i++) {
        for (int j = 1; j < geometry__n; j++)
          if (online(p[i], geometry__a[j], geometry__a[j + 1])) {
            result[m[p[i]]] = min(result[m[p[i]]], deleted);
              //cout << p[i].st << " " << p[i].nd << ", " << geometry__a[j].st << " " << geometry__a[j].nd
              //     << ", " << geometry__a[j + 1].st << " " << geometry__a[j + 1].nd << endl;
          }
      }
    }


    printf("Case #%d:\n", test);
    for (int i = 0; i < n; i++)
      printf("%d\n", result[i]);
  }

  return 0;
}
