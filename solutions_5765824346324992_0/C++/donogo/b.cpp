#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <cstdio>
#include <queue>

int debug = 0;
typedef long long int LLint;

using namespace std;

typedef struct bb {
  int id;
  int minute;
  int openminute;
} BB;


class BBcmp {
  bool rev;
public:
  BBcmp(const bool& revp=false)
  { rev = revp; }
  bool operator() (const BB& l, const BB&r) const
  {
    if (l.openminute == r.openminute) {
      return (l.id > r.id);
    }
    return (l.openminute > r.openminute);
  }
};


void show(int n, BB b) {
  cout << "n=" << n << ", id=" <<  b.id << ", open=" << b.openminute << endl;
}


LLint gcd( LLint x, LLint y) {
  LLint d;
  while (y != 0) {
    d = x % y;
    x = y;
    y = d;
  }
  return x;
}

LLint lcm(LLint x, LLint y) {
  LLint d;
  d = gcd(x, y);
  return x * y / d;
}


int barb(vector <int> M, LLint N) {
  int B = M.size();
  vector <BB> BM;
  int k;
  LLint n;
  LLint modu = 1;
  LLint capcycle = 0;

  for (k = 1; k <= B; k++) {
    BB b;
    b.id = k;
    b.minute = M[k - 1];
    b.openminute = 0;
    BM.push_back(b);
    modu = lcm(modu, b.minute);
  }


  if (modu > 0) {
    for (k = 1; k <= B; k++) {
      capcycle += (modu / M[k - 1]);
    }
  }

  if (capcycle > 0) {
    N %= capcycle;
    if (N == 0) {
      N = capcycle;
    }
  }
  
  priority_queue < BB, vector <BB>, BBcmp > BMQ(BM.begin(), BM.end());
  BB top;

  for (n = 1; n <= N; n++) {
    top = BMQ.top();
    //    show(n, top);
    top.openminute += top.minute;

    BMQ.pop();
    BMQ.push(top);
  }

  return top.id;

}


int main(void) {
  int T, t;
  int B;
  LLint N;
  int k;
  int res;

  cin >> T;

  for (t = 1; t <= T; t++) {
    cin >> B;
    cin >> N;
    vector <int> M;
    for (k = 0; k < B; k++) {
      int m;
      cin >> m;
      M.push_back(m);
    }

    res = barb(M, N);
    
    cout << "Case #" << t << ": " << res << endl;

  }
  return 0;
}
