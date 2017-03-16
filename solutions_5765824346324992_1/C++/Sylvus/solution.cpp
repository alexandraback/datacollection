#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <limits>

using namespace std;

int main () {
	int numTestCases;
	cin >> numTestCases;
	for (int i=0; i<numTestCases; ++i) {
		int B;
		long long N;
		cin >> B >> N;
		set<pair<long long, long long> > idle;
		vector<int> barbers;
		for (int j=0; j<B; ++j) {
			int temp;
			cin >> temp;
			barbers.push_back(temp);
		}
		long long n = 1;

		double sum = std::numeric_limits<double>::epsilon();
		for (int j=0; j<B; ++j) {
			sum += barbers[0]/static_cast<double>(barbers[j]);
		}
		double fraction = 1 / sum;

		for (int j=0; j<B; ++j) {
			// how much can we give to that barber.
			long long amount = (N * fraction * barbers[0])/barbers[j] - (barbers[B-1]/barbers[0] + 1);
			//cout <<fraction << " " << amount << endl;
			idle.insert(make_pair<long long, long long>(amount * barbers[j] , j));
			n += amount;
		}
		if (n>N) {
			cout << n << "Error!!" << N <<  endl;
		}
		while (n<N) {
			//cout << n << "\t\t" << N << endl;
			// we can always do at least 1/B many.
			pair<long long, long long> next = *(idle.begin());
			idle.erase(idle.begin());
			next.first += barbers[next.second];
			idle.insert(next);
			n++;
			//cout <<  "Debug" << ((*(idle.begin())).second + 1) << endl;
		}

		cout << "Case #" << (i+1) << ": " << ((*(idle.begin())).second + 1) << endl; 
	}
}
