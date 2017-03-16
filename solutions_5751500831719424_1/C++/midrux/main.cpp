#include <iomanip>
#include <algorithm>
#include <iterator>     // std::insert_iterator
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>

using namespace std;
int N;

int main(){
	ifstream in("A.in");
	ofstream out("result.txt");
	int TESTS; 
	in >> TESTS;
	for(int test = 0; test<TESTS; test++){
		cout << "Case #" << test+1 << ": ";
		out << "Case #" << test+1 << ": ";
		in >> N;
		vector<string> s(N),ss(N);
		for(int i = 0; i<N; i++){
			in >> s[i];
			string tmp; tmp += s[i][0];
			for(int j = 1; j<s[i].size(); j++)
				if(s[i][j] != s[i][j-1]) tmp += s[i][j];
			ss[i] = tmp;
		}

		bool valid = true;
		for(int i = 1; i<N; i++)
			if(ss[i] != ss[i-1]) valid = false;

		if(!valid){
			cout << "Fegla Won" << endl;
			out << "Fegla Won" << endl;
			continue;
		}

		
		int ret = 0;
		while(1){
			int sz = s[0].size();
			if(sz == 0) break;
			vector<int> nums;
			for(int i = 0; i<N; i++){
				int k = s[i].size()-1;
				int amount = 1;
				while(k>0 && s[i][k] == s[i][k-1]){
					amount++;
					k--;
				}
				for(int j = 0; j<amount; j++) s[i].pop_back();
				nums.push_back(amount);
			}
			sort(nums.begin(), nums.end());
			int best = 99999;
			for(int k = nums[0]; k<=nums[nums.size()-1]; k++){
				int tmp = 0;
				for(int u = 0; u<nums.size(); u++)
					tmp += abs(nums[u]-k);
				best = min(best, tmp);
			}
			ret += best;
		}
		

		cout << ret << endl;
		out << ret << endl;
//		cout << ret << endl;
//		out << ret << endl;
	}
	return 0;
}
