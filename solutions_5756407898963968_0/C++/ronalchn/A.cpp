#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int T, X;
  cin >> T;
  for (int t=1;t<=T;t++) {
		vector<int> v;
		for (int i=1;i<=16;i++) v.push_back(i);
		for (int i=0;i<2;i++) {
			cin >> X;
			vector<int> row, ans(4);
			int x;
			for (int j=1;j<=4;j++) {
				for (int k=1;k<=4;k++) {
					cin >> x;
					if (j==X) row.push_back(x);
				}
			}
			sort(row.begin(),row.end());
			vector<int>::iterator it = set_intersection(v.begin(),v.end(),row.begin(),row.end(),ans.begin());
			ans.resize(it-ans.begin());
			v=ans;
		}
		printf("Case #%d: ", t);
		if (v.size()==1) {
			cout << v[0] << endl;
		}
		else if (v.empty()) cout << "Volunteer cheated!" << endl;
		else cout << "Bad magician!" << endl;
	}

  return 0;
}
