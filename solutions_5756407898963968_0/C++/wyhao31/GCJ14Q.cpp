#include <iostream>
#include <fstream>
using namespace std;

ifstream in("A-small-attempt0.in.txt");
ofstream out("A-small-out");
//#define in cin
//#define out cout

int main()
{
	int T;
	bool flag[17];
	in >> T;
	for (int cnt = 1; cnt <= T; cnt++) {
		memset(flag, 0, sizeof(flag));
		int a1, a2, t;
		in >> a1;
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				in >> t;
				if (a1 == i) flag[t] = true;
			}
		}
		in >> a2;
		int hit = 0, res;
		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 4; j++) {
				in >> t;
				if (a2 == i && flag[t] == true) {
					hit++;
					res = t;
				}
			}
		}
		out << "Case #" << cnt << ": ";
		if (hit == 1) out << res;
		else if (hit == 0) out << "Volunteer cheated!";
		else out << "Bad magician!";
		out << endl;
	}
	return 0;
}