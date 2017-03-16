//my magic will tear you apart!
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
typedef long long ll;

const int N = 1010;
int t, n, m[N];

int main() {
  if(fopen("A.in","r")) freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  cin >> t;
  for(int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    int maxd = 0;
    int sumd = 0;
    int ans2 = 0;
    cin >> n;
    for(int j = 0; j < n; j++) {
      cin >> m[j];
    }
    for(int j = 1; j < n; j++) {
      if(m[j] < m[j-1]) 
        sumd += m[j-1] - m[j];
      maxd = max(maxd, m[j-1] - m[j]);
    }
    for(int j = 0; j < n - 1; j++) {
      ans2 += min(maxd, m[j]);
    }
    cout << sumd << " ";
    cout << ans2 << endl;
  }
  return 0;
}