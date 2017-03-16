#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

//#define GEN_LOCAL_TEST
#define USE_LOCAL_TEST

#ifdef GEN_LOCAL_TEST
void genTest() {
	ofstream ofs("test.txt", ifstream::out);
	int n = 100000;
	ofs << n << endl;
	for (int i = 0; i < n; ++i)
		ofs << 0 << " ";
	ofs << endl;
	ofs.close();
}
#endif

int main(int argc, char* argv[])
{

	ifstream ifs("test.txt", ifstream::in);
	ofstream ofs("ans.txt", ifstream::out);

	int t;
	ifs >> t;

	int a1, a2, val;
	vector<int> v1, v2;
	for (int idx = 0; idx < t; ++idx) {
		v1.clear();
		v2.clear();
		ifs >> a1;
		--a1;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ifs >> val;
				if (i != a1) continue;
				v1.push_back(val);
			}
		}
		ifs >> a2;
		--a2;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				ifs >> val;
				if (i != a2) continue;
				v2.push_back(val);
			}
		}
		int qt = 0;
		int id = -1;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (v1[i] == v2[j]) {
					++qt;
					id = v1[i];
				}
			}
		}
		ofs << "Case #" << idx + 1 << ": ";
		if (qt == 0) {
			ofs << "Volunteer cheated!" << endl;
		}
		else if (qt == 1) {
			ofs << id << endl;
		}
		else {
			ofs << "Bad magician!" << endl;
		}
	}

	return 0;
}

