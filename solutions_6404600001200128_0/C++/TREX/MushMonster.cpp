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
	int n, *mushrooms;
	while (t--) {
		f >> n;
		mushrooms = new int[n];
		for (int i = 0; i < n; i++) {
			f >> mushrooms[i];
		}
		long method1 = 0;
		for (int i = 0; i < n-1; i++) {
			if (mushrooms[i] > mushrooms[i + 1]) {
				method1 += mushrooms[i] - mushrooms[i + 1];
			}
		}
		long rate = mushrooms[0] - mushrooms[1], method2 = 0;
		for (int i = 0; i < n - 1; i++) {
			if (mushrooms[i] - mushrooms[i + 1] > rate) {
				rate = mushrooms[i] - mushrooms[i + 1];
			}
		}
		for (int i = 0; i < n-1; i++) {
			if (mushrooms[i] <= rate) {
				method2 += mushrooms[i];
			}
			else {
				method2 += rate;
			}
		}
		f2 << "Case #" << n1 - t << ": " << method1 << " " << method2 << endl;
		delete mushrooms;
	}
	f.close(); f2.close();
	return 0;
}