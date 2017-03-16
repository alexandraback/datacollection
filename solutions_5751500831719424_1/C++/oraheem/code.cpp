#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

vector<pair<char, int> > getChar(string s){
	vector<pair<char, int> > ret;
	s += " ";
	int lastchar = '.';
	int charcount = 0;
	for(int i = 0; i < s.size();i++){
		if (s[i] == lastchar) charcount ++;
		else{
			if (lastchar != '.') ret.push_back(make_pair(lastchar, charcount));
			charcount = 1;
			lastchar = s[i];
		}
	}
	return ret;
}

string getWord(vector<pair<char, int> > v){
	string ret = "";
	for(int i = 0; i < v.size();i ++){
		ret += v[i].first;
	}
	return ret;
}

int getMin(vector<int> v){
	int mini = 99999;
	int maxi = -9999;
	for(int i = 0; i < v.size(); i++){
		mini = min(mini, v[i]);
		maxi = max(maxi, v[i]);
	}
	int ret = 9999999;
	for(int i = mini; i <= maxi;i++){
		int total_diff = 0;
		for(int j = 0; j < v.size();j++){
			total_diff += abs(i - v[j]);
		}
		ret = min(ret, total_diff);
	}
	return ret;
}

int main(){
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int t;
	scanf("%d", &t);
	for(int c = 1; c <= t;c++){
		int n;
		scanf("%d", &n);
		vector<pair<char, int> > list[105];
		for(int i = 0; i < n;i++){
			string s;
			cin >> s;
			list[i] = getChar(s);
		}
		bool valid = true;
		for(int i = 0; i < n - 1;i++){
			if (getWord(list[i]) != getWord(list[i + 1])){
				valid = false;
			}
		}

		if (valid == true){
			int sol = 0;
			int size = list[0].size();
			for(int i = 0; i < size;i++){
				vector<int> values;
				for(int j = 0; j < n;j++){
					values.push_back(list[j][i].second);
				}
				sol += getMin(values);
			}
			printf("Case #%d: %d\n",c, sol);
		}
		else printf("Case #%d: Fegla Won\n",c);
	}
	//while(true);
}