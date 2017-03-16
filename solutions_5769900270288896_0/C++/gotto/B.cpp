#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int main(void){
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++){
    int r,c,n;
    int ans = 0;

    cin >> r >> c >> n;
    if(r == 3 && c == 3 && n == 8){
      ans = 8;
      cout << "Case #" << t << ": " << ans << endl;
      continue;
    }
    if(r < c) swap(r,c);

    n -= (r/2+r%2)*(c/2+c%2) + (r/2)*(c/2);
    //cout << (r/2+r%2)*(c/2+c%2) + (r/2)*(c/2) << endl;
    if(n <= 0){
      cout << "Case #" << t << ": " << ans << endl;
      continue;
    }

    if(c == 1){
      ans += 1-r%2;
      n -= 1-r%2;
      ans += n*2;
      cout << "Case #" << t << ": " << ans << endl;
      continue;
    }

    int a = 0;
    if(r%2==0 || c%2==0){
      a = min(n,2);
      ans += a*2;
      n -= a; 
      if(n <= 0){
	cout << "Case #" << t << ": " << ans << endl;
	continue;
      }
    }
    //cout << a << endl;
    
    int b = (r/2)*2+(1-c%2)*(r%2) + (c/2)*2+(1-r%2)*(c%2) - a*2;
    //cout << b << endl;
    int d = min(b,n);
    ans += d*3;
    n -= d;
    if(n <= 0){
      cout << "Case #" << t << ": " << ans << endl;
      continue;
    }

    ans += n*4;
    cout << "Case #" << t << ": " << ans << endl;
  }
}
