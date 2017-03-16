#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int T;
	cin >> T;
	for (int Case = 1; Case <= T; ++Case){
		int x[17] = {};
		for (int i = 0; i < 2; ++i){
			int a;
			cin >> a;
			--a;
			for (int r = 0; r < 4; ++r){
				for (int c = 0; c < 4; ++c){
					int num;
					cin >> num;
					if (r == a) ++x[num];
				}
			}
		}

		vector<int> ans;
		for (int i = 1; i <= 16; ++i) if (x[i] == 2) ans.push_back(i);

		printf("Case #%d: ", Case);
		if (ans.size() > 1) cout << "Bad magician!" << endl;
		else if (ans.size() < 1) cout << "Volunteer cheated!" << endl;
		else cout << ans.back() << endl;
	}

	return 0;
}