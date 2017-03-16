
#include <iostream>

using namespace std;

const int MAX_UNHAP = 25;
const int MAX_OSAZ = 65536;

struct Input {
	int R;
	int C;
	int N;
};

struct Output {
	int unhap;
};

int bitsset(int x) {
	x = x - ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	return (((x + (x >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int getunhap(int R, int C, int code) {
	int count = 0;

	// verticals
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C - 1; c++) {
			if (((code >> (c + C * r)) & 3) == 3) {
				//cout << "vert at " << r << " " << c << endl;
				//cout << "anal: code = " << code << ", code2 = " << (code >> (c + C * r)) << ", anded = " << ((code >> (c + C * r)) & 3) << endl;
				count++;
			}
		}
	}

	// horizontals
	for (int r = 0; r < R - 1; r++) {
		for (int c = 0; c < C; c++) {
			int p1 = c + C * r;
			int p2 = p1 + C;
			if (((code >> p1) & 1) == 1 && ((code >> p2) & 1) == 1) {
				//cout << "horiz at " << r << " " << c << endl;
				count++;
			}
		}
	}

	return count;
}

Output compute(Input in) {
	Output out;
	
	int min = MAX_UNHAP;
	for (int i = 0; i < (1 << (in.R * in.C)); i++) {
		if (bitsset(i) != in.N) continue;
		int unhap = getunhap(in.R, in.C, i);
		//cout << "code " << i << " makes " << unhap << endl;
		if (unhap < min) min = unhap;
		if (min == 0) break;
	}

	out.unhap = min;
	return out;
}

ostream & operator << (ostream & out, const Output & output) {
	return (out << output.unhap);
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		Input in;
		cin >> in.R;
		cin >> in.C;
		cin >> in.N;

		Output out = compute(in);
		cout << "Case #" << t << ": " << out << endl;
	}

	return 0;
}
