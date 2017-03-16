#include <iostream>
#include <vector>
using namespace std;

void problem(){
	vector<int> cand[256];
	int p[17] = {};
	int a, b, c;
	cin >> a;
	for(int i = 0; i < 16; ++i){
		cin >> c;
		p[c] = i / 4;
	}
	cin >> b;
	for(int i = 0; i < 16; ++i){
		cin >> c;
		cand[p[c] << 4 | (i / 4)].push_back(c);
	}
	int d = (a - 1) << 4 | (b - 1);
	if(cand[d].empty()){
		cout << "Volunteer cheated!";
	}
	else if(cand[d].size() == 1){
		cout << cand[d][0];
	}
	else{
		cout << "Bad magician!";
	}
}


int main(){
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i){
		cout << "Case #" << i << ": ";
		problem();
		cout << endl;
	}
}
