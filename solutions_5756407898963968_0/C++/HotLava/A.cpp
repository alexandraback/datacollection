#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

template<typename T>
ostream& operator<<(ostream& str, const vector<T>& v) {
	str << "[";
	for(auto n : v) {
		str << n << ", ";
	}
	str << "]";
	return str;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int row1;
		cin >> row1;

		set<int> r1;

		for (int i = 1; i <= 4; ++i)
		{
			
				for (int k = 1; k <= 4; ++k)
				{
					int j;
					cin >> j;
					if(i == row1) 
						r1.insert(j);
				}
			
		}


		int row2;
		cin >> row2;

		set<int> r2;

		for (int i = 1; i <= 4; ++i)
		{
			
				for (int k = 1; k <= 4; ++k)
				{
					int j;
					cin >> j;
					if(i == row2) 
						r2.insert(j);
				}
			
		}

		vector<int> v(8);
		auto nend = set_intersection(r1.begin(), r1.end(), r2.begin(), r2.end(), v.begin());
		int dist = distance(v.begin(), nend);
		if(dist == 0) {
			cout << "Case #" << i+1 << ": Volunteer cheated!" << endl;
		} else if (dist == 1) {
			cout << "Case #" << i+1 << ": " << *v.begin() << endl;
		} else {
			cout << "Case #" << i+1 << ": Bad magician!" << endl;
		}


	}
}