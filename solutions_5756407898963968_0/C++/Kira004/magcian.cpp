#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int casenum;
	vector<vector<int> > arr1(4, vector<int>(4, 0));
	vector<vector<int> > arr2(arr1);
	int row1, row2;
	cin >> casenum;
	for (int k = 1; k <= casenum; ++k)
	{
	cin >> row1;
	row1--;
	for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j)
				cin >> arr1[i][j];
	}
	cin >> row2;
	row2--;
	for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j)
				cin >> arr2[i][j];
	}
	int num = 0;
	int res;
	for (int i = 0; i < 4; ++i) {
		if (find(arr1[row1].begin(), arr1[row1].end(), arr2[row2][i]) != arr1[row1].end()) {
			res = arr2[row2][i];
			num++;
		}
	} 
	cout << "Case #" << k << ": ";
	if (num == 1)
		cout << res << endl; 
	else if (num == 0)
		cout << "Volunteer cheated!" << endl;
	else
		cout << "Bad magician!" << endl;
	}
}
