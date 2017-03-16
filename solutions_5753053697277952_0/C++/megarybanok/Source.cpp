#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


void main() {

	FILE *str, *abc;
	freopen_s(&str, "input.txt", "r", stdin);
	freopen_s(&abc, "out.txt", "w", stdout);

	int t;
	cin >> t;
	
	for (int tt = 0; tt < t; tt++) {
		cout << "Case #" << tt + 1 << ": ";
		
		int n, a[100], sum = 0, num;
		cin >> n;

		num = n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
			
		while (sum != 0) {

			int in1 = 0, in2, max1 = 0, max2 = 0;

			for (int i = 0; i<n; i++)
				if (a[i] > max1) {
					max2 = max1;
					in2 = in1;
					max1 = a[i];
					in1 = i;
				}
				else
					if (a[i] > max2) {
						max2 = a[i];
						in2 = i;
					}

			if (max1 == max2 && !(num==3 && max1 == 1)) {
				cout << (char)(in1 + (int)'A');
				cout << (char)(in2 + (int)'A') << " ";
				sum -= 2;
				a[in1]--; a[in2]--;
				if (a[in1] == 0) num--;
				if (a[in2] == 0) num--;
			}
			else {
				cout << (char)(in1 + (int)'A')<< " ";
				a[in1]--;
				if (a[in1] == 0) num--;
				sum--;
			}
		}
		cout << endl;
	}
		
}