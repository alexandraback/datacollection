//be name oo
#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <sstream>
#include <set>
#include <complex>
#include <iomanip>
#include <queue>

#define FOR(i, n) for(int i = 0; i < (n); i++)
#define SZ(x) ((int)x.size())
#define PB push_back
#define show(x) cerr << "#" << #x << ": " << x << endl
#define F first
#define S second
#define X real()
#define Y imag()

using namespace std;
typedef pair<int, int> pii;
typedef complex<double> point;

const int MAX_N = 200 + 10;

string unique_string(string str){
	return string(str, 0, unique(str.begin(), str.end()) - str.begin());
}

int counter[MAX_N];

int go(string str, int start){
	int ret = 0;
	int pos = start;
	while(pos < SZ(str) && str[pos++] == str[start])
		ret++;
	return ret;
}

int cost(vector<int> nums){
	sort(nums.begin(), nums.end());
	int ret = 0;
	FOR(i, SZ(nums))
		ret += abs(nums[SZ(nums) / 2] - nums[i]);
	return ret;
}

int main(){
	int num_test_case;
	cin >> num_test_case;
	for(int _test = 1; _test <= num_test_case; _test++){
		cout << "Case #" << _test << ": ";
		int n;
		cin >> n;
		vector<string> strings;
		bool impossible = false;
		FOR(i, n){
			string str;
			cin >> str;
			strings.PB(str);
			if(unique_string(str) != unique_string(strings[0]))
				impossible = true;
		}
		if(impossible){
			cout << "Fegla Won\n";
			continue;
		}
		int ans = 0;
		memset(counter, 0, sizeof counter);
		while(counter[0] < SZ(strings[0])){
			vector<int> nums;
			FOR(i, n){
				int num = go(strings[i], counter[i]);
				nums.PB(num);
				counter[i] += num;
			}
			ans += cost(nums);
		}
		cout << ans << endl;
	}
	return 0;
}

