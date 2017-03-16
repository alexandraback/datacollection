#include <cstdio>
#include <sstream>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
//typedef pair<string, vector<int> > pair_s_vi;
using namespace std;
int T, N;
vector<string> vs;
pair<string, vector<int> > stat(string s){
	string ret;
	vector<int> v;
	int cnt = 1;
	int len = s.length();
	int id = 0;
	while(id < len){
		ret.push_back(s[id]);
		int next = id + 1;
		while(next < len && s[next] == s[id]){
			next++;
			cnt++;
		}
		v.push_back(cnt);
		cnt = 1;
		id = next;
	}
	return pair<string, vector<int> >(ret, v);
}
string int2str(int x){
	stringstream ss;
	ss << x;
	return ss.str();
}
string solve(){
	//string s1 = vs[0], s2 = vs[1];
	//int i1 = 0, i2 = 0;
	pair<string, vector<int> > p1 = stat(vs[0]);
	pair<string, vector<int> > p2 = stat(vs[1]);
	if(p1.first != p2.first){
		return "Fegla Won";
	}
	vector<int> v1 = p1.second;
	vector<int> v2 = p2.second;
	int cnt = 0;
	for(unsigned i = 0; i < v1.size(); i++){
		if(v1[i] > v2[i]){
			cnt += v1[i] - v2[i];
		} else {
			cnt += v2[i] - v1[i];
		}
	}
	return int2str(cnt);//c++11
}
int main(int argc, const char *argv[])
{
	string s;
	cin >> T;
	for (int te = 1; te <= T; te++) {
		//scanf("%d", &N);
		vs.clear();
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> s;
			vs.push_back(s);
		}
		string ret = solve();
		printf("Case #%d: %s\n", te, ret.c_str());
	}
	return 0;
}
