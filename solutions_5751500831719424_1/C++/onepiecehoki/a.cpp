#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<queue>

using namespace std;

int getRepetition(string s, string cs, vector<vector<int> > &rep){
	int pos = 0;
	for (int i=0;i<cs.size();++i){
		int num_rep = 0;
		char cur_ch = cs[i];
		while(s[pos] == cur_ch){
			pos++;
			num_rep++;
		}
		if (num_rep == 0) return 0;
		else rep[i].push_back(num_rep);
	}
	if (pos != s.size()) return 0;
	return 1;
}


int main(){
	int T;
	cin >> T;
	for (int t=1;t<=T;++t){
		int N;
		cin >> N;
		vector<string> vstr;
		for (int i=0;i<N;++i){
			string stemp;
			cin >> stemp;
			vstr.push_back(stemp);
		}
		
		//Get compressed string
		string comp_str = "";
		for (int i=0;i<vstr[0].size();++i){
			int cur_size = comp_str.size();
			if (cur_size == 0) comp_str += vstr[0][0];
			else if (comp_str[cur_size-1] == vstr[0][i]) continue;
			else comp_str += vstr[0][i];
		}
		
		//Count the repetition on each character
		vector <vector<int> > repetition(comp_str.size());
		int possible = 1;
		for (int i=0;i<N;++i){
			possible = getRepetition(vstr[i], comp_str, repetition);
			if (possible == 0) break;
		}
		
		//Count the result (the difference to the median)
		int result  = 0;
		if (possible == 1){
		//Try all possible end
			for (int i=0;i<repetition.size();++i){
				sort(repetition[i].begin(), repetition[i].end());
			}
			for (int i=0;i<repetition.size();++i){
				int min_add = 1000000000;
				for (int num=1;num<=100;++num){
					int cur_add = 0;
					for (int j=0;j<repetition[i].size();++j){
						cur_add += abs(repetition[i][j] - num);
					}
					if (cur_add < min_add) min_add = cur_add;
				}
				result += min_add;
			}
			/*
			for (int i=0;i<repetition.size();++i){
				int mid = repetition[i].size()/2;
				for (int j=0;j<repetition[i].size();++j){
					result += abs(repetition[i][j] - repetition[i][mid]);
					//cout << "result: " << result << endl;
				}
			}
			*/
		}
		
		
		cout << "Case #" << t << ": ";
		//COUT RESULT HERE
		if (possible == 0) cout << "Fegla Won";
		else cout << result;
		
		cout << endl;
	}
	return 0;

}