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
int t,n;
vector <int> m;
int main()
{
	in >> t;
	for(int i=1;i<=t;i++)
	{
		in >> n;
		m.resize(n);
		for (int j=0;j<n;j++) in >> m[j];
		int a = 0,b = 0,c = 0;
		for (int j=1;j<n;j++) if (m[j]<m[j-1]) {
			a += m[j-1] - m[j];
			c = max(c,m[j-1] - m[j]);
		}
		for (int j=0;j<n-1;j++) {
			if (m[j]<c) {
				b += m[j];
			} else {
				b += c;
			}
		}
		out << "Case #" << i << ": " << a << " " << b << "\n";
	}
	return 0;
}
