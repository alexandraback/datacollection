/**
	Author: Floris Kint
  **/


#include <cstdio>
#include <bitset>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>

using namespace std;
int possible[4];

int main(){
	int T;
	scanf("%d", &T);
	//cin >> T;
	for(int current_case = 1; current_case <= T; ++current_case){
		//read input
		int first_row;
		scanf("%d", &first_row); --first_row;
		for(int i = 0; i < 4; ++i){
			for(int j = 0; j < 4; ++j){
				int t;
				scanf("%d", &t);
				if(i == first_row){
					possible[j]=t;
				}
			}
		}
		int second_row;
		scanf("%d", &second_row); --second_row;
		int good_cards_amount = 0;
		int last_good_card = 0;
		for(int i = 0; i < 4; ++i){
			for(int j = 0; j < 4; ++j){
				int t;
				scanf("%d", &t);
				if(i == second_row){
					for(int k = 0; k < 4; ++k){
						if(t == possible[k]){
							++good_cards_amount;
							last_good_card = t;
						}
					}
				}
			}
		}
		//process






		printf("Case #%d:", current_case);
		//cout << "Case #" << current_case << ":";

		if(good_cards_amount == 1){
			printf(" %d", last_good_card);
		}else if(good_cards_amount > 1){
			printf(" Bad magician!");
		}else{
			printf(" Volunteer cheated!");
		}



		//output answer
		printf("\n");
		//cout << endl;
	}
    return 0;
}
