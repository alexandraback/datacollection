#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int i, j, k, l;
	int cases, row;
	cin >> cases;
	for(i=1; i<=cases; ++i){
		vector<int> possible, allowed;
		cin >> row;
		for(j=1; j<=4; ++j){
			for(k=1; k<=4; ++k){
				cin >> l;
				if(j == row){
					possible.push_back(l);
				}
			}
		}
		cin >> row;
		for(j=1; j<=4; ++j){
			for(k=1; k<=4; ++k){
				cin >> l;
				if(j == row){
					possible.push_back(l);
				}
			}
		}
		sort(possible.begin(), possible.end());
		for(k=0; k<possible.size()-1; ++k){
			if(possible[k] == possible[k+1]){
				allowed.push_back(possible[k]);
			}
		}
		if(allowed.size() == 1){
			cout << "Case #" << i << ": " << allowed[0] << endl;
		}
		else if(allowed.size() == 0){
			cout << "Case #" << i << ": " << "Volunteer cheated!" << endl;
		}
		else{
			cout << "Case #" << i << ": " << "Bad magician!" << endl;
		}
	}



	return 0;
}
