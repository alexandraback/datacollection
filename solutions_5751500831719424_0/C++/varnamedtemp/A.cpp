#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cmath>
#include <queue>
#include <assert.h>
#include <cstdlib>

using namespace std;

typedef long long ll;

int N;
string s[105], news[105];
vector<int> cnt[105];
int main() {
	freopen("A-small-attempt1.in.txt", "r", stdin);
	//freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin>>T;
	for(int t = 1;t<=T;t++) {
		cin>>N;
		for(int i = 0;i<N;i++) {
			cin>>s[i];
			cnt[i].clear();
		}
		for(int i = 0;i<N;i++) {
			int cntChar = 1;
			news[i] = s[i].substr(0, 1);
			for(int j = 1;j<s[i].size();j++) {
				if(s[i][j] != s[i][j - 1]) {
					news[i] += s[i].substr(j, 1);
					cnt[i].push_back(cntChar);
					cntChar = 1;
				} 
				else {
					cntChar++;
				}
			}
			cnt[i].push_back(cntChar);
			//for(int j = 0;j<cnt[i].size();j++)
			//	cout<<cnt[i][j]<<" ";
			//cout<<endl;
		}

		bool ok = true;
		for(int i = 0;i<N;i++) {
			for(int j = 0;j<N;j++) {
				if(news[i] != news[j])
					ok = false;
			}
		}

		if(!ok) {
			printf("Case #%d: Fegla Won\n", t);
			continue;
		}
		
		int res = 0;
		for(int i = 0;i<news[0].size();i++) {
			vector<int> temp;
			for(int j = 0;j<N;j++) {
				temp.push_back(cnt[j][i]);
			}
			sort(temp.begin(), temp.end());
			int med = temp[temp.size() / 2];
			for(int j = 0;j<N;j++) {
				res += abs(med - temp[j]);
			}
		}
		printf("Case #%d: %d\n", t, res);
	}
    return 0;
}
