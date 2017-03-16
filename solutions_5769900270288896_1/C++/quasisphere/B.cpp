#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

int main(void) {
  int64_t T;
  cin >> T;
  for(int64_t t=1;t<=T;t++) {
    int64_t r,c,n;
    cin >> r >> c >> n;
    if(r>c) swap(r,c);
    if(r*c % 2 == 0) {
      if(n <= r*c/2) {
        cout << "Case #" << t << ": 0\n";
        continue;
      }
      int64_t remove=r*c-n;
      if(r == 1) {
        int64_t penalty=c-1;
        if(remove > (c/2 - 1)) {
          remove-=(c/2 - 1);
          penalty-=2*(c/2 - 1);
          if(remove > 0) {
            remove--;
            penalty--;
          }
        } else {
          penalty-=remove*2;
        }
        cout << "Case #" << t << ": " << penalty << "\n";
      } else if(r == 2) {
        int64_t penalty=c+2*(c-1);
        if(remove > c-2) {
          remove-=c-2;
          penalty-=3*(c-2);
          if(remove > 0) {
            penalty-=2*remove;
          }
        } else {
          penalty-=3*remove;
        }
        cout << "Case #" << t << ": " << penalty << "\n";
      } else {
        int64_t penalty=(r-1)*c + (c-1)*r;
        if(remove > (r-2)*(c-2)/2) {
          remove-=(r-2)*(c-2)/2;
          penalty-=4*(r-2)*(c-2)/2;
          if(remove > r+c-4) {
            remove-=r+c-4;
            penalty-=3*(r+c-4);
            if(remove > 0) {
              penalty-=2*remove;
            }
          } else {
            penalty-=3*remove;
          }
        } else {
          penalty-=4*remove;
        }
        cout << "Case #" << t << ": " << penalty << "\n";
      }
    } else {
      if(n <= (r*c + 1)/2) {
        cout << "Case #" << t << ": 0\n";
        continue;
      }
      int64_t remove=r*c-n;
      if(r == 1) {
        int64_t penalty1=c-1;
        if(remove > (c+1)/2 - 2) {
          remove-=(c+1)/2 - 2;
          penalty1-=2*((c+1)/2 - 2);
          if(remove > 0) {
            penalty1-=remove;
          }
        } else {
          penalty1-=2*remove;
        }
        int64_t penalty2=c-1;
        if(remove <= (c-1)/2) {
          remove-=(c-1)/2;
          penalty2-=2*remove;
        } else {
          penalty2=r*c*4;
        }
        cout << "Case #" << t << ": " << min(penalty1,penalty2) << "\n";
      } else {
        int64_t penalty=(r-1)*c + (c-1)*r;
        if(remove > ((r-2)*(c-2) + 1)/2) {
          remove-=((r-2)*(c-2) + 1)/2;
          penalty-=4*((r-2)*(c-2) + 1)/2;
          if(remove > r+c-6) {
            remove-=r+c-6;
            penalty-=3*(r+c-6);
            penalty-=2*remove;
          } else {
            penalty-=3*remove;
          }
        } else {
          penalty-=4*remove;
        }
        int64_t penalty2=(r-1)*c + (c-1)*r;
        remove=r*c-n;
        if(remove > ((r-2)*(c-2) - 1)/2) {
          remove-=((r-2)*(c-2) - 1)/2;
          penalty2-=4*((r-2)*(c-2) - 1)/2;
          if(remove > r+c-2) {
            remove-=r+c-2;
            penalty2-=3*(r+c-2);
          } else {
            penalty2-=3*remove;
            remove=0;
          }
        } else {
          remove=0;
          penalty2-=4*remove;
        }
        if(remove > 0) {
          cout << "Case #" << t << ": " << penalty << "\n";
        } else {
          cout << "Case #" << t << ": " << min(penalty,penalty2) << "\n";
        }
      }
    }
  }
  return 0;
}

