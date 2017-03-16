#define Federico using
#define Javier namespace
#define Pousa std;
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>


Federico Javier Pousa

vector< pair<char,int> > armarSign(string S){
	vector<pair<char,int> > vec;
	char cAct = S[0];
	int rAct = 1;
	
	for(int i=1;i<(int)S.size();i++){
		if(S[i]==cAct){
			rAct++;
		}else{
			vec.push_back(pair<char,int>(cAct,rAct));
			rAct = 1;
			cAct = S[i];
		}
	}
	vec.push_back(pair<char,int>(cAct,rAct));
	//~ cerr << "A ver " << S << endl;
	//~ for(int i=0;i<(int)vec.size();i++){
		//~ cerr << vec[i].first << " " << vec[i].second << endl;
	//~ }
	
	return vec;
}

int main(){
	int T, N;
	string aux;
	vector<string> Ss;
	cin >> T;
	for(int caso=1;caso<=T;caso++){
		Ss.clear();
		cin >> N;
		vector<vector< pair<char,int > > >  sign;
		for(int i=0;i<N;i++){
			cin >> aux;
			Ss.push_back(aux);
			sign.push_back(armarSign(aux));
		}
		bool sirve = true;
		int mini = -1;
		
		for(int i=1;sirve&&i<N;i++){
			if(sign[0].size()!=sign[i].size()){
				sirve = false;
				//~ cerr << "Entro: " << i << endl;
			}
			for(int j=0;sirve&&j<(int)sign[0].size();j++){
				if(sign[0][j].first!=sign[i][j].first){
					sirve = false;
					//~ cerr << "Entro 2: " << i << " " << j << endl;
				}
			}
		}
		
		if(sirve){
			mini = 0;
			for(int a=0;a<(int)sign[0].size();a++){
				vector<int> vec;
				int auxi = 0;
				for(int i=0;i<N;i++){
					vec.push_back(sign[i][a].second);
				}
				sort(vec.begin(),vec.end());
				
				//~ cerr << "A ver: " << a << endl;
				//~ for(int i=0;i<(int)vec.size();i++){
					//~ cerr << vec[i] << endl;
				//~ }
				
				int mediana = vec[vec.size()/2]; 
				for(int i=0;i<(int)vec.size();i++){
					auxi += abs(vec[i]-mediana);
				}
				
				
				mini += auxi;
			}
		}
		
		cout << "Case #" << caso << ": ";
		if(sirve){
			cout << mini << endl;
		}else{
			cout << "Fegla Won" << endl;
		}
		
	}
	return 0;
}
