#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main (){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int cs=1;cs<=t;++cs){
		vector<pair<int,char>>v;
		int n;
		cin>>n;
		string s="";
		for(int i=0;i<n;++i){
			pair <int,char> tmp;
			cin>>tmp.first;
			tmp.second='A'+i;
			v.push_back(tmp);
		}
		sort(v.begin(),v.end());
		for(int i=0;i<n/2;++i){
			swap(v[i],v[n-i-1]);
		}
		while(v[0].first>v[1].first){
			if(v[0].first-v[1].first>1){
				s+=' ';
				s+=v[0].second;
				s+=v[0].second;
				v[0].first-=2;
			}else{
				s+=' ';
				s+=v[0].second;
				--v[0].first;
			}
		}
		for(int i=2;i<n;++i){
			while(v[i].first>0){
				if(v[i].first>1){
					s+=' ';
					s+=v[i].second;
					s+=v[i].second;
					v[i].first-=2;
				}else{
					s+=' ';
					s+=v[i].second;
					--v[i].first;
				}
			}
		}
		while(v[0].first>0){
			s+=' ';
			s+=v[0].second;
			s+=v[1].second;
			--v[0].first;
			--v[1].first;
		}
		cout<<"Case #"<<cs<<":"<<s<<endl;
	}
	return 0;
}