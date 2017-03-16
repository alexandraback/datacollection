#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

#define PB push_back
vector<int> potential;

vector<int> filter(vector<int> current, int a, int b, int c, int d) {
	vector<int> res;
	for(int i=0;i<current.size();i++) 
		if(current[i] == a || current[i] == b || current[i] == c || current[i] == d) {
			res.PB(current[i]);
		}
	return res;
}

vector<int> row[4];

void read_data() {
	for(int i=0;i<4;i++) {
		row[i].clear();
		for(int i2=0;i2<4;i2++) {
			int num;scanf("%d",&num);
			row[i].PB(num);
		}
	}
}

int main() {
	int id=1;int t;scanf("%d",&t);
	while(t--) {
		potential.clear();
		for(int i=1;i<=16;i++) potential.PB(i);
		int r;
		scanf("%d",&r);r--;
		read_data();
		potential = filter(potential,row[r][0],row[r][1],row[r][2],row[r][3]);
		
		scanf("%d",&r);r--;
		read_data();
		potential = filter(potential,row[r][0],row[r][1],row[r][2],row[r][3]);
		
		string res = "";
		if(potential.size()>1) res = "Bad magician!";
		else if(potential.size() == 0) res = "Volunteer cheated!";
		else {
			char tmp[100];
			sprintf(tmp,"%d",potential[0]);
			res = tmp;
		}
		
		printf("Case #%d: %s\n",id++,res.c_str());
	}
	return 0;
}
