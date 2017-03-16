#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int get_orientation(long long px, long long py, long long qx, long long qy, long long rx, long long ry)
{
    long long val = (qy - py) * (rx - qx) - (qx - px) * (ry - qy);

    if (val == 0) return 0;
    else if(val > 0) return 1;
    else return -1;
}

int main(int argc, char** argv) {

	ifstream fin(argv[1]);
	int n;

	fin >> n;
	for(int iter = 1; iter <= n; iter++) {
		int m;
		vector<long long> px, py;
		fin >> m;
		px.resize(m);
		py.resize(m);
		for(int i = 0; i < m; i++) {
			fin >> px[i] >> py[i];
		}
		cout << "Case #" << iter << ":" << endl;

		for(int i = 0; i < m; i++) {
			int min_cut;

			if(m < 3) {
				min_cut = 0;
			}
			else {
				min_cut = m - 3;
			}


			for(int j = 0; j < m; j++) {
				if(i == j) continue;
				int clockwise = 0;
				int counter_clockwise = 0;
				for(int k = 0; k < m; k++) {
					if(k == i || k == j) continue;
					int orientation = get_orientation(px[i], py[i], px[j], py[j], px[k], py[k]);
					if(orientation > 0) clockwise++;
					else if(orientation < 0) counter_clockwise++;

					if(clockwise >= min_cut && counter_clockwise >= min_cut) break;
				}

				if(clockwise < min_cut) min_cut = clockwise;
				if(counter_clockwise < min_cut) min_cut = counter_clockwise;
			}

			cout << min_cut << endl;
		}
	}
	fin.close();
}