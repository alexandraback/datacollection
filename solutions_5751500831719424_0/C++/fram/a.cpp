#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


void test(int index){
	int n;
	cin >> n;
	
	string s[100];
	for(int i=0; i<n; i++) cin >> s[i];
	
	int ans = 0;
	vector<int> mos(100);
	
	while(s[0].size() > 0){
		for(int i=0; i<n; i++) mos[i] = 0;
		
		char ca = s[0][0];
		
		for(int i=0; i<n; i++){
			if(s[i].size() == 0 || s[i][0] != ca) {cout << "Case #" << index << ": " << "Fegla Won" << '\n'; return;}
			while(s[i][0] == ca) {s[i].erase(s[i].begin()); mos[i]++;}
			
			if(s[0].size() == 0 && s[i].size() > 0) {cout << "Case #" << index << ": " << "Fegla Won" << '\n'; return;}
		}
		
		sort(mos.begin(), mos.begin()+n);
		for(int i=0; i<n; i++) {ans += abs(mos[i]-mos[n/2]);}
	}
	
	cout << "Case #" << index << ": " << ans << '\n';
}

int main(){
	int t; cin >> t;
	for(int i=1; i<=t; i++) test(i);
	return 0;
}
