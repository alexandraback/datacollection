#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int t, h1, n;
string s;

int main(){
	scanf("%d", &t);
	for(int cc = 1 ; cc <= t ; cc ++){
		scanf("%d", &n);
		getline(cin, s);
		string ss = "";
		vector<string> v;
		bool ok = true;
		int pp;
		for(h1 = 0 ; h1 < n ; h1 ++){
			getline(cin, s);
			v.push_back(s);
			pp = unique(s.begin(), s.end()) - s.begin();
			if(h1 == 0)
				ss = s.substr(0, pp);
			else if( ss != s.substr(0, pp) )
				ok = false;
		}
		printf("Case #%d: ", cc);
		if(!ok){
			cout<<"Fegla Won"<<endl;
		}
		else{
			int ans = 0;
			//cout<<ss<<endl;
			for(int i = ss.size()-1 ; i >= 0 ; i --){
				vector<int> vv;
				for(int j = 0 ; j < v.size() ; j ++){
					int cnt = 0;
					while(v[j].size() && v[j].back() == ss[i]){
						cnt ++;
						v[j].pop_back();
					}
					vv.push_back(cnt);
				}
				sort(vv.begin(), vv.end());
				int mid = vv[vv.size()/2];
				for(int j = 0 ; j < vv.size() ; j ++)
					ans += abs(mid - vv[j]);
			}
			cout<<ans<<endl;
		}
	}
}
