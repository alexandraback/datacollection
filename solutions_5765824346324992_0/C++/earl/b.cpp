#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main() {
  int Z;
  cin >> Z;
  for (int z=1; z<=Z;++z) {
    int m;
    long long N;
    cin >> m >> N;
    vector<long long> a(m);
    for (int i=0; i<m;++i){
      cin >> a[i];
    }
    long long lo = 0; long long hi = 100000000000000LL;
    //                                01234567890123
    while (hi > lo) {
      long long mid = (lo + hi) / 2;
      long long started = 0;
      for (int i = 0; i < m; ++i)
        started += 1 + mid / a[i];
      if (started < N)
        lo = mid + 1;
      else
        hi = mid;
    }
    cerr << "lo = " << lo << endl;
    vector<int> avail;
    long long done = 0;
    for (int i = 0; i < m; ++i) {
      if (lo % a[i] == 0) {
        avail.push_back(i);
        done += lo / a[i];
      } else
        done += 1 + lo / a[i];
    }
    cerr << "done = " << done << endl;
    cerr << "avail = " << avail.size() << endl;
    assert(done < N);

    assert(done + avail.size() >= N);
    assert(N - done - 1 < avail.size());
    assert(N - done - 1 >= 0);
    int answer = 1 + avail[N - done - 1];
    cout << "Case #" << z << ": " << answer << endl;

  }
}
