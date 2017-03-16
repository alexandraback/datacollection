#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <map>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <deque>

using namespace std;
typedef long long lint;

int main() {
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		int n;
		cin>>n;
		vector<pair<int,char> > a;
		for(char c='A';c<'A'+n;c++){
			int count;
			cin>>count;
			a.push_back(make_pair(count,c));
		}
		sort(a.begin(),a.end());
		cout<<"Case #"<<(i+1)<<": ";
		if(a.size()>=2){
			vector<char> evacuate;
			if(a[a.size()-1].first>a[a.size()-2].first){
				evacuate.insert(evacuate.end(),a[a.size()-1].first-a[a.size()-2].first,a[a.size()-1].second);
				a[a.size()-1].first=a[a.size()-2].first;
			}
			for(int j=0;j<a.size()-2;j++){
				evacuate.insert(evacuate.end(),a[j].first,a[j].second);
				a[j].first=0;
			}
			for(int j=0;j<evacuate.size();j+=2){
				cout<<evacuate[j];
				if(j+1<evacuate.size())
				cout<<evacuate[j+1];
				cout<<" ";
			}
			for(int j=0;j<a[a.size()-1].first;j++){
				cout<<a[a.size()-1].second<<a[a.size()-2].second<<" ";
			}
		}else{
			vector<char> evacuate;
			evacuate.insert(evacuate.end(),a[0].first,a[0].second);
			for(int j=0;j<a.size()-2;j++){
				evacuate.insert(evacuate.end(),a[j].first,a[j].second);
				a[j].first=0;
			}
			for(int j=0;j<evacuate.size();j+=2)
				cout<<evacuate[j]<<evacuate[j+1]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
