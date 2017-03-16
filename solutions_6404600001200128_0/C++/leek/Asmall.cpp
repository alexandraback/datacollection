#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int N;
int m[10000];

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    cin >> N;
    for(int i=0; i<N; i++)
      cin >> m[i];
    int ret1=0, ret2=0;

    for(int i=0; i<N-1; i++) {
      ret1 += max(m[i]-m[i+1], 0);
    }

    int maxgap = 0;
    for(int i=0; i<N-1; i++) {
      maxgap = max(max(m[i]-m[i+1],0),maxgap );
    }
    for(int i=0; i<N-1; i++) 
      ret2 += min(maxgap , m[i]);

    printf("Case #%d: %d %d\n",tc,ret1, ret2);


  }

  return 0;
}