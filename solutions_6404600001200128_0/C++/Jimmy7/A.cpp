#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,N;
	int nums[1500];
	cin >> T;
	for (int t = 0 ; t < T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin>>nums[i];
		}
		long long total1 = 0;
		for (int i = 0; i < N-1; i++) {
			if (nums[i+1] < nums[i] ) {
				total1+=(nums[i]-nums[i+1]);
			}
		}
		long long total2 = 0;
		long long maxDif = 0;
		for (int i = 0; i < N-1; i++) {
			maxDif = max(maxDif, (long long)(nums[i]-nums[i+1]));
		}
		for (int i = 0; i < N-1; i++) {
			total2+=min(maxDif,(long long)(nums[i]));
		}
		cout << "Case #" << t+1 << ": " << total1 << " " << total2 << endl;
	}
	return 0;
}