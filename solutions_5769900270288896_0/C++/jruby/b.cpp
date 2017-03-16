#include <iostream>
using namespace std;

int m[65537];
int R, C, N;

int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		cout << "Case #" << t << ": ";
    cin >> R;
    cin >> C;
    cin >> N;
    memset(m, -1, sizeof(m));
    
    int mm = 999999;
    for (int i=0;i<(1<< (R*C));i++) {
      bitset<16> val(i);
      int uh = 0;
      if (val.count() == N) {
        for (int j=0;j<R;j++) {
          for (int k=1;k<C;k++) {
            if (val.test(j*C + k) && val.test(j*C + k -1)) {
              uh++;
            }
          }
        }
        for (int j=0;j<C;j++) {
          for (int k=1;k<R;k++) {
            if (val.test(k*C + j) && val.test((k-1)*C + j)) {
              uh++;
            }
          }
        }
        mm = min(uh, mm);
      }
    }
    cout << mm << endl;
	}
	return 0;
}
