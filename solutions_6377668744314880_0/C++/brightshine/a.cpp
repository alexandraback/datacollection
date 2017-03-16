#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <sstream>
#include <bitset>
#include <numeric>
#include <climits>
#include <string>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#define maxl 1000000000
using namespace std;

string s[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
string s2[]={"","","double","triple","quadruple","quintuple","sextuple","septuple","octuple","nonuple","decuple"};

void du(const string &digit){
	int i,j,k,l,d;
	for(i=0;i<digit.size();){
		j=i+1;
		while(j<digit.size() && digit[j]==digit[i])++j;
		l=j-i;
		d=digit[i]-'0';
		if(l>10 || l==1)for(k=0;k<l;++k)cout<<" "<<s[d];else {
			cout<<" "<<s2[l]<<" "<<s[d];
		}
		i=j;
	}
}

void solve(){
	string digit,d2;
	int i,now,x;
	cin>>digit;
	cin>>d2;
	for(i=0;i<d2.size();++i)if(d2[i]=='-')d2[i]=' ';
	istringstream sin(d2);
	vector<int> v;
	while(sin>>x)v.push_back(x);
	now=0;
	for(i=0;i<v.size();++i){
		du(digit.substr(now,v[i]));
		now+=v[i];
	}
	cout<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t,i;
	cin>>t;
	for(int i=1;i<=t;++i){
		cout<<"Case #"<<i<<":";
		solve();
	}
	return 0;
}