#include<bits/stdc++.h>
using namespace std;
int const N = 30;
typedef pair<int,char> pii;
int t, n, T = 1;
pii P[N];
string ans;
void solve(){
	sort(P+1,P+1+n);
	reverse(P+1,P+1+n);
	ans.clear();
	while(P[1].first > P[2].first) ans.push_back(' '), ans.push_back(P[1].second), P[1].first--;
	for(int i = 3; i <= n; i++)
	 while(P[i].first > 0) ans.push_back(' '), ans.push_back(P[i].second), P[i].first--;
 while(P[1].first > 0) ans.push_back(' '), ans.push_back(P[1].second), ans.push_back(P[2].second), P[1].first--;
}
int main(){
	//ifstream cin ("input.a");
	ofstream cout ("output.txt");
	cin >> t;
	while(t--){
		cin >> n;
	 char c = 'A';
	 for(int i = 1; i <= n; i++){
	 	int val;
	 	cin >> val;
	 	P[i] = pii(val,c++);
		}
	 cout << "Case #" << T++ << ":";
	 solve();
	 cout << ans << '\n';
	}
}
