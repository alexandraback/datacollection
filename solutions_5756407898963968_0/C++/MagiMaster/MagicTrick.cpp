#include <iostream>
using namespace std;

class MagicTrick {
public:
	void go(istream &in, ostream &out) {
		int t, x, n1[6], n2[6], r;
		in >> t;
		
		for (int i = 1; i <= t; ++i) {
			r = 0;

			in >> x;

			for (int j = 1; j <= 4; ++j) {
				for (int k = 1; k <= 4; ++k) {
					in >> n1[k];
					if (j == x)
						n2[k] = n1[k];
				}
			}

			in >> x;

			for (int j = 1; j <= 4; ++j) {
				for (int k = 1; k <= 4; ++k) {
					in >> n1[k];
					if (j == x) {
						for (int l = 1; l <= 4; ++l) {
							if (n1[k] == n2[l]) {
								if (r != 0)
									r = -1;
								else
									r = n1[k];
							}
						}
					}
				}
			}

			out << "Case #" << i << ": ";
			if (r == -1)
				out << "Bad magician!" << endl;
			else if (r == 0)
				out << "Volunteer cheated!" << endl;
			else
				out << r << endl;
		}
	}
};