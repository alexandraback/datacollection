#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	int T;
	cin >> T;
	for (int t=1;t<=T;++t){
		//Read input
		int r1, r2;
		vector<int> card1, card2;
		cin >> r1;
		for (int i=0;i<4;++i){
			for (int j=0;j<4;++j){
				int temp;
				cin >> temp;
				if (i == r1-1) card1.push_back(temp);
			}//for j
		}//for i
		cin >> r2;
		for (int i=0;i<4;++i){
			for (int j=0;j<4;++j){
				int temp;
				cin >> temp;
				if (i == r2-1) card2.push_back(temp);
			}//for j
		}//for i
		
		//Preprocess by sorting
		sort(card1.begin(), card1.end());
		sort(card2.begin(), card2.end());

		//Match card1 and card2
		vector<int> matched;
		int in_matched[17] = {0};
		for (int i=0;i<4;++i){
			for (int j=0;j<4;++j){
				if (card1[i] == card2[j] && !in_matched[card1[i]]) {
					matched.push_back(card1[i]);
					in_matched[card1[i]] = 1;
				}
			}//for j
		}//for i
		
		//Output solution
		cout << "Case #" << t << ": ";
		if (matched.size() == 0)
			cout << "Volunteer cheated!" << endl;
		else if (matched.size() == 1)
			cout << matched[0] << endl;
		else 
			cout << "Bad magician!" << endl;
		
	}//for t
	
	return 0;
}