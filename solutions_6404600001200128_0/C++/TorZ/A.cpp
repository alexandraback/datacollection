#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int OneWay(const vector<int>& vec){
	int sum = 0;
	for (int i = 1; i < vec.size(); i++){
		if (vec[i] < vec[i-1]){
			sum += vec[i-1] - vec[i];
		}
	}
	return sum;
}

int secondWay(const vector<int>& vec){
	int sum = 0;
	int maxgap = 0;
	for (int i = 1; i< vec.size(); i++){
		if (vec[i] < vec[i-1]){
			if ((vec[i-1] - vec[i]) > maxgap){
				maxgap = (vec[i-1] - vec[i]);
			}
		}
	}
	if (maxgap == 0){
		return 0;
	}
	for (int i = 0; i+1 < vec.size(); i++){
		sum += vec[i] < maxgap ? vec[i] : maxgap;
	}
	return sum;
}
int main(int argc, char **argv)
{
	freopen("A.in", "r", stdin);
	freopen("A1.out", "w", stdout);
	int vcnt;	cin >> vcnt;
	for (int i = 1; i <= vcnt; i++){
		int nNum ;
		scanf("%d",&nNum);
		vector<int> vlist;
		for (int j = 0; j < nNum; j++){
			int tmp;
			scanf("%d",&tmp);
			vlist.push_back(tmp);
		}
		int first =  OneWay(vlist);
		int second = secondWay(vlist);
		printf("Case #%d: %d %d\n",i,first, second); 
	}
	return 0;
}
