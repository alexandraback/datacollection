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
	ifstream in("A-small-attempt0.in");
	ofstream out("outA.out");
	
	int t;
	in >> t;
	for(int i =0; i < t; i++){
		int n;
		in >> n;
		vector<int> v;
		for(int j = 0; j < n; j++){
			int temp;
			in >> temp;
			v.push_back(temp);
		}
		int one = 0;
		int two = 0;
		double max_rate = 0;
		for(int j = 1; j < n; j++){
			if(v[j] < v[j-1]){
				int rate = v[j-1]-v[j];
				one += rate;
				if(rate > max_rate)
					max_rate = rate;
			}
		}
		for(int j = 0; j < n-1; j++){
			if(v[j] < max_rate)
				two += v[j];
			else
				two += max_rate;
		}
		out << "Case #" << i+1 << ": " << one << " " << two << endl;
	}
	out.close();

	return 0;
}
