#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);

vector<vector<int> > repns;

string getseq(string str)
{
  string res;
  vector<int> repn;
  int s = str.size(), pre = 0, i;
  char c = str[0];
  res += c;
  for(i = 1; i < s; i++) {
    if(c != str[i]) {
      c = str[i];
      res += c;
      repn.push_back(i - pre);
      pre = i;
    }
  }
  repn.push_back(i - pre);
  repns.push_back(repn);
  return res;
}

int main()
{
  int t;
  cin >> t;
  
  for(int tcase = 1; tcase <= t; tcase++) {
    printf("Case #%d: ", tcase);
    repns.clear();
    bool imp = false;
    int n, s;
    char c;
    scanf("%d",&n);
    string seq, seqc, str;
    cin >> str;
    seq = getseq(str);
    for(int i = 1; !imp && i < n; i++) {
      cin >> str;
      seqc = getseq(str);
      if(seq != seqc) {
        imp = true;
      }
    }

    if(imp) {
      cout << "Fegla Won" << endl;
      continue;
    }

    int res = 0;
    s = seq.size();
    for(int i = 0; i < s; i++) {
      int minsum = 100000;
      for(int x = 1; x <= 100; x++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
          sum += abs(repns[j][i] - x);
        }
        minsum = min(minsum, sum);
      }
      res += minsum;
    }

    cout << res << endl;
  }

  return 0;
}
// Google Code Jam Problem A