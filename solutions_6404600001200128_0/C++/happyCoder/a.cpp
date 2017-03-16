#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i)
  {
    int N;
    int M[1009];
    cin >> N;
    for (int j = 0; j < N; ++j)
      cin >> M[j];
    int y = 0;
    int rate = 0;
    for (int j = 1; j < N; ++j) {
      if (M[j] < M[j-1]) {
	y += M[j-1]-M[j];
	rate = max(rate, M[j-1]-M[j]);
      }
    }
    int z = 0;
    for (int j = 1; j < N; ++j) {
      z += min(M[j-1], rate);
    }
    cout << "Case #" << i << ": " << y << ' ' << z << endl;
  }
  return 0;
}
