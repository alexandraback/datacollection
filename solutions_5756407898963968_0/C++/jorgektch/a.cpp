/************************************
Problem: Problem A. Tic-Tac-Toe-Tomek
Author: Jorge Ktch
Language: C++
************************************/
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
vector<int> intersection(vector<int> &v1, vector<int> &v2){
	vector<int> v3;
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));
	return v3;
}
int main(){
	vector<int> v1,v2,v3;
	int t,f,aux;
	int i,j,k,r;
	scanf("%d",&t);
	for(i=0;i<t;i++){	
		scanf("%d",&f);
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				scanf("%d",&aux);
				if(j+1==f){
					v1.push_back(aux);
				}
			}
		}
		scanf("%d",&f);
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				scanf("%d",&aux);
				if(j+1==f){
					v2.push_back(aux);
				}
			}
		}
		v3=intersection(v1,v2);	
		if(v3.size()==1){
			printf("Case #%d: %d",i+1,v3[0]);
		}else{
			if(v3.size()==0){
				printf("Case #%d: Volunteer cheated!",i+1);
			}else{
				printf("Case #%d: Bad magician!",i+1);
			}
		}
		v1.clear();
		v2.clear();
		v3.clear();
		if(i!=t-1){
			printf("\n");
		}
	}
	return 0;
}
