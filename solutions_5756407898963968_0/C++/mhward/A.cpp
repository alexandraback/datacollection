#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


int main() {
	int kases;
	cin >> kases;

	for (int i = 0; i < kases; ++i) {

		// input the two rows into vectors
		int ra, rb; // row a and row b
		int tmp; // temp variable used for inputs
		// ran = row a numbers
		vector<int> ran;
		// rbn = row b numbers
		vector<int> rbn;

		cin >> ra;
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k) {
				cin >> tmp;
				if (j+1 == ra)
					ran.push_back(tmp);
			}
		cin >> rb;
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k) {
				cin >> tmp;
				if (j+1 == rb)
					rbn.push_back(tmp);
			}

		// do a set intersection
		vector<int> result;
		sort(ran.begin(), ran.end());
		sort(rbn.begin(), rbn.end());
		set_intersection(ran.begin(), ran.end(), rbn.begin(), 
			rbn.end(), back_inserter(result));


		// output answer
		cout << "Case #" << i+1 << ": ";
		if (result.size() == 1) 
			cout << result[0];
		else if(result.size() > 1)
			cout << "Bad magician!";
		else
			cout << "Volunteer cheated!";
		cout << endl;

	}

	return 0;
}