#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define sz(v) int(v.size())
typedef long long ll;
typedef pair<int,int> pii;

bool mark[16];

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		for(int i = 0; i < 16; i++)
			mark[i] = 1;
		for(int _ = 0; _ < 2; _++) {
			int choice, tmp;
			cin >> choice; choice--;
			for(int i = 0; i < 4; i++)
				for(int j = 0; j < 4; j++) {
					cin >> tmp; tmp--;
					if(i != choice)
						mark[tmp] = false;
				}
		}
		int cnt = 0, ans = 0;
		for(int i = 0; i < 16; i++)
			if(mark[i]) {
				cnt++;
				ans = i+1;
			}
		cout << "Case #" << t << ": ";
		if(cnt == 0)
			cout << "Volunteer cheated!";
		else if(cnt == 1)
			cout << ans;
		else
			cout << "Bad magician!";
		cout << endl;
	}
	return 0;
}
