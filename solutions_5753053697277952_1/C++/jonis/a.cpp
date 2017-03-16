#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int T;
	cin>>T;
	for(int t=1;t<=T;t++) {
		printf("Case #%d:", t);
		int n;
		cin>>n;
		vector<pair<int, char> > v(n);
		int sum = 0;
		for (int i=0;i<n;i++) {
			cin>>v[i].first;
			sum += v[i].first;
			v[i].second = 'A'+i;
		}
		while(sum > 0) {
			sort(v.begin(), v.end());
			reverse(v.begin(), v.end());
			cout << " " << v[0].second;
			v[0].first--;
			sum--;
			if (2 * v[1].first > sum) {
				cout << v[1].second;
				v[1].first--;
				sum--;
			}
		}
		cout << endl;
	}
	return 0;
}
