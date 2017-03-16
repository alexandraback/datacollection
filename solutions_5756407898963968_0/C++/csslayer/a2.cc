#include <iostream>
#include <stdint.h>
using namespace std;
const uint64_t m1  = 0x5555555555555555; //binary: 0101...
const uint64_t m2  = 0x3333333333333333; //binary: 00110011..
const uint64_t m4  = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
const uint64_t h01 = 0x0101010101010101; //the sum of 256 to the power of 0,1,2,3...

static inline 
int popcount_3(uint64_t x) {
    x -= (x >> 1) & m1;             //put count of each 2 bits into those 2 bits
    x = (x & m2) + ((x >> 2) & m2); //put count of each 4 bits into those 4 bits 
    x = (x + (x >> 4)) & m4;        //put count of each 8 bits into those 8 bits 
    return (x * h01)>>56;  //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ... 
}

int main()
{
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		int row, num;
		unsigned int arrange[2] = {0, 0};
		for (int m = 0; m < 2; m ++) {
			cin >> row;
			for (int i = 0 ; i < 4; i++) {
				for (int j = 0 ; j < 4; j++) {
					cin >> num;
					if (i == row - 1) {
						arrange[m] |= (1 << (num - 1));
					}
				}
			}
		}
		unsigned int inter = arrange[0] & arrange[1];
		int result = -1;
		if (inter != 0) {
			if (popcount_3(inter) == 1) {
				for (int i = 0 ;i < 16; i++) {
					if ((1 << i) & inter) {
						result = i;
						break;
					}
				}
			}
		} else {
			// cheat if no inter
			result = -2;
		}
		
		cout << "Case #" << t << ": ";
		if (result >= 0) {
			cout << result + 1;
		} else if (result == -2) {
			cout << "Volunteer cheated!";
		} else if (result == -1) {
			cout << "Bad magician!";
		}
		
		cout << endl;
	}
}