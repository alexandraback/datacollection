#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;

ifstream in;
ofstream out;
int cnt;
bool d[100000000];
#define P(r,c,d) ((r)*(d)+(c))

void clear() {
	memset(d, 0, sizeof(d));
}

int process(int r, int c, int n, int i, int lv) {
	if (lv == n) {
		int res = 0;
		// check table and calculate result
		for (int ri=0; ri<r; ri++) {
			for (int ci=0; ci<c; ci++) {
				if (d[P(ri, ci, c)] && d[P(ri, ci+1, c)] && ci<c-1)
					res++;
				if (d[P(ri, ci, c)] && d[P(ri+1, ci, c)] && ri<r-1)
					res++;
/*
				if (d[P(ri, ci, c)])
					cout << "* ";
				else
					cout << "  ";*/
			}
//			cout << "\n";
		}
//		cout << "res " << res << "\n";
		return res;
	}

	// fill from i th to end
	int min = 0x7fffffff;
	for (; i<r*c; i++) {
		d[i] = true;
		int ret = process(r, c, n, i+1, lv+1);
		if (ret < min) min = ret;
		d[i] = false;
	}

	return min;
}

int main(int argv, char **argc) {
	if (argv == 1) {
		cout << "input\n";
		return -1;
	}

	in.open(argc[1]);
	out.open("output.txt");
	in >> cnt;
	for (int i=0; i<cnt; i++) {
		int a,b,c;
		in >> a >> b >> c;
		clear();
		cout << "Case #" << i+1 << "\n";
		out << "Case #" << i+1 << ": " << process(a,b,c,0,0) << "\n";
	}

	in.close();
	out.close();

	return 0;
}
