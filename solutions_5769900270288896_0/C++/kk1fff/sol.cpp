#include <iostream>
using namespace std;
int room[10000];

int roomnum(int fl, int ft, int c) {
  return c * ft + fl;
}

int unhapp(int r, int c) {
  int rn = r * c;
  int o = 0;
  for (int i = 0; i < rn; i++) {
    //cout << room[i] << " ";
    if (room[i] == 0) continue;
    int fl = i % c;
    int ft = i / c;
    // cout << "i = " << i << " r = " << r << " c = " << c
    //      << " fl = " << fl << " ft = " << ft << endl;
    //cout <<"(";
    if (fl + 1 < c) {
      //cout << "r: " << roomnum(fl + 1, ft, c) << " ";
      o += room[roomnum(fl + 1, ft, c)];
    }
    if (ft + 1 < r) {
      //cout << "d: " << roomnum(fl, ft + 1, c) << " ";
      o += room[roomnum(fl, ft + 1, c)];
    }
    //cout << ")" << "[" << o << "] ";
  }
  //cout << "->" << o << endl;
  return o;
}

int minunhapp(int r, int c, int leidx, int left, int total) {
  if (left == 0) {
    return unhapp(r, c);
  }

  int minunh = INT_MAX;
  for (int i = leidx; i <= total - left; i++) {
    room[i] = 1;
    minunh = min(minunh, minunhapp(r, c, i + 1, left - 1, total));
    room[i] = 0;
  }
  return minunh;
}

void run(int t) {
  int r, c, n;
  cin >> r >> c >> n;
  memset(room, 0, sizeof(int) * 10000);
  cout << "Case #" << t << ": " << minunhapp(r, c, 0, n, r * c) << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    run(i);
  }
}
