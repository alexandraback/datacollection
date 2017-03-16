#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int TC;
	cin >> TC;
	for (int ii=1; ii<=TC; ii++) {
		int n;
		cin >> n;
		vector<string> data(n);
		vector<vector<int> > counter(n, vector<int>());
		bool valid = true;
		for (int i=0;(i<n); i++) {
			cin >> data[i];
			string tmp = "";
			char last = data[i][0];
			for (int j=0; j<data[i].size(); j++) {
				int cnt = counter[i].size();
				counter[i].push_back(0);
				while (data[i][j] == last) {
					counter[i][cnt]++;
					j++;
				}
				tmp += last;
				last = data[i][j];
				j--;
			}
			data[i] = tmp;
			if (i > 0) {
				if (data[i-1] != tmp) {
					valid = false;
				}
			}
		}

		if (valid) {
			int totalprice = 0;
			for (int j=0; j<counter[0].size(); j++) {
				int minprice = -1;
				for (int x=1; x<=100; x++) {
					int price = 0;
					for (int i=0; i<n; i++) {
						//cout << counter[i][j] << " " << x << endl;
						price += abs(counter[i][j]-x);
					}
					
					if ((minprice == -1) ||(minprice > price)) {
						minprice = price;
						//cout << minprice << " " << x << endl;
					}
				}
				
				if (minprice == -1) cout << "AAAAA\n";
				totalprice+= minprice;
			}
			printf ("Case #%d: %d\n",ii, totalprice);
			//cout << endl << totalprice << endl;
		} else {
			printf ("Case #%d: Fegla Won\n",ii);
		}
		
	}
}
