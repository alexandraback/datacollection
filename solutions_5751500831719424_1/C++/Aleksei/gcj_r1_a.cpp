#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool all_equal(string c[], int n){
	for(int i=0; i<n-1; i++){
		if(c[i]!=c[i+1]) return false;
	}
	return true;
}

int calc(int cnt[], int n){
	int min_val = *min_element(&cnt[0],&cnt[n]);
	int max_val = *max_element(&cnt[0],&cnt[n]);
	int min_res = 100000000;
	for(int v=min_val; v<=max_val; v++){
		int cur_res = 0;
		for(int i=0; i<n; i++){
			cur_res+=abs(v-cnt[i]);
		}
		min_res = min(min_res,cur_res);
	}
	return min_res;
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int n;
		cin>>n;
		string s[101];
		string c[101];
		for(int i=0; i<n; i++){
			cin>>s[i];
			c[i] = s[i];
			string::iterator it = unique(c[i].begin(),c[i].end());
			int r = it-c[i].begin();
			c[i].resize(r);
		}
		if(!all_equal(c,n)){
			cout<<"Case #"<<testnum+1<<": "<<"Fegla Won"<<endl;
			continue;
		}
		int rez = 0;
		int next_pos[101];
		memset(next_pos,0,sizeof(next_pos));
		int cnt[101];
		memset(cnt,0,sizeof(cnt));
		int total_iter = c[0].size();
		for(int tt=0; tt<total_iter; tt++){
			for(int i=0; i<n; i++){
				int b = next_pos[i];
				int e = b+1;
				int z = s[i].size();
				while(e<z && s[i][b]==s[i][e]) e++;
				cnt[i] = e-b;
				next_pos[i] = e;
			}
			rez+=calc(cnt,n);
		}
		cout<<"Case #"<<testnum+1<<": "<<rez<<endl;
	}
	return 0;
}
