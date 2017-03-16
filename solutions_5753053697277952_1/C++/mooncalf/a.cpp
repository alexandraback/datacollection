#include <iostream>

using namespace std;

int main() 
{
	int tests;
	cin >> tests;
	
	for (int i = 0; i < tests; ++i) {
		int parties, nums[25], total;
		total = 0;
		cin >> parties;
		for (int j = 0; j < parties; ++j) {
			cin >> nums[j];
			total += nums[j];
		}
		cout << "Case #" << i + 1 << ": ";
		while (total) {
			int high, sec, highInd, secInd;
			high = nums[0];
			highInd = 0;
			sec = 0;
			for (int j = 1; j < parties; ++j) {
				if (nums[j] > high) {
					sec = high;
					secInd = highInd;
					high = nums[j];
					highInd = j;
				}
				else if (nums[j] > sec) {
					sec = nums[j];
					secInd = j;
				}
			}
			char highChar = 'A' + highInd;
			char secChar = 'A' + secInd;
			if (high == sec && total != 3) {				
				cout << highChar << secChar << " ";
				--nums[highInd];
				--nums[secInd];
				total -= 2;
			}
			else {
				cout << highChar << " ";
				--nums[highInd];
				--total;
			}
		}
		cout << endl;
		
		
		
	}
	
	return 0;
}