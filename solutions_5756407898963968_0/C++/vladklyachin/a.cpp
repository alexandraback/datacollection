#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char ** argv)
{
	if (argc != 3) {
		cerr << "Usage: infile outfile\n";
		return 1;
	}
	ifstream fi(argv[1]);
	if (!fi) {
		cerr << argv[1] << ": " << strerror(errno) << endl;
		return 1;
	}
	ofstream fo(argv[2]);
	if (!fo) {
		cerr << argv[2] << ": " << strerror(errno) << endl;
		return 1;
	}

	int T;
	fi >> T;
	for (int i = 1; i <= T; ++i) {
		int R1, R2;
		vector<int> a1(16), a2(16);
		fi >> R1;
		for (int j = 0; j < 16; ++j) {
			fi >> a1[j];
		}
		fi >> R2;
		for (int j = 0; j < 16; ++j) {
			fi >> a2[j];
		}
		auto p1 = a1.begin() + R1*4 - 4;
		auto p2 = a2.begin() + R2*4 - 4;
		sort(p1, p1+4);
		sort(p2, p2+4);
		vector<int> b(4);
		auto it = std::set_intersection (p1, p1+4, p2, p2+4, b.begin());
		b.resize (it-b.begin());
		switch (b.size()) {
		case 0:
			fo << "Case #" << i << ": Volunteer cheated!" << endl;
			break;
		case 1:
			fo << "Case #" << i << ": " << b[0] << endl;
			break;
		default:
			fo << "Case #" << i << ": Bad magician!" << endl;
			break;
		}
	}
}

/* vim: set ts=4 sw=4 noet: */
