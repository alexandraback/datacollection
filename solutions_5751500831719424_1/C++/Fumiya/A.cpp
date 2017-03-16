#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

string conv(const string& s, vector<int>& v){
	int cnt = 1;
	string res;
	res += s[0];
	char c = s[0];
	for(int i=1;i<s.size();i++){
		if(c == s[i]) cnt++;
		else {
			v.push_back(cnt);
			cnt = 1;
			c = s[i];
			res += c;
		}
	}
	v.push_back(cnt);
	return res;
}

int main(){
	int T; cin >> T;
	for(int test=1;test<=T;test++){
		int N; cin >> N;
		vector< vector<int> > v(N);
		bool won = true;
		string s, t;
		cin >> s;
		t = conv(s, v[0]);
		for(int i=1;i<N;i++){
			cin >> s;
			string u = conv(s, v[i]);
			if(u != t) won = false;
		}
		if(!won){
			printf("Case #%d: Fegla Won\n", test);
			continue;
		}
		int res = 0;
		for(int i=0;i<v[0].size();i++){
			int add = 1000000;
			for(int j=1;j<=100;j++){
				int sum = 0;
				for(int k=0;k<v.size();k++){
					sum += abs(v[k][i]-j);
				}
				add = min(add, sum);
			}
			res += add;
		}
		printf("Case #%d: %d\n", test, res);
	}
}