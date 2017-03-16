#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("A-large.in");
	ofstream fout("output.txt");
	int n, t;
	int a[100000];
	fin >> t;
	int ans1, ans2, max, now;
	for (int k=0; k<t; k++) {
		fin >> n;
		for (int i=0; i<n; i++)
			fin >> a[i];
		ans1 = 0;
		max = 0;
		for (int i=0; i<n-1; i++)
			if (a[i]>a[i+1]) {
				now = a[i] - a[i+1];
				ans1 += now;
				if (now > max) max = now;
			}
		ans2 = 0;
		for (int i=0; i<n-1; i++) {
			if (a[i] > max) ans2 += max; else ans2 += a[i];
		}	
		fout << "Case #" << k+1 << ": " << ans1 << " " << ans2 << endl;
	}
	fin.close();
	fout.close();
}
