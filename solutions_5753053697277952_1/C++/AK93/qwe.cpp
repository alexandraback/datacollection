#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;

void gen(){
	freopen("testcase.txt", "w", stdout);
	exit(0);
}

vector<string> solve(vector<int> arr){
	vector<string> res;
	int n = arr.size();
	
	set<pair<int, int> > s;
	for(int i=0; i<arr.size(); i++){
		if(arr[i] != 0){
			s.insert(make_pair(-arr[i], i));
		}
	}

	if(s.size() == 2){
		pair<int, int> cur1, cur2;
		cur1 = *s.begin();
		s.erase(s.begin());
		cur2 = *s.begin();
		int cnt = -cur1.first;
		char ch1 = cur1.second + 'A';
		char ch2 = cur2.second + 'A';
		string str;
		str += ch1;
		str += ch2;
		for(int i=0; i<cnt; i++){
			res.push_back(str);
		}
		return res;
	}

	while(1){
		pair<int, int> cur = *s.begin();
		int cnt = -cur.first;
		int ind = cur.second;
		if(cnt == 1){
			break;
		}
		s.erase(s.begin());
		char ch = ind + 'A';
		string str(1, ch);
		res.push_back(str);

		cnt--;
		s.insert(make_pair(-cnt, ind));
	}

	vector<int> cur;
	for(auto it = s.begin(); it != s.end(); it++){
		int ind = it->second;
		cur.push_back(ind);
	}

	if(cur.size() % 2 == 1){
		int ind = cur[cur.size() - 1];
		char ch = ind + 'A';
		string str(1, ch);
		res.push_back(str);
		cur.pop_back();
	}

	for(int i=0; i<cur.size(); i += 2){
		char ch1 = cur[i] + 'A';
		char ch2 = cur[i + 1] + 'A';
		string str;
		str += ch1;
		str += ch2;
		res.push_back(str);
	}

	return res;
}

int main(){

#ifdef _CONSOLE
	freopen("A-large.in", "r", stdin);
	//freopen("testcase.txt", "r", stdin);
	//freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int countTest;
	cin>>countTest;	
	for(int test = 1; test <= countTest; test++){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		vector<string> res = solve(arr);

		printf("Case #%d: ", test);
		for(int i=0; i<res.size(); i++){
			cout<<res[i]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
}

