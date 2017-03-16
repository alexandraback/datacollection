#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ifstream in("B-large.in");
	ofstream out;
	out.open("large.out");
	int t; 
	in >> t;
	cout << t << endl;
	for(int z = 0; z < t; z++) {
		int r, c, n;
		int ret = 0;
		in >> r >> c >> n;
		int empty = r*c - n;
		int tot = r*(c-1) + c*(r-1);
		if(r*c == 2 && n == 2){
			ret = 1;
		}
		cout << r << " " << c << " " << n << endl;
		if(r == 1 || c == 1) {
			if(n <= ceil((double)r*c/2.0)){
				ret = 0;
			}
			else {
				ret = tot - empty*2;
			}
		}
		else if(n <= ceil((double)r*c/2.0)){
			ret = 0;
		}
		else if(r*c % 2 == 0 ) {
			cout << "even" << endl;
			if(r >= 3 && c >= 3 && empty <= (r-2)*(c-2)/2) {
				ret = tot - 4*empty;
			}
			else if(empty <= r*c/2-2){
				ret = tot - 3*empty - (r-2)*(c-2)/2;
				cout << "(r)*(c)/2" << endl;
			}
			else {
				ret = 2;
			}
		}
		else {
			if(empty <= ceil((r-2)*(c-2)/2.0)){
				ret = tot - 4*empty;
			}
			else if (empty <= ceil((r-2)*(c-2)/2.0) + r + c -6 ) {
				ret = tot - 3*empty -ceil((r-2)*(c-2)/2.0) ;
			}
			else {
				/**
				int cur = 4*ceil((r-2)*(c-2)/2.0);
				cur += (empty - ceil((r-2)*(c-2)/2.0)) * 3;*/
				ret = tot - 3*empty - floor((r-2)*(c-2)/2.0);
			}

		}
		out << "Case #" << z+1 << ": " << ret << endl;
	}

	out.close();
	return 0;
}
