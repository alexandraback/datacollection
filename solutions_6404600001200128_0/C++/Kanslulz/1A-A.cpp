#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

#define ll long long



int method2(vector<int> &v) {
	//int rate = (v[v.size() - 2] > v.back()) ? v[v.size() - 2] - v.back() : 0;
	
	int mxdif = 0;
	for (int i = 1; i < v.size(); i++)
		if (v[i] < v[i - 1])
			mxdif = max(mxdif, v[i - 1] - v[i]);
	int rate = mxdif;
	int count = 0;
	for (int i = 0; i < v.size()-1; i++)
		count += (v[i] > rate) ?  rate : v[i];
	int left = max(0, v[v.size() - 2] - rate);
	if (v.back() < left)
		count += left - v.back();
	return count;
	
	
}

int method1(vector<int> &v) {
	int count = 0;
	for (int i = 1; i < v.size(); i++)
		if (v[i] < v[i - 1])
			count += v[i - 1] - v[i];
	return count;
	
}



int main() {
	ifstream cin("in.in");
	ofstream cout("out.txt");
	int T;
	cin >> T;
	for (int idx = 1; idx <= T; idx++) {
		int N;
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++)
			cin >> v[i];
		cout << "Case #" << idx << ": " << method1(v) << " " << method2(v) << endl;
	}
	return 0;
}