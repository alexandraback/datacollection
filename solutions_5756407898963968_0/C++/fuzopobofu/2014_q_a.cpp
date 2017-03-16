#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <utility>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int i, j;
  
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {

    int N;
    cin >> N;
    std::vector< std::vector<int> > vv(4, std::vector<int>(4));
    for (int _vi = 0; _vi < 4; _vi++) {
      for (int _vj = 0; _vj < 4; _vj++) {
	cin >> vv[_vi][_vj];
      }
    }
   
    int M;
    cin >> M;
    std::vector< std::vector<int> > vv2(4, std::vector<int>(4));
    for (int _vi = 0; _vi < 4; _vi++) {
      for (int _vj = 0; _vj < 4; _vj++) {
	cin >> vv2[_vi][_vj];
      }
    }
    
    sort( vv[N-1].begin(), vv[N-1].end() );
    sort( vv2[M-1].begin(), vv2[M-1].end() );

    // WARNING: 2 collections must be sorted!
    auto v1 = vv[N-1];
    auto v2 = vv2[M-1];
    vector<int> result;  // 結果が格納される vector (back_inserter により結果がプッシュされていく)
    set_intersection(vv[N-1].begin(), vv[N-1].end(), vv2[M-1].begin(), vv2[M-1].end(), back_inserter(result));
    switch (result.size()) {
    case 1:
      std::cout << "Case #" << (t+1) << ": " << result[0] << std::endl;
      break;

    case 0:
      std::cout << "Case #" << (t+1) << ": " << "Volunteer cheated!" << std::endl;      
      break;

    default:
      std::cout << "Case #" << (t+1) << ": " << "Bad magician!" << std::endl;      
      break;
    }
  }
}

int main(int argc, char *argv[])
{
  solve();
  return 0;
}

