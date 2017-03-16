#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i=0; i<t; ++i){
		int n, x;
		vector< pair<int, char> > s;
		cin >> n;
		for(int j=0; j<n; ++j){
			cin >> x;
			s.push_back(pair<int, char>(x, j+'A'));
		}
		sort(s.begin(), s.end());
		vector<char> crke;
		string out="";
		for(int j=n-2; j>=0; --j){
			while(s[j].first<s[j+1].first){
				if(out!="") out+=' ';
				if(crke.empty()){
					out+=s[j+1].second;
					s[j+1].first--;
				}
				else{
					for(int k=0; k<crke.size()-1; ++k){
						out+=crke[k];
						out+=" ";
					}
					out+=crke[crke.size()-1];
					out+=s[j+1].second;
					s[j+1].first--;
				}
			}
			crke.push_back(s[j+1].second);
		}
		crke.push_back(s[0].second);
		for(int j=0; j<s[0].first; ++j){
			if(out!="") out+=" ";
			for(int k=0; k<crke.size()-2; ++k){
				out+=crke[k];
				out+=" ";
			}
			out+=crke[crke.size()-1];
			out+=crke[crke.size()-2];
		}
		cout << "Case #" << i+1 << ": " << out << endl; 
	}
	return 0;
}