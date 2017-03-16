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

#define PI atan2(0,-1)

using namespace std;
#define MAXN 100
#define MAXVAL MAXN*MAXN*MAXN
vector<pair<char, int> > strings[MAXN];
int max_nb[MAXN];
int main(){
	int T;
	scanf("%d", &T);
	//cin >> T;
	for(int current_case = 1; current_case <= T; ++current_case){
		//read input
        int N;
        scanf("%d", &N);
        while(fgetc(stdin) != '\n'){}
        for(int i = 0; i < N; ++i){
            char c;
            strings[i].clear();
            while((c = fgetc(stdin)) != '\n'){
                if(strings[i].size() == 0 || strings[i].back().first != c){
                    strings[i].push_back(make_pair(c, 1));
                }else{
                    strings[i].back().second++;
                }
            }
        }
		//process
        for(int i = 0; i < MAXN; ++i){
            max_nb[i]=0;
        }
        bool good = true;
        for(int i = 0; i < N && good; ++i){
            if(strings[i].size() != strings[0].size()){
                good = false;
                break;
            }
            for(int j = 0; j < strings[i].size(); ++j){
                max_nb[j] = max(max_nb[j], strings[i][j].second);
                if(strings[i][j].first != strings[0][j].first){
                    good = false;
                    break;
                }
            }
        }
        int total_best = 0;
        if(good){
            for(int i = 0; i < strings[0].size(); ++i){
                int current_best = MAXVAL;
                for(int amount = 0; amount <= max_nb[i]; ++amount){
                    int current_penalty = 0;
                    for(int j = 0; j < N; ++j){
                        current_penalty += abs(strings[j][i].second-amount);
                    }
                    current_best = min(current_penalty, current_best);
                }
                total_best += current_best;
            }
        }




		printf("Case #%d:", current_case);
		//cout << "Case #" << current_case << ":";

        if(good){
            printf(" %d", total_best);
        }else{
            printf(" Fegla Won");
        }


		//output answer
		printf("\n");
		//cout << endl;
	}
    return 0;
}
