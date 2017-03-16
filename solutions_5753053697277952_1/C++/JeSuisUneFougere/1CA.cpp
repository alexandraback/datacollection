#include<bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ll long long
#define ld long double
using namespace std;

const int MAX = 26;
int n, ncases;
int t[MAX];

string evacuate(){
	int max=0, max2=0;
	vector<int> pos, pos2;
	for(int i=0;i<n;++i)
		if(t[i] > max){
			max = t[i];
			pos.clear();
			pos.pb(i);
		}
		else if(t[i] == max)
			pos.pb(i);
	
	for(int i=0;i<n;++i)
		if(t[i] != max && t[i] > max2){
			max2 = t[i];
			pos2.clear();
			pos2.pb(i);
		}
		else if(t[i] == max2)
			pos2.pb(i);
	
	if(max == 0)
		return "";
		
	int o = pos.size();
		
	if(o==1 && max-max2==2){
		string res = "";
		res.pb(pos[0] + 'A');
		res.pb(pos[0] + 'A');
		t[pos[0]] -= 2;
		return res;
	}
	
	if(o%2==1){
		string res = "";
		res.pb(pos[0] + 'A');
		t[pos[0]]--;
		return res;
	}
	else{
		string res = "";
		res.pb(pos[0] + 'A');
		res.pb(pos[1] + 'A');
		t[pos[0]]--;
		t[pos[1]]--;
		return res;
	}


	return "LOL";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> ncases;
	
	for(int test=1;test<=ncases;++test){
		cin >> n;
		for(int i=0;i<n;++i)
			cin >> t[i];
		string plan = evacuate();
		cout << "Case #" << test << ": ";
		while(plan != ""){
// 			cout << plan << " -> ";
// 			for(int x=0;x<n;++x)
// 				cout << t[x] << " ";
// 			cout << endl;
// 			
			cout << plan << " ";
			plan = evacuate();
		}
		cout << endl;
		
// 		cout << "Case #" << test << ": " << evacuate() << endl;
	}
	return 0;
}