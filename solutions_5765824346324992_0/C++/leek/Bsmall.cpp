#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll N;
ll  M[10005];
int B;

bool cancut(ll tt) {
  ll cut = 0;
  for(int i=1; i<=B; i++) {
    cut += tt/M[i] + 1;
  }

  return (cut >= N);
}

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    cin >> B >> N;
    for(int i=1; i<=B; i++)
      cin >> M[i];

    ll left = 0;
    ll right = 1e18;
    while(left +1 < right) {
      ll mid = (left+right)/2;
      
      if(cancut(mid)) right = mid;
      else left = mid;
    }

    if(!cancut(left)) left ++;
    ll timetocut = left - 1;
    if(timetocut > 0) {
      for(int i=1; i<=B; i++) {

        N -=  ((timetocut)/M[i] +1);
      }
    }

    int ret = B;
    if(N==0) {
      for(; ret>=1; ret--) {
        if((timetocut%M[ret]) == 0) break;
      }
    }
    else {
      timetocut = left;
      for(int i=1; i<=B; i++) {
        if((timetocut % M[i]) ==0) N--;
        if(N==0) {
          ret = i;
          break;
        }
      }
    }
    printf("Case #%d: %d\n",tc,ret);


  }

  return 0;
}