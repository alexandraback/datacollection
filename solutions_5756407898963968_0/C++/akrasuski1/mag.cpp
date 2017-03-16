/*
 * mag.cpp
 *
 *  Created on: 12 kwi 2014
 *      Author: admin
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int z=0;z<t;z++){
		int a;
		scanf("%d",&a);
		vector<int>row;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				int x;
				scanf("%d",&x);
				if(i==a-1){
					row.push_back(x);
				}
			}
		}
		int b;
		scanf("%d",&b);
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				int x;
				scanf("%d",&x);
				if(i==b-1){
					row.push_back(x);
				}
			}
		}
		sort(row.begin(),row.end());
		vector<int>answers;
		for(int i=0;i<row.size()-1;i++){
			if(row[i]==row[i+1]){
				answers.push_back(row[i]);
			}
		}
		printf("Case #%d: ",z+1);
		if(answers.size()==1){
			printf("%d\n",answers[0]);
		}
		else if(answers.size()==0){
			printf("Volunteer cheated!\n");
		}
		else{
			printf("Bad magician!\n");
		}
	}


}



