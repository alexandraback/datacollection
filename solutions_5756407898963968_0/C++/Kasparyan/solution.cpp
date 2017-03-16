#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <deque>
#include <map>
#include <cstdio>

using namespace std;

const int inf = 1000*1000*1000;


string solve(){
	int fst,lst;
	cin>>fst;
	int a[4][4];
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cin>>a[i][j];
		}
	}
	cin>>lst;
	int b[4][4];
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cin>>b[i][j];
		}
	}
	int flags[20];
	memset(flags,0,sizeof(flags));
	fst--;
	lst--;
	for(int i=0; i<4; i++){
		flags[a[fst][i]]++;
		flags[b[lst][i]]++;
	}
	int ind = -1;
	int cnt = 0;
	for(int i=0; i<20; i++){
		if(flags[i]>1){
			ind = i;
			cnt++;
		}
	}
	if(cnt == 0) return "Volunteer cheated!";
	if(cnt > 1) return "Bad magician!";
	return to_string(ind);
}


int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	int T;
	cin>>T;
	for(int i=1; i<=T; i++){
		cout<<"Case #"<<i<<": "<<solve()<<endl;
	}
    return 0;
}