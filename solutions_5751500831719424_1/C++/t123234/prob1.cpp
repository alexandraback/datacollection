#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct{
	char c;
	int num;
} chara;

vector<vector<chara> > strs;
vector<int> nums;


bool equal(vector<chara>& str1, vector<chara>& str2){
	if (str1.size()!=str2.size()) {
		return false;
	}
	for (int i=0; i<str1.size(); ++i) {
		if (str1[i].c!=str2[i].c) {
			return false;
		}
	}
	return true;
}

int main(){
	int t, i, j, k, n, r;
	
	vector<chara> str;
	chara ca;

	cin>>t;
	for (i = 1; i <= t; ++i){
		strs.clear();
		cin>>n;
		
		for (j=0; j<n; ++j) {
			string stdstr;
			cin>>stdstr;
			
			str.clear();
			ca.c = stdstr[0];
			ca.num = 1;
			str.push_back(ca);
			for (k=1; k<stdstr.length(); ++k) {
				if (stdstr[k]==str.back().c) {
					++str.back().num;
				} else {
					ca.c = stdstr[k];
					ca.num = 1;
					str.push_back(ca);
				}
			}
			
			strs.push_back(str);
//			for (k=0; k<str.size(); ++k) {
//				cout << str[k].c<<str[k].num;
//			}
//			cout << endl;
		}
		
		bool p=true;
		for (j=1; j<strs.size(); ++j) {
			if (!equal(strs[0], strs[j])) {
				p = false;
				break;
			}
		}
		
		if(p){
			r = 0;
			nums.resize(strs.size());
			for (k=0; k<strs[0].size(); ++k) {
				for (j=0; j<strs.size(); ++j) {
					nums[j] = strs[j][k].num;
				}
				sort(nums.begin(), nums.end());
				int med = nums[nums.size()/2];
				for (j=0; j<nums.size(); ++j) {
					r += abs(nums[j]-med);
				}
			}
		}

		cout<<"Case #"<<i<<": ";
		if(p) cout << r <<endl;
		else cout<<"Fegla Won"<<endl;
	}
	
	return 0;
}