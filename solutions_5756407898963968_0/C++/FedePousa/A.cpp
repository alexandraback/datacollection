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

int main(){
	int T, guess, aux, count[30];
	vector<int> res;
	cin >> T;
	for(int caso=1;caso<=T;caso++){
		res.clear();
		memset(count, 0, sizeof count);
		for(int a=0;a<2;a++){
			cin >> guess;
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					cin >> aux;
					if(i+1==guess){
						count[aux]++;
					}
				}
			}
		}
		for(int i=0;i<20;i++){
			if(count[i]==2)res.push_back(i);
		}
		cout << "Case #" << caso << ": ";
		if(res.size()==0){
			cout << "Volunteer cheated!" << endl;
			continue;
		}
		if(res.size()>1){
			cout << "Bad magician!" << endl;
			continue;
		}
		cout << res[0] << endl;
	}
	return 0;
}
