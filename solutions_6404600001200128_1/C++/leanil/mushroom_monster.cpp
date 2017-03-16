#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	int T;
	in >> T;
	for (int test = 1; test <= T; test++) {
		int N;
		in >> N;
		vector<int> mushrooms(N);
		copy_n(istream_iterator<int>(in), N, mushrooms.begin());
		int res1 = 0, max_steep = 0;
		for (int i = 0; i < N - 1; i++) {
			if (mushrooms[i] > mushrooms[i + 1]) {
				res1 += mushrooms[i] - mushrooms[i + 1];
				max_steep = max(max_steep, mushrooms[i] - mushrooms[i + 1]);
			}
		}

		int res2 = 0;
		for (int i = 0; i < N - 1; i++) {
			res2 += min(mushrooms[i], max_steep);
		}

		out << "Case #" << test << ": " << res1 << " " << res2 << endl;
	}
	return 0;
}