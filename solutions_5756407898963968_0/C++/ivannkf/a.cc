#include <iostream>
#include <set>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i) {
		int row;
		cin >> row;
		set<int> nums;
		for(int j = 0; j < 4; ++j) {
			for(int k = 0; k < 4; ++k) {
				int num;
				cin >> num;
				if(j == row-1) {
					nums.insert(num);
				}
			}
		}
		cin >> row;
		int res = -1;
		for(int j = 0; j < 4; ++j) {
			for(int k = 0; k < 4; ++k) {
				int num;
				cin >> num;
				if(j+1 == row) {
					if(nums.find(num) != nums.end()) {
						if(res == -1) res = num;
						else res = -2;
					}
				}
			}
		}
		cout << "Case #" << i+1 << ": ";
		if(res == -1) cout << "Volunteer cheated!";
		else if(res == -2) cout << "Bad magician!";
		else cout << res;
		cout << endl;
	}
}