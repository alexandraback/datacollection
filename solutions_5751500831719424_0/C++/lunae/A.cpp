#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
string reduced(string str) {
	string answer;
	for (int i=0;i<(int)str.size();i++) {
		if (i==0 || str[i]!=str[i-1]) answer+=str[i];
	}
	return answer;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int tc=1; tc<=T; tc++) {
		int n;
		scanf("%d",&n);
		vector<string> words (n);
		for (int i=0;i<n;i++) cin >> words[i];
		bool ok=true;
		string red = reduced(words[0]);
		for (int i=0;i<n;i++) if (reduced(words[i]) != red) {
			ok=false;
			break;
		}
		if (ok) {
			int answer=0;
			vector<vector<int> > numbers ((int)red.size());
			for (int i=0;i<n;i++) {
				string s = words[i];
				int cnt=0;
				int which=0;
				for (int idx=0;idx<(int)s.size();idx++) {
					cnt++;
					if (idx==(int)s.size()-1 || s[idx+1]!=s[idx]) {
						numbers[which].push_back(cnt);
						cnt=0;
						which++;
					}
				}
			}
			for (int i=0;i<(int)red.size();i++) {
				vector<int> v = numbers[i];
				sort(v.begin(),v.end());
				for (int i=0;i<n;i++) answer += abs(v[i] - v[n/2]);
			}
			printf("Case #%d: %d\n",tc,answer);
		} else {
			printf("Case #%d: Fegla Won\n",tc);
		}
	}
}
