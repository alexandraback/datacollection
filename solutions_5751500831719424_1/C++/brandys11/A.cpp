#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstdio>

using namespace std;

bool check(string a, string b) {
	char last = 'J';
	int pos = 0;
	for(int i=0;i<b.size();i++) {
		if(last != b[i]) {
			if(pos == a.size()) return false;
			last = b[i];
			if(b[i] == a[pos]){
				pos++;
			} 
			else return false;
		}
	}
	return a.size() == pos;
}

void solve(int t) {
	cout << "Case #"<< t<<": ";

	int N, res = 0;
	string ch;
	char last;
	bool ans = true;
	cin >> N;
	vector<string> in(N);
	vector<vector<int> > count(147);

	for(int i=0;i<N;i++){
		cin >> in[i];
		if(i==0) {
			last = 'O';
			ch = "";
			for(int j=0; j<in[i].size(); j++) {
				if(last != in[i][j]) ch += in[i][j];
				last = in[i][j];
			}
		}
		int a = 0, poc =0; 
		last = in[i][0];
		for(int j=0; j<in[i].size(); j++) {
			if(last != in[i][j]){ count[a].push_back(poc); poc =0; a++;  }
			poc++;
			last = in[i][j];
		}	
		count[a].push_back(poc);
		if(!check(ch, in[i])) ans = false;
	} 
	if(ans == false) { cout << "Fegla Won" << endl; return; }

	for(int i=0; i < count.size(); i++) {
		if(count[i].size() == 0) break;
		int best = 474747, ma = 0, akt;
		for(int j = 0; j < count[i].size(); j++) {
			ma = max(ma, count[i][j]);
			//cerr << count[i][j];
		}
		//cerr << endl;
		for(int j=1; j <= ma; j++) {
			akt = 0;
			for(int k=0; k < count[i].size(); k++) {
				akt += abs(count[i][k] - j);
			}
			best = min(akt, best);
		}
		res += best;
	}
	cout << res << endl;
}
int main(void) {
	int T;
	cin >> T;

	for(int t=1;t<=T;t++) solve(t);
}