#include<iostream>
#include<algorithm>
#include<utility>
#include<string>
#include<vector>

using namespace std;

void resuelve( vector < pair <int, int> > v , int n){
	int i;
	while( !v.empty() ){
	//for(int x=0;x<5;x++){
		sort(v.begin(), v.end());
		i=v.back().second;
		if(v.size()>2){
			cout << char(i+65) << " ";
			v.back().first--;
		}
		else{
			while( v.back().first>v.front().first){
				cout << char(i+65) << " ";
				v.back().first--;
			}
			while( v.back().first>0){
				cout << char(i+65) << char(v.front().second+65)  << " ";
				v.back().first--; v.front().first--;
			}
			return;
		}
		if(v.back().first<=0)
			v.pop_back();
	}
}


int main(){
	int t;	
	int n, k;
	
	cin >> t;
	for(int tt=0;tt<t;tt++){
		cin >> n;
		vector < pair <int, int> > v;
		cout << "Case #" << tt+1 << ": ";
		for(int i=0;i<n;i++){
			cin >> k;
			v.push_back( make_pair(k, i) );
		}
		//sort(v.begin(), v.end());
		resuelve(v, n);
		
		cout << endl; 
	}
	return 0;
} 
