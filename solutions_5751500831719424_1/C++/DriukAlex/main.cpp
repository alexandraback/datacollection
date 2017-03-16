#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <iomanip>

using namespace std;

vector<pair<int, char> > mas[100];
string str[100];

void solve(int t) {
	int n;
	cin>>n;
	for (int i=0;i<n;i++) {
		cin>>str[i];
	}
	for (int i=0;i<100;i++)
		mas[i].clear();
	for (int i=0;i<n;i++) {
		int cnt=1;
		for (int j=1;j<str[i].size();j++) {
			if (str[i][j]==str[i][j-1]) {
				cnt++;
			} else {
				mas[i].push_back(make_pair(cnt,str[i][j-1]));
				cnt=1;
			}
		}
		mas[i].push_back(make_pair(cnt,str[i][str[i].size()-1]));
	}
	int sz=mas[0].size();
	for (int i=1;i<n;i++) {
		if (mas[i].size()!=sz) {
			printf("Case #%d: Fegla Won\n",t+1);
			return;
		}
	}
	for (int i=1;i<n;i++) {
		for (int j=0;j<mas[i].size();j++) {
			if (mas[i][j].second != mas[0][j].second) {
				printf("Case #%d: Fegla Won\n",t+1);
				return;
			}
		}
	}
	int res = 0;
	for (int j=0;j<mas[0].size();j++) {
		vector<int> cur;
		for (int i=0;i<n;i++) {
			cur.push_back(mas[i][j].first);
		}
		sort(cur.begin(),cur.end());
		int mini=1000000;
		for (int ret=1;;ret++) {
			int c=0;
			for (int i=0;i<n;i++) {
				c+=abs(ret-cur[i]);
			}
			if (mini > c)
				mini=c;
			else
				break;
		}
		res+=mini;
	}
	printf("Case #%d: %d\n",t+1,res);
}

int main() {

	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int T;
	cin>>T;
	for (int i=0;i<T;i++) {
		solve(i);
	}
	return 0;
}