//In the Name of Allah
#include <iostream>
#include <string>
#include <vector>
#include <set>
//#include <map>
//#include <algorithm>
using namespace std;

const double eps = 1e-12;
typedef long long ll;
typedef pair<int, int> pii;
#define For(i, a, b) for (int i = (a); i < (b); i++)
#define debug(x) { cerr << #x << " = _" << (x) << "_" << endl; }

string key(string s){
	string ret = "";
	ret += s[0];
	for(int i=1; i<s.length();i++)
		if(s[i] != s[i-1])
			ret += s[i];
	return ret;
}

vector <int> v;
set <int> s;		
int cal(int x){
	int s = 0;
	for(int i=0; i<v.size(); i++)
		s += abs(x-v[i]);
	return s;
}
int cal(){
	int mn = 1000000;
	for(set<int>::iterator it = s.begin(); it!=s.end(); it++){
		int x = cal(*it);
		if(x < mn) mn = x;
	}
	return mn;
}

int main(){
	//*
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	//*/

	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++){
		int n;
		cin >> n;
		string str[200];
		For(i, 0, n) cin >> str[i];
		string key1 = key(str[0]);

		bool pos = true;
		For(i, 1, n){
			if(key(str[i]) != key1){
				pos = false;
				break;
			}
		}
		int ans = 0;
		if(pos){
			while(str[0].length() > 0){
				v.clear();
				s.clear();
				const char ch = str[0][0];
				for(int i=0; i<n; i++){
					int cnt = 0, j = 0;
					for(; j<str[i].length(); j++)
						if(str[i][j] != ch) break;
					if(j == 0){ cout << "############ ERror!!1\n"; while(1); }
					str[i] = str[i].substr(j);
					v.push_back(j);
					s.insert(j);
				}
				ans += cal();
			}
		}

		cout << "Case #" << tc << ": ";
		if(!pos) cout << "Fegla Won\n";
		else cout << ans << endl;
	}
}
/*
5
2
mmaw
maw
2
gcj
cj
3
aaabbb
ab
aabb
2
abc
abc
3
aabc
abbc
abcc

*/