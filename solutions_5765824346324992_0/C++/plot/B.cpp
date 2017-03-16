#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>

using namespace std;

int gcd(int a, int b){
    while(true){
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

long lcm(int a, int b){
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

long solve(int b, int n, long* m){
	vector<int> vec;
	int l = m[0];
	for(int i = 1; i < b; i++){
		l = lcm(l, m[i]);
	}
	for(int i = 0; i < l; i++){
		for(int j = 0; j < b; j++){
			if(i == 0 || i % m[j] == 0){
				vec.push_back(j + 1);
			}
		}
	}
		
	return vec.at((n - 1)%vec.size());
}

int main() {
	int t, b, n;
	long* m;
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> b >> n;
		
		m = (long*)malloc(b * sizeof(long));

		for(int j = 0; j < b; j++)
			cin >> m[j];

		cout << "Case #" << (i + 1) << ": " << solve(b, n, m) << endl;
	}
	
	return EXIT_SUCCESS;
}
