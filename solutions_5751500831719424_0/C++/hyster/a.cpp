#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> vect(string s) {
	vector<int> l; 
	int lkm = 1;
	for(int i=1;i<s.length();i++){
		if (s.at(i) == s.at(i-1)) lkm++;
		else {
			l.push_back(lkm);
			lkm=1;
		}
	}
	l.push_back(lkm);
	return l;
}

int abs(int a) {
	if (a<0) return -a;
	return a;
}

string simplify(string a) {
	string t=a.substr(0,1);
	char c = a[0];
	for(int i=1;i<a.length();i++){
		if (a[i] != t[t.size()-1]) {
			t+= a.substr(i,1); 
		}
	}
	return t;
}
int erot(vector<int> v) {
	int vrt = v[(v.size()-1)/2];
	int t = 0;
	for(int i=0;i<v.size();i++) {
		t+= abs(v[i]-vrt);
	}
	return t;
}

void solve(){
	int a;
	vector<string> v;
	cin>>a;
	for(int i=0;i<a;i++) {
		string s;
		cin>>s;
		v.push_back(s);
	}
	string k =simplify(v[0]);
	for(int i=1;i<v.size();i++) {
		if (simplify(v[i]).compare(k) != 0) { 
			cout<<"Fegla Won"<<endl;
			return;
		}
	}
	vector< vector< int > > t;
	for(int i=0;i<v.size();i++) {
		vector<int> ta = vect(v[i]);
		for(int j=0;j<ta.size();j++) {
			if(i==0) {
				vector<int> tj;
				tj.push_back(ta[j]);
				t.push_back(tj);
			}
			else {
				t[j].push_back(ta[j]);
			}
		}
	}
	for(int i=0;i<t.size();i++) {
		vector<int> ti = t[i];
		sort(ti.begin(),ti.end());
		t[i] = ti;
	}
	int lkm=0;
	for(int i=0;i<t.size();i++) {
		lkm += erot(t[i]);
	}
	cout<<lkm<<endl;
}

int main() {
	int a;
	cin>>a;
	for(int i=0;i<a;i++) {
		cout<<"Case #"<<(i+1)<<": ";
		solve();
	}
}
