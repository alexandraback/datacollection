#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long ll;

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; ++t){
		int N;
		cin >> N;
		vector<int> mushrooms(N, 0);
		for (auto& i : mushrooms){
			cin >> i;
		}

		int firstAns = 0, secondAns = 0;
		int biggistGap = 0; //  always eat this in #2 way
		for (int i = 0; i < N - 1; ++i){
			int gap = mushrooms[i] - mushrooms[i + 1];
			if (gap > 0){
				firstAns += gap;
				biggistGap = max(gap, biggistGap);
			}
		}

		for (int i = 0; i < N - 1; ++i){
			int gap = mushrooms[i] - mushrooms[i + 1];
			if (mushrooms[i] - biggistGap >= 0)
				secondAns += biggistGap;
			else
				secondAns += mushrooms[i];
		}

		cout << "Case #" << t << ": " << firstAns << ' ' << secondAns << endl;
	}
	return 0;
}