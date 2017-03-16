#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctype.h>
#include <sstream>
#include <map>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
 
using namespace std;

typedef long long LL;

#define FOR(i,n) for(int i = 0;i < n;i++)
#define MP make_pair
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define PII pair<int, int>
#define PDD pair<double, double>
#define PSS pair<string, string>
#define PLL pair<long long, long long>
#define CLEAR(a) memset(a, 0, sizeof(a))
#define prev eruyvuy
#define INF 2000000007
#define next abc
const double EPS = 1E-7;
const LL mod = 1000000007;

using namespace std;

int n;
int a[1005];

int main() {
  ios_base::sync_with_stdio(0);
  int t,idx=1;
  cin >> t;
  FOR(tt,t) {
    cin >> n;
    int prev = 0;
    int sum = 0;
    int md = 0;
    FOR(i, n) {
      cin >> a[i];
      if (a[i] < prev) {
        sum += prev-a[i];
        md = max(md, prev-a[i]);
      }
      prev=a[i];
    }
    cout << "Case #" << idx++ << ": " << sum << ' ';

    int ans = 0;
    FOR(i, n-1) {
      if (a[i] <= md)
        ans += a[i];
      else
        ans += md;
    }
    cout << ans << endl;
  }  

  return 0;
}
