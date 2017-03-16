#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	string letters;
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int result1, result2;
		int n;
		cin >> n;
		int m[2000];
		for(int i = 0; i < n; i++){
			cin >> m[i];
		}
		int maxx = 0;
		result1 =0;
		result2= 0;
		for(int i = 0; i < n - 1; i++){
			int temp = m[i] - m[i + 1];
			if (temp > 0)
				result1 += temp;
			if (temp > 0 && temp > maxx){
				maxx = temp;
			}
		}

		for(int i = 0; i < n - 1; i++){
			if (m[i] < maxx)
				result2 += m[i];
			else
				result2 += maxx;
		}
		cout << "Case #" << tt << ": " << result1 << " " << result2 << endl;
	}
	return 0;
}