#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("C-small-attempt1.in");
	ofstream fout("output.txt");
	long long n, t, min, now1, now2;
	long long x[10000], y[10000], temp, a, b, c;
	fin >> t;
	for (int kk=0; kk<t; kk++) {
		fin >> n;
		for (int i=0; i<n; i++)
			fin >> x[i] >> y[i];
		fout << "Case #" << kk+1 << ":" << endl;
		for (int i=0; i<n; i++) {
			min = 10000;
			for (int j=0; j<n; j++) {
				if (i==j) continue;
				a = y[i] - y[j];
				b = x[j] - x[i];
				c = y[i]*(x[i]-x[j])+(y[j]-y[i])*x[i];
				now1 = 0; now2 = 0;
				for (int k=0; k<n; k++) {
					if (k==i || k==j) continue;
					temp = a*x[k]+b*y[k]+c;
					if (temp>0) now1++;
					if (temp<0) now2++;
				}
				if (now1 < min) min = now1;
				if (now2 < min) min = now2;
			}
			if (n<=3) fout << 0 << endl; else fout << min << endl;
		}
	}
	fin.close();
	fout.close();
}
