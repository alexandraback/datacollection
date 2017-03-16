#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

inline int myabs(int x){return x>0? x:-x;}

int n;
string table[111];

vector<vector<int> > vii;

string myunique(string str){
	string ret;
	for(int i=0; i<str.size(); i++){
		if(i==0)
			ret += str[i];
		else{
			if(str[i] != str[i-1])
				ret += str[i];
		}
	}
	return ret;
}

bool parsing(){
	string basis;

	basis = myunique(table[0]);

	vii = vector<vector<int > >(n);

	for(int i=0; i<n; i++){
		string tmp = myunique(table[i]);

		if(basis != tmp) return false;
		vii[i] = vector<int>(basis.size(), 0);

		int vp = 0, sp = 0;
		while(sp < table[i].size()){
			if(sp == 0)
				vii[i][vp] ++;

			else{
				if(table[i][sp] != table[i][sp-1]){
					vp++;
					vii[i][vp] ++;
				}
				else{
					vii[i][vp] ++;
				}
			}
			sp ++;
		}
	}
	return true;
}
		

int main(){

	freopen("A-large.in", "r", stdin);
	freopen("myout.txt", "w", stdout);

	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++){
		cin >> n;

		for(int i=0; i<n; i++)
			cin >> table[i];

		cout << "Case #" << tc << ": ";

		if(parsing()){
			int ans=0;

			for(int i=0; i<vii[0].size(); i++){
				int now = 222;
				for(int s=1; s<111; s++){
					int nowdiff=0;
					for(int k=0; k<n; k++){
						nowdiff += myabs(s-vii[k][i]);
					}
					now = min(now, nowdiff);
				}
				ans += now;
			}
			cout << ans << endl;
		}
		else cout << "Fegla Won" << endl;
	}
}