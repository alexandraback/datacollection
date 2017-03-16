#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main(){
	int cases;
	cin >> cases;
	for(int c=0;c<cases;c++){
		int answer1 = 0;
		cin >> answer1;
		vector<set<int> > vs;
		for(int i=0;i<4;i++){
			vs.push_back(set<int>());
			for(int j=0;j<4;j++){
				int temp;
				cin >> temp;
				vs[i].insert(temp);
			}
		}
		int answer2 = 0;
		cin >> answer2;
		vector<set<int> > vs2;
		for(int i=0;i<4;i++){
			vs2.push_back(set<int>());
			for(int j=0;j<4;j++){
				int temp;
				cin >> temp;
				vs2[i].insert(temp);
			}
		}
		vector<int> diff(10);
		vector<int>::iterator it = set_intersection(vs[answer1-1].begin(), vs[answer1-1].end(),vs2[answer2-1].begin(), vs2[answer2-1].end(), diff.begin());
		diff.resize(it-diff.begin());
		if(diff.size() == 1){
			printf("Case #%d: %d\n", c+1, *diff.begin());
		}
		else if(diff.size() == 0){
			printf("Case #%d: Volunteer cheated!\n", c+1);
		}
		else{
			printf("Case #%d: Bad magician!\n", c+1);
		}
		
	}
}