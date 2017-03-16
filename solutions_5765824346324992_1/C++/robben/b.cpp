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

vector<int> v;

long long numPpl(long long time) {
	long long num = 0;
	for(unsigned int i = 0; i < v.size(); i++) {
		num += ceil((double)time/v[i]);
	}
	return num;
}

int main() {
	ifstream in("B-large.in");
	ofstream out("outBlarge.out");

	int t;
	in >> t;
	
	for(int z = 0; z < t; z++){
		long long n;
		int b;
		in >> b >> n;
		int res = -1;
		for(int i = 0; i < b; i++) {
			int temp;
			in >> temp;
			v.push_back(temp);
		}
		long long time = 1;
		cout << "case " << z << endl; 
		cout << n << endl;
		while(numPpl(time) < n) {
			cout << numPpl(time) << endl;
			time *= 2;
		}
		cout << numPpl(time) << endl;
		cout << time << endl;
		long long up = time; 
		long long low = time/2;
		while(up - low > 1) {
			long long mid = (up+low)/2;
			if(numPpl(mid) >= n) {
				up = mid;
			}
			else {
				low = mid;
			}
		}

		if(numPpl(low) < n && numPpl(low+1) >= n)
			low = low+1;
		if(numPpl(low+1) < n && numPpl(low+2) >= n)
			low = low +2;
		int rank;
		rank = n - numPpl(low-1)-1;
		cout << "low: " << low << endl;
		cout << "numPpl low: " << numPpl(low) << endl;
		cout << "rank: " << rank << endl;
		for(int j = 0; j < b; j++){
			if(ceil((double)low/v[j]) > ceil((double)(low-1)/v[j])){
				if(rank > 0){
					rank --;
					continue;
				}
				res = j+1;
				break;
			}
		}
		out << "Case #" << z+1 << ": " << res << endl;
		v.clear();

	}
	out.close();
	return 0;
}
