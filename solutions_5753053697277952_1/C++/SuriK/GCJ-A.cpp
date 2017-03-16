#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <iterator>
#include <set>
#include <stack>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <cassert>


#define LL long long
#define LD long double
#define PI pair<int,int>
#define PS pair<string, string>
#define PL pair<LL,LL>
#define pb push_back
#define mp make_pair
#define FORI(i,k,n) for (int i = (k); i < (n); i++)
#define RFORI(i,k,n) for (int i = (k); i > (n); i--)
#define FORL(i,k,n) for (LL i = (k); i < (n); i++)
#define RFORL(i,k,n) for (LL i = (k); i > (n); i--)
#define VI vector<int>
#define VPI vector<PI>
#define VPS vector<PS>
#define VPL vector<PL>
#define VB vector<bool>
#define VD vector<LD>
#define VL vector<LL>
#define VS vector<string>
#define VVI vector<vector<int>> 
#define VVVI vector<vector<vector<int>>> 
#define VVB vector<vector<bool>> 
#define VVVB vector<vector<vector<bool>>> 
#define VVL vector<vector<LL>> 
#define VVD vector<vector<LD>> 
#define SZ(x) ((int)x.size())
#define epsilon 1e-06


using namespace std;

class Prob {

public:
  int solve(int N, VPI& vP)
  {

    while (!vP.empty()) {
      sort(vP.rbegin(), vP.rend());

      if (vP[0].first == 0)
        break;

      if (vP[0].first > vP[1].first)
      {
        cout << (char) ('A' + vP[0].second) << " ";
        vP[0].first--;
      }
      else {

        if (N > 2 && vP[0].first == 1 && vP[2].first == 1) {
          cout << (char)('A' + vP[0].second) << " ";
          vP[0].first--;
        }
        else {
          cout << (char)('A' + vP[0].second) << (char)('A' + vP[1].second) << " ";
          vP[0].first--;
          vP[1].first--;
        }
      }

    }




    return 0;
  }
};

int main() {
  int t;
  cin >> t;
  FORI(i, 1, t + 1) {

    int N;
    cin >> N;

    VPI vP(N);
    FORI(j, 0, N) {
      cin >> vP[j].first;
      vP[j].second = j;
    }

    Prob prob;
    cout << "Case #" << i << ": ";
    prob.solve(N, vP);
    cout << endl;
  }

  return 0;
}



