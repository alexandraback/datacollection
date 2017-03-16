#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;
typedef pair<int, int> pii;

vector<pii> convert(const string &s){
	int prev = -1;
	vector<pii> result;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] != prev){
			result.push_back(pii(s[i], 1));
		}else{
			++result.back().second;
		}
		prev = s[i];
	}
	return result;
}

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int caseNum = 1; caseNum <= T; ++caseNum){
		int n;
		cin >> n;
		vector< vector<pii> > inputs(n);
		for(int i = 0; i < n; ++i){
			string s;
			cin >> s;
			inputs[i] = convert(s);
		}
		bool accept = true;
		for(int i = 1; accept && i < n; ++i){
			if(inputs[i].size() != inputs[0].size()){
				accept = false;
			}else{
				for(int j = 0; accept && j < inputs[0].size(); ++j){
					if(inputs[0][j].first != inputs[i][j].first){
						accept = false;
					}
				}
			}
		}
		cout << "Case #" << caseNum << ": ";
		if(!accept){
			cout << "Fegla Won" << endl;
			continue;
		}
		int answer = 0;
		for(int i = 0; i < inputs[0].size(); ++i){
			int sum = 0;
			for(int j = 0; j < n; ++j){
				sum += inputs[j][i].second;
			}
			const int len = sum / n;
			int lower = 0, upper = 0;
			for(int j = 0; j < n; ++j){
				lower += abs(len - inputs[j][i].second);
				upper += abs(len + 1 - inputs[j][i].second);
			}
			answer += min(lower, upper);
		}
		cout << answer << endl;
	}
	return 0;
}

