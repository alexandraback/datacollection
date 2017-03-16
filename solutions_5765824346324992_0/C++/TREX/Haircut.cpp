#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


int main() {
	int t;
	fstream f, f2;
	f.open("a.txt");
	f2.open("output.txt", ios::out);
	f >> t; int n1 = t;
	int b; long n; long lcm, lnsum;
	int *time, *newTime;
	while (t--) {
		f >> b >> n;
		lcm = 1; lnsum = 0;
		time = new int[b];
		for (int i = 1; i <= b; i++) {
			f >> time[i - 1]; 
			lcm *= time[i - 1];
		}
		for (int i = 0; i <= b; i++) {
			lnsum += (lcm / time[i]);
		}
		int k;
		for (k = 0; lnsum*k < n; k++);
		n -= lnsum*(k - 1);
		if (n <= b) {
			f2 << "Case #" << n1 - t << ": " << n << endl;
			delete time;
		}
		else {
			n = n - b;
			newTime = new int[b];
			for (int i = 1; i <= b; i++) {
				newTime[i - 1] = time[i - 1];
			}
			bool found = false; long minTime;
			while (!found) {
				minTime = newTime[0];
				for (int i = 0; i < b; i++) {
					if (newTime[i] < minTime) {
						minTime = newTime[i];
					}
				}
				for (int i = 0; i < b; i++) {
					newTime[i] -= minTime;
				}
				for (int i = 0; i < b; i++) {
					if (newTime[i] == 0) {
						n--;
						newTime[i] += time[i];
						if (n == 0) {
							f2 << "Case #" << n1 - t << ": " << i + 1 << endl;
							found = true;
							break;
						}
					}
				}
			}
			delete time; delete newTime;
		}
	}
	f.close(); f2.close();
	return 0;
}