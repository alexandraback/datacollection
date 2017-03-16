#include <algorithm>
#include <vector> 
#include <iostream> 
#include <string> 
#include <unordered_map> 
#include <set> 
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct strstruct {
	int single[100];
	strstruct() {
		memset(single, 0, sizeof(single));
	}
}; 
bool build(string &str, string & base, strstruct & ss) {
	bool right = true;
	int j = 0;
    for(int i=0;i<base.size();i++) {
		if(str[j] != base[i]) return false;
		while(j < str.size() && str[j] == base[i]) {
			ss.single[i] ++;
			j++;
		}
		if(j == str.size()) return i==(base.size()-1);
	}
	return false;
}
string getbase(string &str) {
	string result;
	result.append(1, str[0]);
	char pre = str[0];
	for(int i=1;i<str.size();i++) {
		if(str[i] != pre) {
			result.append(1,str[i]);
			pre = str[i];
		} 
	}
	return result;
}
int absolute(int i) {
	return i > 0 ? i: -i;
}
void solve (string strs[],int n,int id) {
	string base = getbase(strs[0]);
	int k = base.size();
	strstruct ss[n];
	for(int i=0;i<n;i++) {
		if(!build(strs[i],base,ss[i])) {
			printf("Case #%d: Fegla Won\n",id);
			return;
		}
	}
	
	
	int min = 0;
	for(int i=0;i<k;i++) {
		int tmin = INT_MAX; 
		
		for(int j=0;j<n;j++) {
			int tmp = 0;
			for(int q=0;q<n;q++) {
				tmp += absolute(ss[j].single[i] - ss[q].single[i]);
			}
			if(tmp < tmin) tmin = tmp;
		} 
		min += tmin;
	}
	printf("Case #%d: %d\n",id,min);
}

int main() {
	int t,n;
	cin >> t;
	int T = t;
	while(t--) {
		cin >> n;
		string strs[n];
		for(int i=0;i<n;i++) {
			cin >> strs[i];
		}
		solve(strs, n, T-t);
	}
}
