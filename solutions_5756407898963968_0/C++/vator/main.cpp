#include <ctime>
#include <iostream>
#include <iomanip>
#include <set>
#include <cstdio>

using namespace std;

// TEMPLATE {{{
#ifdef ONLINE_JUDGE
#define OJ 1
#else
#define OJ 0
#endif

//#define TIMESTAMP fprintf(stderr, "Execution time: %.3lf s.\n", (double)clock()/CLOCKS_PER_SEC)
#define TIMESTAMP merr << "Execution time: " << fixed << setprecision(3) << (double)clock()/CLOCKS_PER_SEC << " s.\n"
class C_ {}; template <typename T> C_& operator <<(C_& m, const T& s) { if (!OJ) cerr << "\E[91m" << s << "\E[0m"; return m; }
C_ merr;
/// END OF TEMPLATE }}}

int main(void) {
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    int a;
    set<int> R1,R2;
    cin >> a;
    a--;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int m;
        cin >> m;
        if (i == a) R1.insert(m);
      }
    }
    cin >> a;
    a--;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int m;
        cin >> m;
        if (i == a && R1.find(m) != R1.end()) R2.insert(m);
      }
    }
    cout << "Case #" << tt+1 << ": ";
    if (R2.size() == 1) {
      cout << *R2.begin() << endl;
    } else {
      cout << ((R2.size()) ? "Bad magician!" : "Volunteer cheated!") << endl;
    }
  }
  //TIMESTAMP;
  return 0;
}
