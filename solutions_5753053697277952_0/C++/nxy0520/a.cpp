#include "iostream"
#include "stdio.h"

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int cs = 1; cs<=T; cs++) {
    cout << "Case #" << cs << ":";
    int N;
    cin >> N;
    int a[30] = {};
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    int ans = 0;
    int maxv = 0;
    for (int i = 1; i <= N; i++) {
      if (a[i] > maxv) {
        maxv = a[i];
        ans = i;
      }
    }
    int ans2 = 0;
    int maxv2 = 0;
    for (int i = 1; i <= N; i++) {
      if (a[i] > maxv2 && i!=ans) {
        ans2 = i;
        maxv2 = a[i];
      }
    }
    if (maxv2 != maxv) {
      for (int i = maxv2; i<maxv;i++) {
        char c = 'A' + ans - 1;
        cout << " " << c;
      }
    }
    for (int i = 1; i<=N;i++) {
      if (i!=ans && i!=ans2) {
        for (int j = 0; j < a[i];j++) {
          char c = 'A' + i - 1;
          cout << " " << c;
        }
      }
    }
    for (int i = 1; i<=maxv2;i++) {
      char c = 'A' + ans - 1;
      char d = 'A' + ans2 - 1;
      cout << " " << c << d;
    }
    cout<<endl;
  }
}
