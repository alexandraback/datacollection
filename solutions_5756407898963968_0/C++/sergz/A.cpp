#include <iostream>

using namespace std;

int
count_set_bits(int n) {
  n = n - ((n >> 1) & 0x55555555);
  n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
  return (((n + (n >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int
main() {
  int T;
  int bit[16];
  int b = 1;

  for(int i = 0; i < 16; i++) {
    bit[i] = b;
    b <<= 1;
  }

  cin >> T;
  
  for(int i = 1; i <= T; i++) {
    int r1, r2;
    int l1 = 0, l2 = 0;

    cin >> r1;
    for(int r = 1; r <= 4; r++) {
      for(int c = 0; c < 4; c++) {
	int v;

	cin >> v;
	if(r == r1) {
          l1 |= bit[v-1];
	}
      } 
    } 

    cin >> r2;
    for(int r = 1; r <= 4; r++) {
      for(int c = 0; c < 4; c++) {
	int v;

	cin >> v;
	if(r == r2) {
          l2 |= bit[v-1];
	}
      } 
    } 

    int m = l1&l2;
    int n = count_set_bits(m);
    cout << "Case #" << i << ": ";
    if(n == 1) {
      int k = 0;
      while(m != 0) {
	m >>= 1;
	k++;
      }
      cout << k;
    } else if(n == 0) {
      cout << "Volunteer cheated!";
    } else {
      cout << "Bad magician!";
    }
    cout << endl;
  }

  return 0;
}

