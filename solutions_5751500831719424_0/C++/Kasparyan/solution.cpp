#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <deque>
#include <map>
#include <cstdio>
#include <queue>


using namespace std;

const int inf = 1000*1000*1000;

string strs[113];

void solve(int n){
	vector<int> cnts[113];
	string obr[113];
	for(int i=0; i<n; i++){
		int k=1;
		obr[i] = ""+strs[i][0];
		for(int j=1; j<strs[i].length(); j++){
			if(strs[i][j] != strs[i][j-1]){
				cnts[i].push_back(k);
				k=1;
				obr[i] += strs[i][j];
			}else{
				k++;
			}
		}
		cnts[i].push_back(k);
	}
	for(int i=0; i<n; i++){
		if(obr[0] != obr[i]){
			cout<<"Fegla Won"<<endl;
			return;
		}
	}
	int ans = 0;
	int cnt = cnts[0].size();
	for(int i=0; i<cnt; i++){
		int mn,mx;
		mn = inf;
		mx = -inf;
		for(int j=0; j<n; j++){
			mn = min(mn,cnts[j][i]);
			mx = max(mx,cnts[j][i]);
		}
		int preAns = inf;
		for(int cc = mn; cc<=mx; cc++){
			int shtraf = 0;
			for(int j=0; j<n; j++){
				shtraf += abs(cnts[j][i]-cc);
			}
			preAns = min(preAns,shtraf);
		}
		ans+=preAns;
	}
	cout<<ans<<endl;
}

int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	int t;
	cin>>t;
	for(int i=1; i<=t; i++){
		cout<<"Case #"<<i<<": ";
		int n;
		cin>>n;
		getline(cin,strs[0]);
		for(int j=0; j<n; j++){
			getline(cin,strs[j]);
		}
		solve(n);
	}
    return 0;
}