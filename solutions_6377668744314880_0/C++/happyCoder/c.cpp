#include <iostream>
#include <utility>
#include <tuple>
#include <algorithm>

using namespace std;

bool IN_H[3009];
int N;
tuple<int, int, int> P[3009];
tuple<int, int, int> H[6009];
int M[3009];
int mask;

long long cross(const tuple<int, int, int> &O, const tuple<int, int, int> &A, const tuple<int, int, int> &B)
{
  return ((long long)(get<0>(A) - get<0>(O))) * (get<1>(B) - get<1>(O)) - ((long long)(get<1>(A) - get<1>(O))) * (get<0>(B) - get<0>(O));
}

int popcnt(int N)
{
  int r = 0;
  while (N)
  {
    if (N&1)
      ++r;
    N >>= 1;
  }
  return r;
}

void convex_hull()
{
  int k = 0;

  // Build lower hull
  for (int i = 0; i < N; ++i) {
	  if ((1<<i) & mask) continue;
	  while (k >= 2 && cross(H[k-2], H[k-1], P[i]) < 0) k--;
	  H[k++] = P[i];
  }

  // Build upper hull
  for (int i = N-2, t = k+1; i >= 0; i--) {
	  if ((1<<i) & mask) continue;
	  while (k >= t && cross(H[k-2], H[k-1], P[i]) < 0) k--;
	  H[k++] = P[i];
  }

  int m = popcnt(mask);
  
  for (int j = 0; j < k; ++j)
    M[get<2>(H[j])] = min(M[get<2>(H[j])], m);
}

void solve()
{
  cin >> N;
  for (int i = 0; i < N; ++i)
  {
    int X, Y;
    cin >> X >> Y;
    P[i] = make_tuple(X, Y, i);
    M[i] = N;
  }
  sort(P, P+N);
  for (int i = 0; i < (1<<N)-1; ++i)
  {
    mask = i;
    convex_hull();
  }
  for (int i = 0; i < N; ++i)
    cout << M[i] << endl;
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i)
  {
    cout << "Case #" << i << ":" << endl;
    solve();
  }
  return 0;
}
