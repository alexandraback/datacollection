#include <iostream>
#include <fstream>
#include <string>
#include <vector>



using namespace std;

int t;


int main() {

	ifstream fin("A-small-attempt3.in", ifstream::in);
	ofstream fout("result.out", ofstream::out);
	fin >> t;
//	cin >> t;
	int n, m;
	vector<int> ms;
	for(int i = 0; i < t; ++i) {
		fin >> n;
//		cin >> n;
		int nn = n;
		ms.clear();
		while(nn--) {
			fin >> m;
//			cin >> m;
			cout << m << " ";
			ms.push_back(m);
		}
		cout << endl;
		int y = 0, z = 0;
		int max_d = 0, d = 0;
		for(int j = 1; j < n; ++j) {
			d = ms[j-1] - ms[j];			
			if(d > 0) {
				y += d;
				if(d > max_d)
					max_d = d;
			}
		}
		for(int j = 0; j < n-1; ++j) {
			if(ms[j] > max_d) {				
				z += max_d;
			}
			else {
				z += ms[j];
			}
		}
		cout << "Case #" << (i+1) << ": " <<  y << " " << z << endl;
		fout << "Case #" << (i+1) << ": " <<  y << " " << z << endl;
	}
	
	return 0;
}
