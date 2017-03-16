#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int gcd ( int a, int b ) {
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main(int argc, char** argv) {

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int B, N;
        cin >> B >> N;
        
        vi v(B);
        for (int i = 0; i < B; ++i) cin >> v[i];
        
        int product = 1;
        for (int i = 0; i < B; ++i) 
            product = (product * v[i])/gcd(product, v[i]);
        
        int serviced = 0;
        for (int i = 0; i < B; ++i)
            serviced += product/v[i];
        
        N = (N-1) % serviced;
        
        vi times(B, 0);
        while (N != 0) {
            int m = 10000, index;
            for (int i = 0; i < B; ++i) {
                if (m > times[i]) {
                    m = times[i];
                    index = i;
                }
            }
            if (m == 0) {
                times[index] += v[index];
                N--;
            } else {
                for (int i = 0; i < B; ++i)
                    times[i] -= m;
            }
        }
        
        int temp = times[0], ans = 0;
        for (int i = 0; i < B; ++i) {
            if (temp > times[i]) {
                temp = times[i];
                ans = i;
            }
        }
        cout << "Case #" << cases << ": " << ans+1 << endl;
    }
    return 0;
}

