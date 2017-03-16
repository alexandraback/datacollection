#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <cstdlib>
using namespace std;




int main(){
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	for(int i=0;i<T;++i){

		int N;
		cin>>N;
		bool win=true;
		vector<string> v;
		for(int j=0;j<N;++j){
			string s;
			cin>>s;
			v.push_back(s);
		}

		int cnt=0;


		while(!(v[0].empty()))//albol jakis inny warunek
		{
			char c=v[0][0];
			vector<int> t;

			for(int k=0;k<N;++k){
				int cn=0,l=0;
				while(!( v[k].empty()) && c==v[k][l]){++cn; v[k].erase(v[k].begin());}
				if(!cn) win=false;
				t.push_back(cn);
			}
			sort(t.begin(),t.end());
			//cout<<"wek t "; for(auto p:t) cout<<p<<","<<endl;
			int min_=1000000000;
			for(int k=*t.begin();k<=*(t.end()-1);++k)
		{
				int sum=0;
				for(auto val:t){
					sum+=abs(k-val);
				}
				if(sum<min_) min_=sum;
		}
//cout<<"dodaje"<<min_;
		cnt+=min_;
	}
for(auto st:v) if(!st.empty()) win=false;
if(win)
cout<<"Case #"<<i+1<<": "<<cnt<<endl;
else
	cout<<"Case #"<<i+1<<": Fegla Won"<<endl;
	}
	return 0;
}
