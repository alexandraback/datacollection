#include<iostream>
#include<cstdio>
#include<string>
#include<vector>

using namespace std;

int main(){
	freopen("in.txt", "r", stdin);	
	int T; cin >> T;
	for(int tc = 1; tc <= T; tc++){
		vector<int> counts[110];	
		int N; cin >> N;
		vector<pair<char, int> > vec[110];
		string s;
		string ss[110];
		int total_size = 0;
		for(int i = 0; i < N; i++){
			cin >> s;	
			total_size += s.size();
			ss[i] = s;
		//	vec.push_back(s);
			int cnt = 1;
			char prev = s[0];
			for(int j = 1; j < s.size(); j++){
				if(prev == s[j]){
					cnt++;
				}else{
					vec[i].push_back(make_pair(prev, cnt));
					prev = s[j];
					cnt = 1;
				}
			}
			vec[i].push_back(make_pair(prev, cnt));
			
		}
		bool fegla = 0;
		for(int i = 0; i < N; i++){
			if(vec[i].size() != vec[0].size()){
				fegla = true; break;
			}
			for(int j = 0; j < vec[i].size(); j++){
				if(vec[i][j].first != vec[0][j].first){
					fegla = true;break;
				}
			}
		}			
		cout << "Case #"<<tc<<": ";					
		if(fegla){
			cout << "Fegla Won" << endl;
		}else{
			int ans = 0;
			for(int i = 0; i < vec[0].size(); i++){
				for(int j = 0; j < N; j++){
					counts[i].push_back(vec[j][i].second);
				}
				sort(counts[i].begin(), counts[i].end());
				for(int j = 0; j < N; j++){
					ans += abs(counts[i][counts[i].size()/2] - counts[i][j]);
				}
			}	
			cout << ans << endl;		
		}
	
//		return 0;
	}
	return 0;
}	
				
						
			
		
