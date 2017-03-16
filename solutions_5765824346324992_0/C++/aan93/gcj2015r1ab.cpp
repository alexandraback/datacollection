#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
ifstream in("in.txt");
ofstream out("out.txt");
long long int t,b,n;
vector <long long int> m,d,e;
int main()
{
	in >> t;
	for(long long int i=1;i<=t;i++)
	{
		in >> b >> n;
		m.resize(b);
		d.resize(b);
		e.resize(b);
		for (int j=0;j<b;j++) in >> m[j];
		if (n>b) {
			long long int a1 = 0, a2 = 100000*n, a,c;
			while (a1 < a2) {
				a = (a1+a2)/2;
				c = 0;
				for (int j=0;j<b;j++) c += a/m[j];
				if (c < n-b) {
					a1 = a+1;
				} else {
					a2 = a;
				}
			}
			a = (a1+a2)/2;
			c = 0;
			for (int j=0;j<b;j++) {
				c += a/m[j];
				d[j] = a/m[j]*m[j];
				e[j] = j+1;
			}
		//	cout << i << "\t" << a << "\t" << c << "\t" << n << "\t" << b << "\n";
			n = n-c;
			for (int j=0;j<b;j++) for (int k=0;k<j;k++) if (d[j]<d[k] || (d[j]==d[k] && e[j]<e[k])) {
				swap(d[j],d[k]);
				swap(e[j],e[k]);
			}
		//	for (int j=0;j<b;j++) cout << i << "\t" << j << "\t" << d[j] << "\t" << e[j] << "\n";
			out << "Case #" << i << ": " << e[n-1] << "\n";
		}
		else out << "Case #" << i << ": " << n << "\n";
	}
	return 0;
}
