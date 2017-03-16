#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#define loop(i, c) for(int i = 0; i < c; i++)

using namespace std;

int main() {
	int T;
	cin >> T;
	int b1[4], b2[4], dummy, r1, r2;
	loop(t, T) {
		cin >> r1;
		loop(i, 4) loop(j, 4)
			if(r1-1 == i) cin >> b1[j];
			else cin >> dummy;
		cin >> r2;
		loop(i, 4) loop(j, 4)
			if(r2-1 == i) cin >> b2[j];
			else cin >> dummy;
		sort(b1, b1+4);
		sort(b2, b2+4);
		vector<int> matches;
		int i = 0, j = 0;
		while(i < 4 && j < 4) {
			if(b1[i] == b2[j]) {
				matches.push_back(b1[i]);
				i++, j++;
			}
			else if(b1[i] < b2[j]) i++;
			else if(b1[i] > b2[j]) j++;
		}
		if(matches.size() == 1)
			printf("Case #%d: %d\n", t+1, matches[0]);
		else if(matches.size() > 1)
			printf("Case #%d: Bad magician!\n", t+1);
		else printf("Case #%d: Volunteer cheated!\n", t+1);
	}
}