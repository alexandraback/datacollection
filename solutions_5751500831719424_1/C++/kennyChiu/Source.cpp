#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int T, N;
	int i,j,k;

	cin >> T;

	for (i=1;i<=T;i++){
		cin >> N;
		string input;
		vector<string> all_strings;
		for (j=0;j<N;j++){
			cin >> input;
			all_strings.push_back(input);
		}

		vector<vector<int> > all_chain_size;
		vector<char> chain;
		vector<int> chain_size;
		char first = all_strings[0][0];
		int s = 1;

		chain.push_back(first);
		for (j=1;j<all_strings[0].size();j++){
			if (all_strings[0][j] != first){
				chain_size.push_back(s);
				first = all_strings[0][j];
				s = 1;
				chain.push_back(first);
			}else{
				s++;
			}
		}
		chain_size.push_back(s);

		all_chain_size.push_back(chain_size);

		//cout << chain_size.size() << " " << chain.size() << endl;

		bool possible = true;
		for (j=1 ; j < all_strings.size(); j++){
			int s = 0;
			int chain_index = 0;

			if (all_strings[j][0] != chain[0]){
				possible = false;
				break;
			}else{
				s = 1;
			}
			vector<int> chain_size_2;
			for (k=1;k< all_strings[j].size() && possible; k++){
				if (all_strings[j][k] != chain[chain_index]){
					if (chain_index + 1 < chain.size() && all_strings[j][k] == chain[chain_index + 1]){
						chain_index++;
						chain_size_2.push_back(s);
						s = 1;
					}else{
						possible = false;
					}
				}else{
					s++;
				}
			}
			if (chain_index + 1 == chain.size() && all_strings[j][k-1] == chain[chain_index]){
				chain_size_2.push_back(s);
			}else{
				possible = false;
			}
			all_chain_size.push_back(chain_size_2);
		}

		if (possible){
			int total = 0;
			for (j=0;j< chain.size(); j++){
				vector<int> list;
				for (k=0;k< all_chain_size.size() ;k++){
					list.push_back(all_chain_size[k][j]);
				}
				sort(list.begin(), list.end());
				int median;
				if (list.size() % 2 == 0){
					median = floor((list[(list.size()-2)/2] + list[list.size()/2])/2);
				}else{
					median = list[(list.size()-1)/2];
				}
					
				
				for (k=0;k<all_chain_size.size() ; k++){
					total += abs(all_chain_size[k][j] - median);
				}
			}
			cout << "Case #"<< i << ": " << total << endl;
		}else{
			cout << "Case #" << i << ": Fegla Won" << endl;
		}
		
	}

	return 0;
}