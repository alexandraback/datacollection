#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <iomanip>
#include <stdlib.h>

using namespace std;
class data {
	public:
	char a;
	int n;

	data() {
		n = 0;
	}
	data(char r) {
		a = r;
		n = 0;
	}
};

int main() {
	fstream f;
	f.open("a.dat", ios::in);
	if (!f.is_open()) {
		throw "Failed to open";
	}

	int T;

	f>>T;

	for (int i =0;i<T;i++) {
		cout<<"Case #"<<(i+1)<<": ";
		int N;
		char c;
		bool fail = false;
		vector< vector<data> > cmp;
		f>>N;
		
		f>>noskipws>>c;
		for (int j = 0;j< N;j++) {
		  char oldc='\n';
		  vector<data> inp;
			f>>noskipws>>c;
			while(c != '\n') {
							if (c != oldc) {
								data indata;
								indata.a = c;	
								indata.n = 1;	
								inp.push_back(indata);	
							} else {
							  inp.back().n++;
							}
							oldc = c;
							f>>noskipws>>c;
			}
		  cmp.push_back(inp);
		}

		bool feglawon = false;
		for (int j =0; j<N;j++) {
			if (cmp[j].size() != cmp[0].size()) {
				 feglawon = true;
			}
			for (int k = 0;k<cmp[0].size();k++) {
				if (cmp[0][k].a != cmp[j][k].a) {
					feglawon = true;
				}
			}
		}
		
		if (feglawon) {
			cout<<"Fegla Won"<<endl;
			continue;
		}

		int sum=0;
		int med= N/2;
		for (int k = 0; k< cmp[0].size();k++) {
			vector<int> v;
			for (int j=0; j<N; j++) {
				v.push_back(cmp[j][k].n);
			}
			sort(v.begin(), v.end());
			for (int j=0; j<N; j++) {
				sum+=abs(v[j]- v[med]);
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
