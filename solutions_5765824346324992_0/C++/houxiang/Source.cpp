#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <assert.h>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <functional>

#include <Windows.h>

using namespace std;

struct Rec {
	int id;
	long long used; 
	Rec(int aid) : id(aid), used(0) {}
};

bool operator<(Rec& r1, Rec& r2) {
	if (r1.used < r2.used) return true;
	if (r1.used == r2.used) {
		if (r1.id < r2.id)
			return true;
	}
	return false;
}

long long gcd(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b); 
}

long long gcb(long long a, long long b) {
	return a / gcd(a, b) * b; 
}

int main(int argc, char* argv[]) {
	ifstream inf(argv[1]);

	int TC = 0;
	inf >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		int bar, n; 
		inf >> bar >> n; 
		vector<int> master(bar+1); 
		vector<Rec> consume;

		long long usedTime = 1; 

		for (int i = 1; i <= bar; i++) {
			inf >> master[i];
			consume.push_back(Rec(i));
			usedTime = gcb(usedTime, master[i]); 
		}

		long long usedCustomer = 0; 
		for (int i = 1; i <= bar; i++) {
			usedCustomer += usedTime / master[i]; 
		}

		int m = n % usedCustomer; 
		if (m == 0)
			m = usedCustomer; 

		for (int i = 0; i < (m-1); i++) {
			sort(consume.begin(), consume.end()); 
			consume[0].used += master[consume[0].id];
		}

		sort(consume.begin(), consume.end());

		cout << "Case #" << tc << ": " << consume[0].id << endl;
	}

	return 0;
}