#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

void docase(){
	int N;
	cin >> N;
	vector<string >  vec(N);
	vector<vector<int> > sequences(N);
	for(int i = 0; i<N; i++){
		cin >>vec[i];
	}
	char curr= 'A';
	sequences[0].push_back(1);
	string ret; 
	for(int i=0; i<vec[0].size(); i++){
		if(curr != vec[0][i]){ 
			sequences[0].push_back(1);
			curr = vec[0][i];
			ret+= curr;
		}
		else{
			sequences[0][sequences[0].size()-1]++;
		}	
	}
	
	for(int i=1; i<N; i++){
		curr= 'A';
		int where =0;	
		sequences[i].push_back(1);
		for(int j=0; j<vec[i].size(); j++){
			if(curr != vec[i][j]){ 
				curr = vec[i][j];
				if(where >= ret.size() || ret[where++] != curr){cout <<"Fegla Won"<<endl; return;}
				sequences[i].push_back(1);
			}
			else{
				sequences[i][sequences[i].size()-1]++;
			}
		}	
		if(where != ret.size()){cout <<"Fegla Won"<<endl; return;}
	}
	int moves =0;
	for(int i =0; i<sequences[0].size(); i++){
		vector<int> v;
		for(int j =0; j < N ;j++)
			v.push_back(sequences[j][i]);
		int best =1000000000;
		for (int j=0; j<v.size(); j++){
			int t =0;
			for(int k=0; k<v.size(); k++)
				t+= abs(v[j]-v[k]);
			if (t < best) best =t;
		
		}
		moves += best;
	}
	cout << moves <<endl;
	
}



int main()
{
	int testcases;
	cin >> testcases;
	for(int i=0; i<testcases; i++){
		cout <<"Case #"<<i+1<<": ";
		docase();
	}
	return 0;
}
