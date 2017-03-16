#include <cstdio>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
#define INF 2000000000
#define INFLL (1LL<<62)
#define SS ({int x;scanf("%d", &x);x;})
#define SSL ({lint x;scanf("%lld", &x);x;})
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i,m,n) for(int i=(m);i<(n);i++)
#define ull unsigned long long
#define lint long long
#define MX 10000001

vector<string> all;

string itos(int i) {
	stringstream ss;
	string s;		
	ss<<i;
	ss>>s;
	return s;
}

vector<pair<char,int> > encoded (string s) {
	
	int len = s.length();

	int i, j = 0, k;

	vector<pair<char, int> > ans;

	rep(i,len) {
		 
		int rLen = 1;     
		while(i + 1 < len && s[i] == s[i+1]) {
		  rLen++;
		  i++;
		}   
		 
		 ans.push_back(make_pair(s[i], rLen));
 	}
 	return ans;
 }

int getCurrent(vector<int> v) {
	sort(v.begin(), v.end());
	int median, n = v.size();
	if(v.size()%2) 
		median = v[n/2];
	else {
		median = (v[n/2] + v[n/2 - 1])/2;
	}
	int ans = 0;
	rep(i,n) {
		ans = ans + abs(v[i] - median);
	}
	return ans;
}

int solve () {

	vector<vector<pair<char,int> > > final;
	rep(i, all.size()) {
		final.push_back(encoded(all[i]));
	}

	int size = final[0].size();
	rep(i,final.size()) {
		if(final[i].size() != size)
			return -1;
	}
	//Get optimal ans
	int ans = 0;
	rep(j, final[0].size()) {
		vector<int> current;
		current.push_back(final[0][j].second);
		rept(i, 1, final.size()) {
			if(final[i][j].first != final[0][j].first) {
				return -1;
			}
			current.push_back(final[i][j].second);
		}
		int cnum = getCurrent(current);
		ans += cnum;
	}
	
	return ans;
}

int main() {
	
	int t,n;
	t=SS;	
	rept(testCase, 1, t+1) {

		n=SS;
		all.clear();
		rep(i,n){
			string s;
			cin>>s;
			all.push_back(s);
		}

		int ans = solve();

		printf("Case #%d: ",testCase);

		if (ans == -1) {
			cout<<"Fegla Won\n";
		} else {
			cout<<ans<<endl;
		}
	}
	return 0;
}




