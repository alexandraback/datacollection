#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <cctype>
#include <bitset>
#include <ctime>
#include <cassert>
#include <fstream>
#include <complex>
#include <iomanip>
using namespace std;

#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))
#define ABS(x) (((x)<0)?(-(x)):(x))
#define ff first
#define ss second
#define ei else if
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const ld EPS = 1e-7;
const ld PI  = 3.141592653589793;

int main() {
  ios_base::sync_with_stdio(0);

  int T; cin >> T;
  for(int tests = 1; tests <= T; ++tests) {
    int row1; cin >> row1;
    int cards[17] = {0}, num;
    for(int i = 1; i <= 4; ++i)
      for(int j = 1; j <= 4; ++j) {
	cin >> num;
	if(i == row1) cards[num]++;
      }

    int row2; cin >> row2;
    for(int i = 1; i <= 4; ++i)
      for(int j = 1; j <= 4; ++j) {
	cin >> num;
	if(i == row2) cards[num]++;
      }

    int cnt = 0, c;
    for(int i = 1; i <= 16; ++i)
      if(cards[i] == 2) {
	c = i;
	cnt++;
      }

    cout << "Case #" << tests << ": ";
    if(cnt == 1) cout << c;
    if(cnt == 0) cout << "Volunteer cheated!";
    if(cnt >= 2) cout << "Bad magician!";
    cout << '\n';
  }

  return 0;
}
